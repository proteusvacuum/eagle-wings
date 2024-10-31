#include <Servo.h>

constexpr const int LEFT_WING_PIN = 9;
constexpr const int RIGHT_WING_PIN = 10;

constexpr const int MAX_POS = 80;
constexpr const int MIN_POS = 10;

Servo leftWing;
Servo rightWing;

int currentPosition{0};

void setup()
{
  leftWing.attach(LEFT_WING_PIN);
  rightWing.attach(RIGHT_WING_PIN);
}

void setPosition(int pos)
{
  leftWing.write(pos);
  rightWing.write(90 - pos);
}

void loop()
{
  // Downstroke - a bit slower
  for (currentPosition = MIN_POS; currentPosition <= MAX_POS; currentPosition += 1)
  {
    setPosition(currentPosition);
    delay(15);
  }

  delay(150);

  // Upstroke - a bit faster
  for (currentPosition = MAX_POS; currentPosition >= MIN_POS; currentPosition -= 1)
  {
    setPosition(currentPosition);
    delay(10);
  }
}
