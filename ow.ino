

#include "OneWire.h"

OneWire ow;

void setup() {
  Serial.begin(115200);
}


void loop() {
  ow.platform_init();
  ow.print("Test123");
  ow.print("TestABC");
  ow.println("Test123");
  ow.println("TestABC");
  while(1);
}
