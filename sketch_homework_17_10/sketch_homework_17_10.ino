#include <Adafruit_Microbit.h>
#include <OneButton.h>

Adafruit_Microbit_Matrix microbit;

int drop_column = random(5);
// player always be initialized in the middle column (index 2)
int player_column = 2;

// the ball at first start to drop at row 1 (index 0)
int droping_at_row = 0;

enum cases {
  empty = B00000,
  first = B10000,
  second = B01000,
  third = B00100,
  fourth = B00010,
  fifth = B00001
};

const uint8_t ledCases[] = {first, second, third, fourth, fifth};

OneButton buttonLeft(5, true);
OneButton buttonRight(11, true);

void setup() {
  microbit.begin();
  buttonLeft.attachClick(clickLeft);
  buttonRight.attachClick(clickRight);
}

void loop() {
  buttonLeft.tick();
  buttonRight.tick();
  delay(10);
}

void clickLeft() {
  if (player_column > 0) {
    player_column--;
  }
}

void clickRight() {
  if (player_column < 4) {
    player_column++;
  }
}

void updateFrame() {
  for (int i = 0; i < 5; i++) {
    uint8_t ball;
    uint8_t player;
    if (i == droping_at_row) {
      ball = ledCases[]
    }
  }
}
