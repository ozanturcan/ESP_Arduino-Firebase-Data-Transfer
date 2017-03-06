
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


// Set these to run example.
#define FIREBASE_HOST "FIREBASE_HOST"
#define FIREBASE_AUTH "FIREBASE_AUTH"
#define WIFI_SSID " WIFI_SSID "
#define WIFI_PASSWORD "WIFI_PASSWORD"

void setup() {
  Serial.begin(115200);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
  

  // get value 
  Serial.print("truth: ");
  Serial.println(Firebase.getBool("truth"));
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // remove value
 // Firebase.remove("number");
  Serial.print("Get: Number");
  Serial.println(Firebase.getFloat("number"));
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  Serial.print("Gets: /logs/");
  Serial.println(Firebase.getString("logs"));
  // set bool value
  if (Firebase.failed()) {
      Serial.print("setting /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  delay(1000);

  delay(1000);
  
  Serial.print("Gets: Message");
  Serial.println(Firebase.getString("messege"));
  // set bool value
  if (Firebase.failed()) {
      Serial.print("setting /messege failed:");
      Serial.println(Firebase.error());  
      return;
  }
  // append a new value to /logs
}
