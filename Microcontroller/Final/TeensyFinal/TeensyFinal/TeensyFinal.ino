// https://www.pjrc.com/teensy/td_uart.html
//set this to the hardware serial port you wish to use
#define ESPSerial Serial1

//Variables of the pins being read
const int xpin = 21;                  // x-axis of the accelerometer
const int ypin = 22;                  // y-axis
const int zpin = 23;                  // z-axis (only on 3-axis models)
const int runPin = 14;
const int fallPin = 13;

double ax = 0;
double ay = 0;
double az = 0;

//know the voltage biases
const double xBias = analogRead(xpin);
const double yBias = analogRead(ypin);
const double zBias = analogRead(zpin);


int incomingByte = 0;
boolean falling = false;
boolean doStuff = false;
String outString;

void setup() {
  Serial.begin(115200);
  ESPSerial.begin(115200);
  pinMode(runPin, INPUT);
  pinMode(fallPin, INPUT);
}

void loop() {
  if (digitalRead(runPin) == 1 && !doStuff) {
    doStuff = true;
  } else if (digitalRead(runPin) == 0 && doStuff) {
    doStuff = false;
    ESPSerial.print("STOPPED<br>");
    Serial.println("STOPPED");
  }
  if (doStuff) {
    readData();
  }
  //  if (Serial.available() > 0) {
  //    // read the incoming byte:
  //    incomingByte = Serial.read();
  //    //Serial.println(incomingByte);
  //    if (doStuff == false) {
  //      doStuff = true;
  //    } else {
  //      doStuff = false;
  //      ESPSerial.print("STOPPED<br>");
  //      Serial.println("STOPPED");
  //    }
  //  }
  //  if (doStuff == true) {
  //    readData();
  //  }
}


//If the IMU is setup, this will change
static void readData() {
  int startTime = millis();
  // print the sensor values:
  ax = (analogRead(xpin) - xBias) / 57;
  ay = (analogRead(ypin) - yBias) / 57;
  az = (analogRead(zpin) - zBias) / 56;
  // print whether falling or not
  //(time,x,y,z,fall?);
  outString = String(millis()) + ", " + String(ax) + ", " + String(ay) + ", " + String(az) + ", " + String(digitalRead(fallPin));
  Serial.println(outString);
  //This takes about 1 second, which is waaaaaaaay too long, so cutting it out is necessary
  ESPSerial.print(outString + "<br>");
  //    Serial.println(ESPSerial.readString());
  //flush to close out everything and not clogg the serial communication
  ESPSerial.flush();
  delay(80 - (millis() - startTime));
}
