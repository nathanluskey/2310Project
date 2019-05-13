/*
 * NEW CODE BASIS TO WRITE MULTIPLE FIELDS!!! https://github.com/mathworks/thingspeak-arduino/blob/master/examples/ESP8266/WriteMultipleFields/WriteMultipleFields.ino
 * https://github.com/nothans/thingspeak-esp-examples/blob/master/examples/A0_to_ThingSpeak.ino
 ESP8266 --> ThingSpeak Channel
 
 This sketch sends the value of Analog Input (A0) to a ThingSpeak channel
 using the ThingSpeak API (https://www.mathworks.com/help/thingspeak).
 
 Requirements:
 
   * ESP8266 Wi-Fi Device
   * Arduino 1.8.8+ IDE
   * Additional Boards URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json
   * Library: esp8266 by ESP8266 Community
   * Library: ThingSpeak by MathWorks
 
 ThingSpeak Setup:
 
   * Sign Up for New User Account - https://thingspeak.com/users/sign_up
   * Create a new Channel by selecting Channels, My Channels, and then New Channel
   * Enable one field
   * Enter SECRET_CH_ID in "secrets.h"
   * Enter SECRET_WRITE_APIKEY in "secrets.h"
 Setup Wi-Fi:
  * Enter SECRET_SSID in "secrets.h"
  * Enter SECRET_PASS in "secrets.h"
  
 Tutorial: http://nothans.com/measure-wi-fi-signal-levels-with-the-esp8266-and-thingspeak
   
 Created: Feb 3, 2017 by Hans Scharler (http://nothans.com)
*/

#include "ThingSpeak.h"
//#include "secrets.h"

const long myChannelNumber = 735382;
const char myWriteAPIKey[] = "JOSA0BFI2HSTF93N";

#include <ESP8266WiFi.h>

char ssid[] = "Nathan's IPhone";   // your network SSID (name)
char pass[] = "ninaluskey";   // your network password
int keyIndex = 0;            // your network key index number (needed only for WEP)
int repeats = 0;
WiFiClient  client;

void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.mode(WIFI_STA);

  ThingSpeak.begin(client);
}

void loop() {

  // Connect or reconnect to WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }

  // Measure Analog Input (A0)
//  int valueA0 = analogRead(A0);
    int valueA0 = 1 + repeats;
    repeats++;

  // Write value to Field 1 of a ThingSpeak Channel
  int httpCode = ThingSpeak.writeField(myChannelNumber, 1, valueA0, myWriteAPIKey);

  if (httpCode == 200) {
    Serial.println("Channel write successful.");
  }
  else {
    Serial.println("Problem writing to channel. HTTP error code " + String(httpCode));
  }

  // Wait 20 seconds to uodate the channel again
  delay(20000);
}
