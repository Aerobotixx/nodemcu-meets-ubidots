/****************************************
 Getting data from Ubidots to NodeMCU
 Tested by Aerobotix Techsolutions 
 ****************************************/
 
#include "Ubidots.h"

const char* UBIDOTS_TOKEN = "******************";  // Put your Ubidots TOKEN here
const char* WIFI_SSID = "********"; // Put your Wi-Fi SSID here
const char* WIFI_PASS = "********"; // Put your Wi-Fi password here

Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

void setup() 
{
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
 //ubidots.setDebug(true);  // This is only for developers & testers to debug the process
  Serial.println("NodeMCU Meets Ubidots");
  delay(1000);
  Serial.println("Connection Initializing... Please Wait....");
  delay(2000);
}

void loop() 
{
  // assign variables to store data
  float t = ubidots.get("*********", "temperature");//replace****** with the device label
  float h = ubidots.get("*********", "humidity");
  
  // Validate incoming data whether it is error OR actual result
  if (t != ERROR_VALUE) 
  {
    Serial.print("Temperature = ");
    Serial.print(t);
  }

  if (h != ERROR_VALUE) 
  {
    Serial.print("\t\t");    //to create a seperating column
    Serial.print("Humidity = ");
    Serial.println(h);
  }
  delay(5000);
}
