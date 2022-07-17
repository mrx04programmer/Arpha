#include "Mouse.h"
void setup() {
  Mouse.begin();
}

void loop() {
   Mouse.move(0, 0, 0);
   Mouse.click();
}
