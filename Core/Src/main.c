#include "main.h"

#include "stdbool.h"
#include "stm32l476xx.h"
#include "stm32l4xx_hal_gpio.h"
#include <stdint.h>

/* On the Keypad, from left to right: Row1, Row2, Row3, Row4, Col.1, Col.2, Col.3
*/

#define ROW_COUNT 4
#define COL_COUNT 3
#define LED_COUNT 4

#define PC_ROW_START 0
#define PC_COLUMN_START 10
#define PA_LED_START 5

void gpio_init()
{
	// set rows as input
	// PC0-3
	GPIOC->MODER &= ~(GPIO_MODER_MODE0 | GPIO_MODER_MODE1 | GPIO_MODER_MODE2 | GPIO_MODER_MODE3);

	// set cols as output
	// PC10-12
	GPIOC->MODER &= ~(GPIO_MODER_MODE10 | GPIO_MODER_MODE11 | GPIO_MODER_MODE12);
	GPIOC->MODER |= (GPIO_MODER_MODE10_0 | GPIO_MODER_MODE11_0 | GPIO_MODER_MODE12_0);

	// set LEDS as output 
	// PA5-8
	GPIOA->MODER &= ~(GPIO_MODER_MODE5 | GPIO_MODER_MODE6 | GPIO_MODER_MODE7 | GPIO_MODER_MODE8);

	GPIOA->MODER |= (GPIO_MODER_MODE5 | GPIO_MODER_MODE6 | GPIO_MODER_MODE7 | GPIO_MODER_MODE8);
}

bool row_is_high(uint8_t i)
{
	return GPIOC->IDR & (1 << (PC_ROW_START + i));
}

void col_set(uint8_t j, bool high)
{
	GPIOC->ODR &= ~(1 << (PC_COLUMN_START + j));
	if (high) 
		GPIOC->ODR |= (1 << (PC_COLUMN_START + j));
}

bool key_is_pressed(uint8_t i, uint8_t j)
{
}

void LED_turn_off()
{
	GPIOA->ODR &= ~GPIO_ODR_OD5;
	GPIOA->ODR &= ~GPIO_ODR_OD6;
	GPIOA->ODR &= ~GPIO_ODR_OD7;
	GPIOA->ODR &= ~GPIO_ODR_OD8;
}

void count_display(uint8_t val)
{
	LED_turn_off();
	GPIOC->ODR |= ((val) << GPIO_ODR_OD0_Pos);
	HAL_Delay(DISPLAY_DELAY);
}

	
int main(void)
{
	HAL_Init();

	while (1) {
		/* Add application code here. */
	}
}
