#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPLyRzdoEYC"
#define BLYNK_DEVICE_NAME "ultrasonik"
#define BLYNK_AUTH_TOKEN "YX7PN5gWFxx0s58WmMj9Nimoru3kXEoE"
#define BLYNK_PRINT Serial

#define  trig  12
#define  echo  13

long duration;
int distance;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mii";
char pass[] = "aa123456";

BlynkTimer timer;

void setup(){
  pinMode(trig, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echo, INPUT);   // Sets the echoPin as an Inpu
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  timer.setInterval(1000L, ultrasonik);
}

void loop() {
  Blynk.run();
  timer.run();
}

void ultrasonik(){
  digitalWrite(trig, LOW);   // Makes trigPin low
  delayMicroseconds(2);       // 2 micro second delay
  digitalWrite(trig, HIGH);  // tigPin high
  delayMicroseconds(10);      // trigPin high for 10 micro seconds
  digitalWrite(trig, LOW);   // trigPin low
  duration = pulseIn(echo, HIGH);   //Read echo pin, time in microseconds
  distance = duration * 0.034 / 2;   //Calculating actual/real distance
  Serial.print("Distance = ");        //Output distance on arduino serial monitor
  Serial.println(distance);
  
  Blynk.virtualWrite(V0, distance); 

}
