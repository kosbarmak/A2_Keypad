#include "main.h"

#include "stdbool.h"
#include <stdint.h>

/* On the Keypad, from left to right: Row1, Row2, Row3, Row4, Col.1, Col.2, Col.3
*/

#define PC_ROW_START 0
#define PC_COLUMN_START 10

bool row_is_high(uint8_t i) {
	return (GPIOC->IDR & (PC_ROW_START << i));
}

bool col_is_high(uint8_t j) {
	return (GPIOC->IDR & (PC_COLUMN_START << j));
}




int main(void)
{
    HAL_Init();

    while (1) {
        /* Add application code here. */
    }

}
