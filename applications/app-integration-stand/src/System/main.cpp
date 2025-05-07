#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Config/FreeRTOSConfig.h"
#include "third-party/FreeRTOS/src/include/FreeRTOS.h"
#include "third-party/FreeRTOS/src/include/task.h"

extern void vMainTask(void*);

int main(void)
{
	xTaskCreate(vMainTask, "Main", configLARGE_STACK_SIZE * 10, NULL, tskIDLE_PRIORITY + 1, NULL);

	vTaskStartScheduler();
}
