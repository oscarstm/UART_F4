/*
 * dma_tx.h
 *
 *  Created on: Oct 8, 2023
 *      Author: oscar
 */

#ifndef DMA_TX_H_
#define DMA_TX_H_

#include "stm32f4xx.h"

void DMA2_USART1_TX(uint8_t *pBuffer, uint32_t sizedata);

#endif /* DMA_TX_H_ */
