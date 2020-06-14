/**
   One-Wire Debug
   2020/6/9
   Ryter Chen
 **/

#define CONFIG_PLATFORM_ARDUINO
//#define CONFIG_PLATFORM_STM32

// platform interface
#ifdef CONFIG_PLATFORM_ARDUINO
  #include "Arduino.h"
  #define OW_PIN 8
  #define OW_delay(us) delayMicroseconds(us);
  #define OW_set_gpio_state(S) digitalWrite(OW_PIN, S);
  #define OW_get_gpio_state() digitalRead(OW_PIN);
  #define OW_show(C) serial.print(c);
#endif

#define CONFIG_ONE_WIRE_OUTPUT_ONLY
//#define CONFIG_ONE_WIRE_INPUT_ONLY

//#define CONFIG_SEND_BYTE_DELAY_BIAS -0 // us
//#define CONFIG_SEND_BYTE_DELAY (104 + CONFIG_SEND_BYTE_DELAY_BIAS) // us (9600)
#define CONFIG_SEND_BYTE_DELAY_BIAS -1 // us
#define CONFIG_SEND_BYTE_DELAY (52 + CONFIG_SEND_BYTE_DELAY_BIAS) // us (19200)
#define CONFIG_START_BIT_LENGTH 1 // 1 (bit)
#define CONFIG_STOP_BIT_LENGTH 1  // 1 , 1.5 (bit)
#define CONFIG_DATA_FRAME_BIT 8

#define CONFIG_OUT_BUFFER_SIZE 128
#define CONFIG_READ_BUFFER_SIZE 128

#define BIT(bit) (0x01 << (bit))


enum OW_keycode {
  OW_ALL_ZERO_ERROR = 0,
  OW_SUCCESS,
  OW_ECHO,
  OW_BUFFER_FULL,
  OW_BUFFER_OVERFLOW_ERROR,
  OW_STOP_BIT_ERROR,
  OW_UNKNOWN_CODE_ERROR,
  OW_NO_FUNCTION_ERROR,
  OW_SEND_NULL_ERROR,
  OW_UNKNOWN_ERROR,
  OW_KEYWORD_NUM
};

#ifndef OneWire_h
#define OneWire_h

class OneWire  
{  
  
  public:  

    /* one-wire init function */
    char platform_init(void);

    /* one-wire input only function */
    #ifdef CONFIG_ONE_WIRE_INPUT_ONLY
      char readline(void);
      char read_byte(void);
      char read_buffer[CONFIG_READ_BUFFER_SIZE];
    #endif

    /* one-wire output only function */
    #ifdef CONFIG_ONE_WIRE_OUTPUT_ONLY
      char print(char* str_out);
      char send_byte(const char byte_out);
      char out_buffer[CONFIG_OUT_BUFFER_SIZE];
    #endif
    
  private:  
    
};  
  
#endif  




/*
  enum OW_gpio_state {
	LOW = 0,
	HIGH
  };
*/
