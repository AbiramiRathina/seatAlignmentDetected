#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <FirebaseArduino.h>
#define FIREBASE_AUTH "<auth>" 
#define FIREBASE_HOST "<host>"
#define WIFI_SSID "<ssid>"
#define WIFI_PASSWORD "<password>"

String values,sensor_data;

void setup() 
{ 
  Serial.begin(9600);
  delay(1000);
  Serial.print("Scan start ... ");
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" network(s) found");
  for (int i = 0; i < n; i++)
  {
    Serial.println(WiFi.SSID(i));
  }
  Serial.println();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
       Serial.println("fail");
       delay(500);   
  }  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
}
void loop() 
{
     bool Sr =false;
     while(Serial.available())
    {    
        sensor_data=Serial.readString(); 
        Sr=true;            
    }  
    delay(1000);
    if(Sr==true)
    {  
    
          values=sensor_data;  
          int fristCommaIndex = values.indexOf(',');
          int secondCommaIndex = values.indexOf(fristCommaIndex+1,values.length()); 
          String Chair1 = values.substring(0, fristCommaIndex);
          String Chair2 = values.substring(fristCommaIndex+1, secondCommaIndex); 
         Firebase.setString("Chair1",Chair1);
         delay(10); 
         Firebase.setString("Chair2",Chair2);
         delay(10);   
         delay(1000);  
         if (Firebase.failed()) 
         {  
               return;
         }  
    }   
}
