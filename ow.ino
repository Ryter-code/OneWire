

#include "OneWire.h"

OneWire ow;

void setup() {
  Serial.begin(115200);
}


void loop() {
  ow.platform_init();
  ow.print("Test123 Test123 Test123 Test123 Test123 Test123 Test123 Test123 Test123 Test123 Test123 Test123 ");
  ow.print("TestABC TestABC TestABC TestABC TestABC TestABC TestABC TestABC TestABC TestABC TestABC TestABC ");
  while(1);
}
