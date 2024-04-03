#include "tasks.h"
#include <stdio.h>

void setZerosInArray(char *const array, uint8_t size){
	uint8_t i = 0;
	while(i < size){
		array[i++] = '-';
	}
}

void addItemInArray(char *const array, char value, uint8_t size){
	uint8_t i = 0;
	uint8_t end = size - 1;
	while(i < end){
		array[i] = array[i + 1];
		i++;
	}
	array[end] = value;
}

void sendMessage(char *const message, uint8_t size){
	uint8_t i = 0;
	while(i < size){
		while(!(USART1->SR & USART_SR_TXE));
		USART1->DR = (uint32_t)message[i++];
	}
}

void usartTask(void *pvParameters){
	dataFromUart = xQueueCreate(20, sizeof(uint32_t));
	char dataFromQueue = 0;
	//char dataToUART[] = "Hi from STM32";
	char buff[10];
	while(1){
		if(xQueueReceive(dataFromUart, &(dataFromQueue),( TickType_t ) 10 ) == pdPASS){
			switch(dataFromQueue){
				case 's':
					setZerosInArray(buff, 10);
					break;
				case 'e':
					sendMessage(buff, 10);
					break;
				default:
					addItemInArray(buff, dataFromQueue, 10);
					break;
			}
		}
	}
}
