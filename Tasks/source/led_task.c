#include "tasks.h"

void blinkTask(void *pvParameters){
	while(1){
		taskENTER_CRITICAL();
		togglePin(&ledC);
		taskEXIT_CRITICAL();
		vTaskDelay(1000);
	}
}
