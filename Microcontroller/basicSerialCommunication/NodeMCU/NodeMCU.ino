//https://www.hackster.io/pawan-kumar3/serial-communication-between-nodemcu-and-arduino-640819

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
 
//ESP Web Server Library to host a web page
#include <ESP8266WebServer.h>

const char* ssid = "Nathan's IPhone";
const char* password = "ninaluskey";

WiFiServer server(80);

//my global variables
int repeater = 0;
String webpageStart = "<!DOCTYPE html> <html> <head> </head> <body>";
String webpageEnd = "</body> </html>";
String webpageMiddle = "";

void setup() {
    Serial.begin(115200);
    delay(10);

    // Connect to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    //Trying to make a static IP, but it's not working... https://circuits4you.com/2018/03/09/esp8266-static-ip-address-arduino-example/
//    IPAddress ip(192,168,1,200);
//    IPAddress gateway(192,168,1,254);
//    IPAddress subnet(255,255,255,0);
//    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    // Start the server
    server.begin();
    Serial.println("Server started");

    // Print the IP address
    Serial.print("Use this URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");

}

void loop() {
  //Serial Stuff:
  if (Serial.available()) {
    String incoming = Serial.readString();
    webpageMiddle += incoming;
  }

  // WIFI Stuff
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
//  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }
  client.flush();
  client.println(webpageStart);
  client.println(webpageMiddle);
  client.println(webpageEnd);

  delay(1);
//  Serial.println("Client disonnected");
//  Serial.println("");

}
