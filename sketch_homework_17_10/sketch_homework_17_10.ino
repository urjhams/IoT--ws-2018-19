#include <Adafruit_Microbit.h>
#include <OneButton.h>

Adafruit_Microbit_Matrix microbit;

int drop_column = random(5);
// player always be initialized in the middle column (index 2)
int player_column = 2;

// the ball at first start to drop at row 1 (index 0)
int droping_at_row = 0;

// LED matrix
uint8_t matrix[5];

// speed (milisecond)
int spd = 300;

// number of winning rounds
int wins = 0;

// current round
int rounds = 1;

enum cases {
  empty = B00000,
  first = B10000,
  second = B01000,
  third = B00100,
  fourth = B00010,
  fifth = B00001
};

const uint8_t ledCases[] = {first, second, third, fourth, fifth};

const uint8_t win[] = 
  { B00100,
    B01010,
    B10001,
    B01010,
    B00100, };

const uint8_t lose[] =
  { B10001,
    B01010,
    B00100,
    B01010,
    B10001, };
    
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
  microbit.show(matrix);
  delay(spd);

  if (droping_at_row == 4) {
    endRound();
  } else {
    droping_at_row++;
  }
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

void endRound() {
  if (drop_column == player_column) {  
    wins++; 
    microbit.show(win); 
  } else {       
    microbit.show(lose); 
  }

  if (rounds == 5) {
    endGame();
  } else {
    rounds++;
    droping_at_row = 0;
    player_column = 2;
    drop_column = random(5);
    delay(1000);
  }
  
}

void endGame() {
  rounds = 1;
  microbit.print(wins);
  wins = 0;
  droping_at_row = 0;
  delay(2000);
}

void updateFrame() {
  for (int i = 0; i < 5; i++) {
    uint8_t ball;
    uint8_t player;
    ball = (i == droping_at_row) ? ledCases[drop_column] : empty;
    player = (i == 4) ? ledCases[player_column] : empty;
    matrix[i] = ball | player;
  }
}
