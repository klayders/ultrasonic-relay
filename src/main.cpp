#include <Arduino.h>
#include <Ultrasonic.h>

#define RELAY_OMG 19

Ultrasonic ultrasonic(32, 33);
static long oldTime = 0;

void doIt()
{
  delay(100);
  int cm = ultrasonic.read(CM);
  Serial.print("Distance in CM: ");
  Serial.println(cm);

  if (millis() - oldTime > 1000)
  {
    if (cm < 10)
    {
      Serial.println("on");
      digitalWrite(RELAY_OMG, LOW);
    }
    else
    {
      Serial.println("off");
      digitalWrite(RELAY_OMG, HIGH);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(RELAY_OMG, OUTPUT_OPEN_DRAIN);
}

void loop()
{

  doIt();

}
