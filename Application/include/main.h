#ifndef MAIN_H
#define MAIN_H

#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "init.h"
#include "register_work.h"
#include "tasks.h"

void vApplicationIdleHook ( void ){
}

void vApplicationTickHook ( void ){
}

void vApplicationMallocFailedHook ( void ){
	while(1);
}

void vApplicationStackOverflowHook( TaskHandle_t xTask,
    									char * pcTaskName ){
	( void ) pcTaskName;
	( void ) xTask;
	while(1);
}

void badTimeOut(){
	int i = 0;
	for(i = 0; i < 1000000; i++);
}

#endif
