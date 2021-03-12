#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[]="ogmHvv3ziwjE_mKxn9NBrxVNVsewijH6";
char ssid[]="OTB";
char pass[]="AAAbbb9292";
BlynkTimer timer;
#define Pump D0
#define LED D4
#define Hum A0
#define ON LOW
#define OFF HIGH
int HumidityValue;
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
     if(pinValue == 1){
      digitalWrite(Pump, ON);
      }else{
      digitalWrite(Pump, OFF);
      }
  }
BLYNK_READ(V2)
{
  Blynk.virtualWrite(V2,analogRead(Hum));
  }
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(Pump,OUTPUT);
  digitalWrite(Pump,OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}
void loop() {
 HumidityValue = analogRead(Hum);
 if (HumidityValue >= 800)
 {
  digitalWrite(Pump, ON);
  delay(5000);
  digitalWrite(Pump, OFF);
  }
  digitalWrite(LED, HIGH);
  delay(100);
  digitalWrite(LED, LOW);
  delay(100);
  Blynk.run();
  timer.run();
}
