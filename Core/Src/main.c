#include "main.h"

#include "stdbool.h"
#include <stdint.h>

/* On the Keypad, from left to right: Row1, Row2, Row3, Row4, Col.1, Col.2, Col.3
*/

#define PC_ROW_START 0
#define PC_COLUMN_START 10

void gpio_init() {

}

bool row_is_high(uint8_t i) {
	return (GPIOC->IDR & (PC_ROW_START << i));
}

void col_set(uint8_t j, bool high) {

}


bool key_is_pressed(uint8_t i, uint8_t j) {

}

int main(void)
{
    HAL_Init();

    while (1) {
        /* Add application code here. */
    }

}
