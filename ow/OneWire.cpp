
#include "OneWire.h"
#include <string.h>

char OneWire::platform_init(void)
{
  pinMode(OW_PIN, OUTPUT);
  OW_set_gpio_state(HIGH);
  OW_delay((int)CONFIG_SEND_BYTE_DELAY);
}

char OneWire::print(char* str_out)
{
  char i = 0, re;

  if (out_buffer == NULL)
    return OW_SEND_NULL_ERROR;
    
  memset(out_buffer, 0, sizeof(out_buffer));

  strcpy(out_buffer, str_out);

  while (out_buffer[i] != 0)
  {
    this->send_byte(out_buffer[i]);
    i++;
  }
  /* send '\n' */
  send_byte('\r');
  send_byte('\n');
  
  return OW_SUCCESS;
}

char OneWire::send_byte(const char byte_out)
{
#ifdef CONFIG_ONE_WIRE_OUTPUT_ONLY

  int bit;

  // Start bit
  OW_set_gpio_state(LOW);
  OW_delay((int)CONFIG_SEND_BYTE_DELAY * CONFIG_START_BIT_LENGTH);

  for (bit = BIT(0); bit <= BIT(CONFIG_DATA_FRAME_BIT); bit <<= 1) { //
    OW_set_gpio_state((byte_out & bit) ? HIGH : LOW);
    
    //Serial.print("set_gpio: [");
    //Serial.print(bit);
    //Serial.print("]:");
    //Serial.println((byte_out & bit) ? HIGH : LOW);
    /* Delay SEND_BYTE_DELAY */
    OW_delay(CONFIG_SEND_BYTE_DELAY);
  }

  // Stop bit
  OW_set_gpio_state(HIGH);
  OW_delay((int)CONFIG_SEND_BYTE_DELAY * CONFIG_STOP_BIT_LENGTH *5);
  return OW_SUCCESS;

#endif
}
