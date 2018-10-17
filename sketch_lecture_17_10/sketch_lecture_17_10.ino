#include <Adafruit_Microbit.h>
#include <OneButton.h>

Adafruit_Microbit_Matrix microbit;

const int buttonB = 11;     // the number of the pushbutton pin
const int buttonA = 5;
OneButton button(11, true);
const uint8_t
  smile_bmp[] =
  { B00000,
    B00001,
    B10010,
    B01100,
    B01000, };

const uint8_t
  signal_bmp[] =
  { B00000,
    B00100,
    B01110,
    B00100,
    B00000, };

    
void setup() {
  Serial.begin(9696);
  Serial.println("Ready");
  microbit.begin();
  pinMode(buttonB, INPUT);
  pinMode(buttonA, INPUT);

  // task 4
  prepareButton();
}

void loop() {
  // task 1
  //sosBlink();
  
  // task 2
  //showGreeting();

  // task 3
  //stepwise();

  // task 4
  button.tick();
  delay(10);
}

// --- task 1: blink LED array in S-O-S rhythm
void sosBlink() {
  if (! digitalRead(buttonB)) {
    blinkLoop(200, "S");
    blinkLoop(500, "O");
    blinkLoop(200, "S");
    delay(1000);
    }
}

void blinkLoop(int delaySecond, char* letter) {
  for (int i = 0; i < 3; i++) {
    delay(delaySecond);
    microbit.fillScreen(LED_ON);
    //microbit.print(letter);
    delay(delaySecond);
    microbit.clear();
  }
}

// --- task 2: display of "Hello world"
void showGreeting() {
  if (! digitalRead(buttonA)) {
    microbit.print("Hello World!");
  }
}

// --- task 3: Stepwise animation of text with a button press
char* letters[11] = {"H", "E", "L", "L", "O", " ", "W", "O", "R", "L", "D"};
int indx = 0;

void stepwise() {
  if (! digitalRead(buttonB) && indx < sizeof(letters) - 1){
      indx++;
      microbit.clear();
      delay(100);
    }
    if (! digitalRead(buttonA) && indx > 0){
      indx--;
      microbit.clear();
      delay(100);
    }
    delay(100);
    microbit.print(letters[indx]);
}

// --- task 4: Implement a double click
void prepareButton() {
  button.attachDoubleClick(doubleClick);
}

void doubleClick() {
  for (int i = 0; i < 10; i++) {
    microbit.show(signal_bmp);
    delay(100);
    microbit.clear();
    delay(100);
  }
}
