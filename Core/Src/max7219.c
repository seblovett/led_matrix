#include "max7219.h"
#include "MAX7219.h"
#include "stm32_hal_legacy.h"

void spi_write(uint8_t reg, uint8_t data) {
  HAL_GPIO_WritePin(LOAD_GPIO_Port, LOAD_Pin, GPIO_PIN_RESET);

  uint16_t buf[1] = {0};
  buf[0] = (reg << 8) | data;
  HAL_SPI_Transmit(&hspi1, buf, 1, 1000);

  HAL_GPIO_WritePin(LOAD_GPIO_Port, LOAD_Pin, GPIO_PIN_SET);
}

void display_test(uint8_t on) {
  if (on)
    spi_write(MAX7219_DISPLAY_TEST, 0x01);
  else
    spi_write(MAX7219_DISPLAY_TEST, 0x00);
}

void set_leds(uint8_t row, uint8_t col) { spi_write(row + 1, col); }

void set_display_on(uint8_t on) {
  if (on)
    spi_write(MAX7219_SHUTDOWN, 0x01);
  else
    spi_write(MAX7219_SHUTDOWN, 0x00);
}
void set_scan_limit() {

  spi_write(MAX7219_DECODE_MODE, 0x00);
  spi_write(MAX7219_INTENSITY, 0x01);
  spi_write(MAX7219_SCAN_LIMIT, 0x07);
}