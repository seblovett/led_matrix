#ifndef MAX7219
#define MAX7219

#include "main.h"
extern SPI_HandleTypeDef hspi1;

void display_test(uint8_t on);
void set_scan_limit();
void set_leds(uint8_t row, uint8_t col);
void set_display_on(uint8_t on);

#define MAX7219_NOOP    0x0
#define MAX7219_DIGIT_0 0x1
#define MAX7219_DIGIT_1 0x2
#define MAX7219_DIGIT_2 0x3
#define MAX7219_DIGIT_3 0x4
#define MAX7219_DIGIT_4 0x5
#define MAX7219_DIGIT_5 0x6
#define MAX7219_DIGIT_6 0x7
#define MAX7219_DIGIT_7 0x8
#define MAX7219_DECODE_MODE 0x9
#define MAX7219_INTENSITY   0xA
#define MAX7219_SCAN_LIMIT  0xB
#define MAX7219_SHUTDOWN    0xC
#define MAX7219_DISPLAY_TEST 0xF
#endif //defined MAX7219