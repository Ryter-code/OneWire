/**
   One-Wire Debug
   2020/6/9
   Ryter Chen
 **/


/* ***** Configuration Platform ***** */
#define CONFIG_PLATFORM_ARDUINO
//#define CONFIG_PLATFORM_STM32_HAL
/* ********************************** */


/* ***** Configuration Platform Interface ***** */
#ifdef CONFIG_PLATFORM_ARDUINO
  #include "Arduino.h"
  #define OW_PIN 8
  #define OW_delay(us) delayMicroseconds(us);
  #define OW_set_gpio_state(S) digitalWrite(OW_PIN, S);
  #define OW_get_gpio_state() digitalRead(OW_PIN);
#elif CONFIG_PLATFORM_STM32_HAL
  //pass
#endif
/* ******************************************** */


/* ***** Configuration One-Wire Input/Output Type ***** */
#define CONFIG_ONE_WIRE_OUTPUT_ONLY
//#define CONFIG_ONE_WIRE_INPUT_ONLY
/* **************************************************** */


/* ***** Configuration Baud Rate ***** */
//#define CONFIG_BAUD_RATE_9600    // Default Baud Rate
//#define CONFIG_BAUD_RATE_19200
//#define CONFIG_BAUD_RATE_38400
//#define CONFIG_BAUD_RATE_57600

#ifdef CONFIG_BAUD_RATE_9600
  #define CONFIG_SEND_BYTE_DELAY 102 // 96~107 us
#elif defined(CONFIG_BAUD_RATE_19200)
  #define CONFIG_SEND_BYTE_DELAY 49  // 47~51 us
#elif defined(CONFIG_BAUD_RATE_38400)
  #define CONFIG_SEND_BYTE_DELAY 23  // 22~24 us
#elif defined(CONFIG_BAUD_RATE_57600)
  #define CONFIG_SEND_BYTE_DELAY 14 // 14 us
#else
  #define CONFIG_SEND_BYTE_DELAY 102 // Default Baud Rate is 9600
#endif
/* ************************************ */


/* ***** Configuration Data Frame ***** */
#define CONFIG_START_BIT_LENGTH 1 // start bit : 1
#define CONFIG_DATA_BIT_LENGTH 8  // data bit  : 8
#define CONFIG_STOP_BIT_LENGTH 1  // stop bit  : 1
/* ************************************ */


/* ***** Configuration Buffer Size ***** */
#ifdef CONFIG_ONE_WIRE_OUTPUT_ONLY
  #define CONFIG_OUT_BUFFER_SIZE 128
#endif
#ifdef CONFIG_ONE_WIRE_INPUT_ONLY
  #define CONFIG_READ_BUFFER_SIZE 128
#endif
/* ************************************* */


/* ***** Define Tool Function ***** */
#define BIT(bit) (0x01 << (bit))
/* ******************************** */


enum OW_keycode {
  OW_SUCCESS = 0,
  OW_ALL_ZERO_ERROR,
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
    char print(const char* str_out);
    char println(const char* str_out);
    char send_byte(const char byte_out);
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
