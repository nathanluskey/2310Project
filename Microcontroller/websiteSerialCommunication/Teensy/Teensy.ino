// https://www.pjrc.com/teensy/td_uart.html
//set this to the hardware serial port you wish to use
#define ESPSerial Serial1

//Variables of the pins being read
const int xpin = 21;                  // x-axis of the accelerometer
const int ypin = 22;                  // y-axis
const int zpin = 23;                  // z-axis (only on 3-axis models)
const int startPin = 14;
const int fallPin = 15;

int ax = 0;
int ay = 0;
int az = 0;

int incomingByte = 0;
boolean doStuff = true;
String outString;
double fallingPin = 15;
double doStuffPin = 17;

void setup() {
  Serial.begin(115200);
  ESPSerial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    //Serial.println(incomingByte);
    if (doStuff == false) {
      doStuff = true;
    } else {
      doStuff = false;
      Serial.println("STOPPED");
    }
  }
  if (doStuff == true) {
    readData();
  }

}


//If the IMU is setup, this will change
static void readData() {
  int startTime = millis();
  // print the sensor values:
  ax = analogRead(xpin);
  ay = analogRead(ypin);
  az = analogRead(zpin);
  outString = "(" + String(ax) + ", " + String(ay) + ", " + String(az) + ", " + millis() + ")<br>";
  Serial.println(outString);
  //This takes about 1 second, which is waaaaaaaay too long, so cutting it out is necessary
  //  ESPSerial.print(outString);
  //  Serial.println(ESPSerial.readString());
  //flush to close out everything and not clogg the serial communication
  ESPSerial.flush();
  delay(80 - (millis() - startTime));
}
