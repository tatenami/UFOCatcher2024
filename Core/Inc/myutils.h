#ifndef MYUTILS_H
#define MYUTILS_h

#include <stdint.h>

void set_PWM_CCR(unsigned long* ccr_p, uint16_t val);
uint8_t is_bit_on(uint8_t num, uint8_t mask);
void set_task_led(uint8_t flag);

#endif /* MYUTILS_H */