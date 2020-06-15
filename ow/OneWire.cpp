/**
   One-Wire Debug
   2020/6/9
   Ryter Chen
 **/

#include "OneWire.h"

char OneWire::platform_init(void)
{
#ifdef CONFIG_PLATFORM_ARDUINO
  pinMode(OW_PIN, OUTPUT);
  OW_set_gpio_state(HIGH);
  OW_delay((int)CONFIG_SEND_BYTE_DELAY);
#elif CONFIG_PLATFORM_STM32
  //pass
#endif
}

char OneWire::print(const char *str_out)
{
  while(*str_out)
  {
    if(*str_out == '\0')
      break;
    this->send_byte(*str_out++);
  }
  
  return OW_SUCCESS;
}


char OneWire::println(const char *str_out)
{
  this->print(str_out);

  /* send '\n' */
  this->send_byte('\r');  // in Windows platform need '\r'
  this->send_byte('\n');

  return OW_SUCCESS;
}

char OneWire::send_byte(const char byte_out)
{
  int bit;

  /* Start bit */
  OW_set_gpio_state(LOW);
  OW_delay((int)CONFIG_SEND_BYTE_DELAY * CONFIG_START_BIT_LENGTH);

  /* Data bit */
  for (bit = BIT(0); bit <= BIT(CONFIG_DATA_BIT_LENGTH); bit <<= 1) {

    /* From Data Bit Set GPIO High/Low */
    OW_set_gpio_state((byte_out & bit) ? HIGH : LOW);
    
    /* Delay SEND_BYTE_DELAY */
    OW_delay(CONFIG_SEND_BYTE_DELAY);
  }

  /* Stop bit */
  OW_set_gpio_state(HIGH);
  OW_delay((int)CONFIG_SEND_BYTE_DELAY * CONFIG_STOP_BIT_LENGTH);

  return OW_SUCCESS;
}
