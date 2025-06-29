#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Firebase credentials
#define API_KEY "AIzaSyAB5ErkFfIJgjlp8-ZqiKW7-OFlkFMT1Aw"
#define DATABASE_URL "https://project-nsic-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define USER_EMAIL "example@gmail.com"
#define USER_PASSWORD "123456789"

// WiFi credentials
#define NETWORK "home"
#define PASSWORD "123456789"

// Firebase objects
FirebaseData fbdo, fbdo1, fbdo2, fbdo3;
FirebaseAuth auth;
FirebaseConfig config;

// Relays
#define relay1 5
#define relay2 18
#define relay3 19
#define relay4 23

// Function 1
// void i2cScanner() {
//   Serial.println("Scanning I2C...");
//   for (byte i = 1; i < 127; i++) {
//     Wire.beginTransmission(i);
//     if (Wire.endTransmission() == 0) {
//       Serial.print("Found I2C device at 0x");
//       Serial.println(i, HEX);
//     }
//   }
// }

// Function 2
void connectToWiFi() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Connecting...");
  WiFi.begin(NETWORK, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
 // delay(2000);
}

// Function 3
void setFirebase() {
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.begin(&config, &auth);
}

// Arduino setup()
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
 // delay(1000);
 

  lcd.begin();
  lcd.backlight();

  connectToWiFi();
  setFirebase();

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

// Arduino loop()
void loop() {
  if (Firebase.ready()) {
    Firebase.getInt(fbdo, "/gesture/Load1");
    Firebase.getInt(fbdo1, "/gesture/Load2");
    Firebase.getInt(fbdo2, "/gesture/Load3");
    Firebase.getInt(fbdo3, "/gesture/Load4");

    int Load1 = fbdo.to<int>();
    int Load2 = fbdo1.to<int>();
    int Load3 = fbdo2.to<int>();
    int Load4 = fbdo3.to<int>();

    lcd.clear();

    digitalWrite(relay1, Load1 ? LOW : HIGH);
    lcd.setCursor(0, 0);
    lcd.print(Load1 ? "L1 ON " : "L1 OFF");

    digitalWrite(relay2, Load2 ? LOW : HIGH);
    lcd.setCursor(8, 0);
    lcd.print(Load2 ? "L2 ON " : "L2 OFF");

    digitalWrite(relay3, Load3 ? LOW : HIGH);
    lcd.setCursor(0, 1);
    lcd.print(Load3 ? "L3 ON " : "L3 OFF");

    digitalWrite(relay4, Load4 ? LOW : HIGH);
    lcd.setCursor(8, 1);
    lcd.print(Load4 ? "L4 ON " : "L4 OFF");

    //delay(500);
  }
}
