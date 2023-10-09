/*
 * polling_user.c
 *
 *  Created on: Oct 8, 2023
 *      Author: oscar
 */

#include "polling_user.h"

void USART1_Write(uint8_t *buffer, uint32_t nbytes) {
	int i;
	for (i = 0; i < nbytes; i++) {
		while (!(USART1->SR & (USART_SR_TXE))) {
			//
		}
		USART1->DR = buffer[i] & 0xFF;
	}

	while (!(USART1->SR & (USART_SR_TC))) {
		//
	}
	USART1->CR1 |= (USART_CR1_TCIE);
}
