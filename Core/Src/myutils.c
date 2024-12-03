#include "myutils.h"
#include "stm32f7xx_hal.h"

void set_PWM_CCR(unsigned long* ccr_p, uint16_t val) {
  *ccr_p = val;
}

uint8_t is_bit_on(uint8_t num, uint8_t mask) {
  if ((int)(num & mask) > 0) return 1;
  else return 0;
}

void set_task_led(uint8_t flag) {
  uint8_t led_bit_g = 0;
  uint8_t led_bit_b = 0;
  uint8_t led_bit_r = 0;
  uint8_t count = 0;

  while (flag > 0) {
    flag >>= 1;
    count++;
  }

  led_bit_g = is_bit_on(count, 0x01);
  led_bit_b = is_bit_on(count, 0x02);
  led_bit_r = is_bit_on(count, 0x04);

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, led_bit_g);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, led_bit_b);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, led_bit_r);
}