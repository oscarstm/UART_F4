/*
 * dma_tx.c
 *
 *  Created on: Oct 8, 2023
 *      Author: oscar
 */

#include "dma_tx.h"

void DMA2_USART1_TX(uint8_t *pBuffer, uint32_t sizedata) {
	DMA2_Stream7->NDTR = sizedata;
	DMA2_Stream7->M0AR = (uint32_t) pBuffer;
	DMA2_Stream7->PAR = (uint32_t) &USART1->DR;
	DMA2_Stream7->CR |= (DMA_SxCR_EN);
}

