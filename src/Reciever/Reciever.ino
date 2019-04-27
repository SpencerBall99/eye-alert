#include <Manchester.h>

#define RX_PIN 4
#define LED_PIN 3

enum MsgState: uint8_t
{
  NONE,
  UNKNOWN_ERROR,
  GLASSES_OFF,
  GLASSES_ON,
  BATTERY_LOW
};

const uint32_t keepAliveThresh = 13000; // ms
const uint32_t keepAlivePeriod = 4000;  // ms (used only on glasses)

MsgState currState = NONE;
uint32_t lastArrival;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  man.setupReceive(RX_PIN, MAN_600);
  man.beginReceive();
  lastArrival = millis();
  Serial.println("Receiver setup.");
}

void loop()
{
  if (man.receiveComplete()) {
    uint8_t msg = man.getMessage();
    man.beginReceive();

    currState = msg;
    updateState();

    Serial.print("Received: ");
    printState();
  }
  
  if (millis() - lastArrival > keepAliveThresh) {
    currState = NONE;
    updateState();
    Serial.println("KEEP ALIVE FAILED");
  }
}

void printState()
{
  switch (currState) {
    case NONE:
      Serial.println("NONE");
      break;
    case UNKNOWN_ERROR:
      Serial.println("ERROR");
      break;
    case GLASSES_OFF:
      Serial.println("GLASSES OFF");
      break;
    case GLASSES_ON:
      Serial.println("GLASSES ON");
      break;
    default:
      Serial.println("OTHER");
      break;
  }
}

void updateState()
{
  switch (currState) {
    case NONE:
      digitalWrite(LED_PIN, LOW);
      break;
    case GLASSES_OFF:
      digitalWrite(LED_PIN, HIGH);
      break;
    case GLASSES_ON:
      digitalWrite(LED_PIN, LOW);
      break;
    default:
      digitalWrite(LED_PIN, HIGH);
      break;
  }
  lastArrival = millis();
}
