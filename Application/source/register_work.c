#include "register_work.h"

void setRegister32(volatile uint32_t * const reg, uint32_t mask, uint32_t value){
	*reg &= ~mask;
	*reg |= value;
}

void setRegister16(volatile uint16_t * const reg, uint32_t mask, uint32_t value){
	*reg &= ~mask;
	*reg |= value;
}

void setPin(PinPort *const pp){
	pp->port->BSRR |= (1 << pp->pin);
}

void resetPin(PinPort *const pp){
	pp->port->BRR |= (1 << pp->pin);
}

void togglePin(PinPort *const pp){
	if(pp->port->ODR & (1 << pp->pin)){
		resetPin(pp);
		return;
	}
	setPin(pp);
}
