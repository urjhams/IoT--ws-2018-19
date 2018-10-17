#include <Adafruit_Microbit.h>
#include <OneButton.h>

Adafruit_Microbit_Matrix microbit;

OneButton buttonLeft(5, true);
OneButton buttonRight(11, true);

void setup() {
  buttonLeft.attachSingleClick(clickLeft);
  buttonRight.attachSingleClick(clickRight);
}

void loop() {
  buttonLeft.tick();
  buttonRight.tick();
  delay(10);
}

void clickLeft() {
  
}

void clickRight() {
  
}
