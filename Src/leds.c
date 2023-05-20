//
// Created by Armin on 20-May-23.
//

#include "leds.h"

typedef struct
{
	GPIO_TypeDef* port;
	uint16_t pin;
} GPIO_Config;

GPIO_Config LedPorts[16] = {
		{GPIOD, GPIO_PIN_7},
		{GPIOD, GPIO_PIN_6},
		{GPIOD, GPIO_PIN_5},
		{GPIOD, GPIO_PIN_4},
		{GPIOD, GPIO_PIN_3},
		{GPIOE, GPIO_PIN_2},
		{GPIOE, GPIO_PIN_4},
		{GPIOE, GPIO_PIN_5},
		{GPIOE, GPIO_PIN_6},
		{GPIOE, GPIO_PIN_3},
		{GPIOF, GPIO_PIN_8},
		{GPIOF, GPIO_PIN_7},
		{GPIOF, GPIO_PIN_9},
		{GPIOG, GPIO_PIN_1},
		{GPIOG, GPIO_PIN_0},
		{GPIOD, GPIO_PIN_1}
};



void LedOut(uint16_t led) {
	for (int i = 0; i < 16; i++) {
		HAL_GPIO_WritePin(LedPorts[i].port, LedPorts[i].pin,
		                  (led & (1 << i)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	}
}



void InitLeds() {
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_3, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7 | GPIO_PIN_6 | GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_3 | GPIO_PIN_1, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_9, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1 | GPIO_PIN_0, GPIO_PIN_RESET);

	/*Configure GPIO pins : PE2 PE4 PE5 PE6 PE3 */
	GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

	/*Configure GPIO pins : PD7 PD6 PD5 PD4 PD3 PD1 */
	GPIO_InitStruct.Pin = GPIO_PIN_7 | GPIO_PIN_6 | GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_3 | GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	/*Configure GPIO pins : PF8 PF7 PF9 */
	GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_7 | GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

	/*Configure GPIO pins : PG1 PG0 */
	GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

	LedOut(0x0000);
}
