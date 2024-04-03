#ifndef INIT_H
#define INIT_H

#include "stm32f10x.h"
#include "register_work.h"

#define ALL_32_BITS 0xFFFFFFFF
#define ALL_16_BITS 0xFFFF

void rccInit();

void portInit();

void uartInit();

void extiInit();

#endif
