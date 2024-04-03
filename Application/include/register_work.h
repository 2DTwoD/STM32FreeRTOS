#ifndef REGISTER_WORK_H
#define REGISTER_WORK_H

#include "stm32f10x.h"

typedef struct {
	GPIO_TypeDef* port;
	uint8_t pin;
} PinPort;

void setRegister32(volatile uint32_t *const reg, uint32_t mask, uint32_t value);
void setRegister16(volatile uint16_t *const reg, uint32_t mask, uint32_t value);
void setPin(PinPort* pp);
void resetPin(PinPort* pp);
void togglePin(PinPort* pp);

#endif
