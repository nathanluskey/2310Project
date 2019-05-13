/*
   https://github.com/nothans/thingspeak-esp-examples/blob/master/examples/A0_to_ThingSpeak.ino
  ESP8266 --> ThingSpeak Channel

  This sketch sends the value of Analog Input (A0) to a ThingSpeak channel
  using the ThingSpeak API (https://www.mathworks.com/help/thingspeak).

  Requirements:

     ESP8266 Wi-Fi Device
     Arduino 1.8.8+ IDE
     Additional Boards URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json
     Library: esp8266 by ESP8266 Community
     Library: ThingSpeak by MathWorks

  ThingSpeak Setup:

     Sign Up for New User Account - https://thingspeak.com/users/sign_up
     Create a new Channel by selecting Channels, My Channels, and then New Channel
     Enable one field
     Enter SECRET_CH_ID in "secrets.h"
     Enter SECRET_WRITE_APIKEY in "secrets.h"
  Setup Wi-Fi:
    Enter SECRET_SSID in "secrets.h"
    Enter SECRET_PASS in "secrets.h"

  Tutorial: http://nothans.com/measure-wi-fi-signal-levels-with-the-esp8266-and-thingspeak

  Created: Feb 3, 2017 by Hans Scharler (http://nothans.com)
*/

#include "ThingSpeak.h"

const long myChannelNumber = 754717;
const char myWriteAPIKey[] = "UL3RL53WB2VSCVPC";
int startTime;

#include <ESP8266WiFi.h>

char ssid[] = "Nathan's IPhone";   // your network SSID (name)
char pass[] = "ninaluskey";   // your network password

//my global variables
int repeats = 0;
double delayTime = 10000;
double rate = 100;
int intValues[12];
makeIntVector(12);

WiFiClient  client;
void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.mode(WIFI_STA);

  ThingSpeak.begin(client);
  startTime = millis();
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
  if (startTime - millis() < delayTime) {
    intValues[repeats] = repeats;
    repeats++;
    delay(delayTime);
  } else {
    // Write value to Field 1 of a ThingSpeak Channel
    int httpCode = ThingSpeak.writeField(myChannelNumber, 1, intValues, myWriteAPIKey);

    if (httpCode == 200) {
      Serial.println("Channel write successful.");
    }
    else {
      Serial.println("Problem writing to channel. HTTP error code " + String(httpCode));
    }
    // reset startTime and intValues
    startTime = millis();
    intValues
  }
}

// some useful functions
public static void makeIntVector(double vectorLength) {
  for (int i = 0; i < vectorLength; i++) {
    intVector[i] = -1;
  }
}

public static String formatter(int vector[]) {
  boolean markerFound = false;
  double i = 0;
  while (!markerFound && i < vector.length) {
    int value = vector[i];
    if (value == -1) {
      markerFound = true;
    }
    else {
      i++;
    }
  }
  String returnVector;
  for (int j = 0; j < i; j++) {
    returnVector += String(vector[j]);
  }
  return returnVector;
}
