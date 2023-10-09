/*
 * dma_usart.c
 *
 *  Created on: Oct 8, 2023
 *      Author: oscar
 */

#include "dma_usart.h"

void DMA2_USART1_Init(void) {
	RCC->AHB1ENR |= (RCC_AHB1ENR_DMA2EN);

	DMA2_Stream7->CR &= ~(DMA_SxCR_EN);
	// memory to peripheral
	DMA2_Stream7->CR |= (DMA_SxCR_DIR_0);
	DMA2_Stream7->CR &= ~(DMA_SxCR_DIR_1);
	// level high
	DMA2_Stream7->CR &= ~(DMA_SxCR_PL_0);
	DMA2_Stream7->CR |= (DMA_SxCR_PL_1);
	// memory size 8 bit
	DMA2_Stream7->CR &= ~(DMA_SxCR_PSIZE_0);
	DMA2_Stream7->CR &= ~(DMA_SxCR_PSIZE_1);
	DMA2_Stream7->CR &= ~(DMA_SxCR_MSIZE_0);
	DMA2_Stream7->CR &= ~(DMA_SxCR_MSIZE_1);
	// peripheral memory fixed
	DMA2_Stream7->CR &= ~(DMA_SxCR_PINC);
	// memory increment
	DMA2_Stream7->CR |= (DMA_SxCR_MINC);
	//
	DMA2_Stream7->CR |= (DMA_SxCR_CIRC);
	// interrupt
	DMA2_Stream7->CR |= (DMA_SxCR_TCIE);
	DMA2_Stream7->CR |= (DMA_SxCR_HTIE);
	DMA2_Stream7->CR |= (DMA_SxCR_TEIE);
	// 4th channel
	DMA2_Stream7->CR &= ~(DMA_SxCR_CHSEL_0);
	DMA2_Stream7->CR &= ~(DMA_SxCR_CHSEL_1);
	DMA2_Stream7->CR |= (DMA_SxCR_CHSEL_2);
	// enable
	NVIC_EnableIRQ(DMA2_Stream7_IRQn);
}
