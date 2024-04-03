#include "main.h"

PinPort ledC = {GPIOC, 13};
QueueHandle_t dataFromUart = NULL;
TimerHandle_t buttonTimer = NULL;

void bTimerCallback( TimerHandle_t xTimer ){
	if(GPIOA->IDR & GPIO_IDR_IDR0){
		return;
	}
	taskENTER_CRITICAL();
	togglePin(&ledC);
	taskEXIT_CRITICAL();
}

int main(void){
	rccInit();
	portInit();
	uartInit();
	extiInit();
	buttonTimer = xTimerCreate("BTimer", 50, pdFALSE, ( void * ) 0, bTimerCallback);
	xTaskCreate(blinkTask, "Blink", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
	xTaskCreate(usartTask, "Usart", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);
	vTaskStartScheduler();
	while(1);
}

void USART1_IRQHandler(void){
	if(USART1->SR & USART_SR_RXNE){
		BaseType_t xHigherPriorityTaskWoken = pdTRUE;
		uint32_t data = USART1->DR;
		xQueueSendFromISR(dataFromUart, (void*)&data, &xHigherPriorityTaskWoken);
	}
}

void EXTI0_IRQHandler(void){
	EXTI->PR |= EXTI_PR_PR0; 
	xTimerStartFromISR(buttonTimer, 0);
}
