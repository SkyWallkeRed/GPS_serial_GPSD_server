
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Choose two Arduino pins to use for software serial
const int RXPin = 13;
const int TXPin = 5;
const int buttonPin = 4; // pushbutton pin

const int greenLedPin = 3; // led
const int yellowLedPin = 8; // led
const int redLedPin = 9; // led

bool buttonState = true; // variable for reading the pushbutton status

// Create a TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS module
SoftwareSerial ss(RXPin, TXPin);

bool isLoaded = false;

void setup() {
  Serial.begin(9600);
  Serial.println("init arduino pro mini bud: 9600");

  pinMode(buttonPin, INPUT);

  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  Serial.println("init arduino pro mini GPS module bud: 9600");
  ss.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == true) {
    buttonState = !buttonState;
    Serial.print("buttonState changed");
  } while (digitalRead(buttonPin) == true) {
    delay(30); // SMALL DELAY TO PREVENT DUBEL TIK ON RUNTIME
  }


  if (ss.available() > 0 && !buttonState) {

    isLoaded = true;
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    while (ss.available() > 0) {
      // get the byte data from the GPS
      byte gpsData = ss.read();
      Serial.write(gpsData);
    }
    return;
  }

  if ((ss.available() > 0) && buttonState) {

    while ((ss.available() > 0)) {
      if (gps.encode(ss.read())) {
        if (gps.location.isValid()) {

          Serial.print("lat: ");
          Serial.print(gps.location.lat(), 6);
          Serial.println("");
          Serial.println("");

          Serial.print("lng: ");
          Serial.print(gps.location.lng(), 6);
          Serial.println("");
          Serial.println("");

          digitalWrite(greenLedPin, LOW);
          digitalWrite(yellowLedPin, LOW);
          digitalWrite(redLedPin, HIGH);
          delay(300);

          // led yellow
        } else {
          digitalWrite(greenLedPin, LOW);
          digitalWrite(redLedPin, LOW);
          digitalWrite(yellowLedPin, HIGH);
          delay(300);


          // led red
        }
      }
    }
  }
}
