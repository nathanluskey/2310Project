// https://www.pjrc.com/teensy/td_uart.html
//set this to the hardware serial port you wish to use
#define ESPSerial Serial1

//Variables of the pins being read
const int xpin = 21;                  // x-axis of the accelerometer
const int ypin = 22;                  // y-axis
const int zpin = 23;                  // z-axis (only on 3-axis models)

int ax = 0;
int ay = 0;
int az = 0;

int incomingByte = 0;
boolean doStuff = true;
String outString;

void setup() {
  Serial.begin(115200);
  ESPSerial.begin(115200);
  digitalWrite(13, HIGH);
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
  //  Serial.print(millis());
  //  Serial.print(", ");
  // print the sensor values:
  ax = analogRead(xpin);
  ay = analogRead(ypin);
  az = analogRead(zpin);
  outString = "B (" + String(ax) + ", " + String(ay) + ", " + String(az) + ") D ";
  Serial.println(outString);
  if (ESPSerial.available() > 0) {
    //because the serial read is between 0-1023, need a way to label the data
    ESPSerial.print(outString);
    Serial.println(ESPSerial.readString());
    Serial.println("Printing to NodeMCU Succeeded");
  } else {
    Serial.println("Printing to NodeMCU Failed");
  }
  // delay before next reading:
  delay(100);
}
