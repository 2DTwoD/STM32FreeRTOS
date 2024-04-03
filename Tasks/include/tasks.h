#ifndef TASKS_H
#define TASKS_H

#include "FreeRTOS.h"
#include "task.h"

#include "globals.h"
#include "register_work.h"

void blinkTask(void *pvParameters);

void usartTask(void *pvParameters);

#endif
