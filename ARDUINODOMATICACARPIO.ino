#include <Arduino.h>

#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

const char* WIFI_SSID = "PAIN";
const char* WIFI_PASSWORD= "carpio123";


const char* API_KEY= "AIzaSyCbpEN_BGy9i1KlI-Yr7_jnYVKwP7BQTkc";

const char* DATABASE_URL= "https://domotica-carpiogaibor-default-rtdb.firebaseio.com/"; //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app;

const char* USER_EMAIL= "domatica@esp.com";
const char* USER_PASSWORD= "123456789";


FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;

const int BOTON1 =23;
bool buttonState = false;

const int BOTON2 =22;
bool buttonState2 = false;

const int BOTON3 =21;
bool buttonState3 = false;

const int BOTON4 =19;
bool buttonState4 = false;

const int BOTON5 =18;
bool buttonState5 = false;

const int BOTON6 =5;
bool buttonState6 = false;

void setup_WIFI(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long ms = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  config.signer.tokens.legacy_token = "<database secret>";
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096, 1024);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

}

void setup() {
    Serial.begin(115200);
    setup_WIFI();
    setupFirebase();
    pinMode(BOTON1,INPUT);
    pinMode(BOTON2,INPUT);
    pinMode(BOTON3,INPUT);
    pinMode(BOTON4,INPUT);
    pinMode(BOTON5,INPUT);
    pinMode(BOTON6,INPUT);
}

void loop() {

  if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState = digitalRead(BOTON1);
      
    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setBool(&fbdo, F("/casa/dormitorio"), buttonState) ? "DORMITORIO" : fbdo.errorReason().c_str());
    
  }if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState2 = digitalRead(BOTON2);
      
    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setBool(&fbdo, F("/casa/atico"), buttonState2) ? "ATICO" : fbdo.errorReason().c_str());
    
  }if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState3 = digitalRead(BOTON3);
      
    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setBool(&fbdo, F("/casa/sala"), buttonState3) ? "SALA" : fbdo.errorReason().c_str());
    
  }if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState4 = digitalRead(BOTON4);
      
    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setBool(&fbdo, F("/casa/comedor"), buttonState4) ? "COMEDOR" : fbdo.errorReason().c_str());
    
  }if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState5 = digitalRead(BOTON5);
      
    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setBool(&fbdo, F("/casa/patio"), buttonState5) ? "PATIO" : fbdo.errorReason().c_str());
    
  }if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0))
  {
      buttonState6 = digitalRead(BOTON6);
      
    //Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/sensor/a")) ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
    Serial.printf("Set int... %s\n", Firebase.RTDB.setBool(&fbdo, F("/casa/recepcion"), buttonState6) ? "RECEPCION" : fbdo.errorReason().c_str());
    
  }

}
