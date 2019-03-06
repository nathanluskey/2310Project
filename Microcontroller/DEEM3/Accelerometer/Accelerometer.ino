/*
  ADXL3xx

  Reads an Analog Devices ADXL3xx accelerometer and communicates the
  acceleration to the computer. The pins used are designed to be easily
  compatible with the breakout boards from SparkFun, available from:
  http://www.sparkfun.com/commerce/categories.php?c=80

  The circuit:
  - analog 0: accelerometer self test
  - analog 1: z-axis
  - analog 2: y-axis
  - analog 3: x-axis
  - analog 4: ground
  - analog 5: vcc

  created 2 Jul 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ADXL3xx
*/

// these constants describe the pins. They won't change:
const int xpin = 21;                  // x-axis of the accelerometer
const int ypin = 22;                  // y-axis
const int zpin = 23;                  // z-axis (only on 3-axis models)
//const int killPin = 0;
int incomingByte = 0;
boolean doStuff = false;

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);
  //  pinMode(killPin, INPUT);

}

void loop() {
  //Stop & Start the reading by just pressing the send button on the serial monitor
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


static void readData() {
//  Serial.print(millis());
//  Serial.print(", ");
  // print the sensor values:
  Serial.print(analogRead(xpin));
  // print a tab between values:
  Serial.print(", ");
  Serial.print(analogRead(ypin));
  // print a tab between values:
  Serial.print(", ");
  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
  delay(1);
}
