#include <CapacitiveSensor.h>
#include <Manchester.h>

#define TX_PIN 1
#define LED_PIN 0
#define CAP_OUT_PIN 4
#define CAP_IN_PIN 3
#define VIB_PIN 2

enum MsgState : uint8_t
{
  NONE,
  UNKNOWN_ERROR,
  GLASSES_OFF,
  GLASSES_ON,
  BATTERY_LOW
};

const uint32_t keepAlivePeriod = 4000; // ms
const uint32_t vibeEveryPeriod = 2000; // ms
const uint32_t offVibeDelay = 10000;   // ms

const uint8_t senRes = 100;
const uint8_t crossThresh = 20;
const uint8_t countThresh = 3;
const uint8_t countSetback = 2;

uint8_t crossCount = 0;
uint32_t lastSent;
//uint32_t lastOff;
bool on = true;

// Resistor effects sensitivity, experiment with values, 50K - 50M.
// Larger resistor values yield larger sensor values.
// Currently 1M resistor between pins
CapacitiveSensor sen = CapacitiveSensor(CAP_OUT_PIN, CAP_IN_PIN);

void setup()
{
  man.setupTransmit(TX_PIN, MAN_600);
  pinMode(LED_PIN, OUTPUT);
//  pinMode(VIB_PIN, OUTPUT);
  digitalWrite(VIB_PIN, LOW);
//  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

void loop()
{
  long rawCs = sen.capacitiveSensor(senRes);
  uint8_t cs = map(rawCs, 0, 10000, 0, 255);

  if ((!on && cs > crossThresh) || (on && cs < crossThresh)) {
    crossCount += 1;
    if (crossCount > countThresh) {
      on = not on;
      crossCount = 0;
      updateGlasses();
//      if (!on) {
//        lastOff = millis();
//      }
    }
  } else {
    crossCount = (crossCount > countSetback) ? (crossCount - countSetback) : 0;
  }

  uint32_t now = millis();
  if (now - lastSent > keepAlivePeriod) {
    updateGlasses();
  }
//  if (!on && now - lastOff > offVibeDelay) {
//    digitalWrite(VIB_PIN, HIGH);
//  } else {
//    digitalWrite(VIB_PIN, LOW);
//  }
//  if (!on) {
//    digitalWrite(VIB_PIN, HIGH);
//  } else {
//    digitalWrite(VIB_PIN, LOW);
//  }

  delay(400);
}

void updateGlasses() {
  if (on) {
    man.transmit(GLASSES_ON);
    digitalWrite(LED_PIN, LOW);
  } else {
    man.transmit(GLASSES_OFF);
    digitalWrite(LED_PIN, HIGH);
  }
  lastSent = millis();
}
