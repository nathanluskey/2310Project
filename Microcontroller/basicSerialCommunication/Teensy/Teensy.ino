// https://www.pjrc.com/teensy/td_uart.html
//set this to the hardware serial port you wish to use
#define ESPSerial Serial1

//Variables of the pins being read

void setup() {
  Serial.begin(115200);
  ESPSerial.begin(115200);
  digitalWrite(13,HIGH);
}

void loop() {
  Serial.print("Trying to write...");
    if (ESPSerial.available() > 0) {
      Serial.println("YES!");
      ESPSerial.println("1");
      delay(1000);
      ESPSerial.println("0");
    } else {
      Serial.println("Nope!");
    }
    delay(3000);
}


//If the IMU is setup, this will change
//static void readData() {
//  //  Serial.print(millis());
//  //  Serial.print(", ");
//  // print the sensor values:
//  ax = analogRead(xpin);
//  Serial.print(ax);
//  // print a tab between values:
//  Serial.print(", ");
//  ay = analogRead(ypin);
//  Serial.print(ay);
//  // print a tab between values:
//  Serial.print(", ");
//  az = analogRead(zpin);
//  Serial.println(az);
//  if (ESPSerial.available() > 0) {
//    //because the serial read is between 0-1023, need a way to label the data
//    ESPSerial.println("B"); //B is for beginning
//    ESPSerial.println(ax);
//    ESPSerial.println(ay);
//    ESPSerial.println(az);
//    ESPSerial.println("D"); //D is for done
//    Serial.println("Printing to NodeMCU Succeeded");
//  } else {
//    Serial.println("Printing to NodeMCU Failed");
//  }
//  // delay before next reading:
//  delay(100);
//}
