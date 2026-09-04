#include "main.h"

int main(void)
{
    HAL_Init();

    while (1) {
        /* Add application code here. */
    }
}

void Error_Handler(void)
{
    __disable_irq();
    while (1) {
    }
}
