#include "stm32f4xx.h"

#include "clk_user.h"
#include "delay_user.h"
#include "usart_user.h"
#include "polling_user.h"
#include "dma_usart.h"
#include "dma_tx.h"

uint8_t x[14] = { 'H', 'e', 'l', 'l', 'o',' ','W', 'o','r','l','d','!','\r', '\n' };
uint8_t y[4] = { 'H', 'i','\r', '\n' };

int main(void) {
	clk_user();
	USART1_Init();
	DMA2_USART1_Init();

	DMA2_USART1_TX(x, 32);

	while (1) {
		USART1_Write(y, 4);
		delay(9000);
	}

}

