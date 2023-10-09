/*
 * polling_user.h
 *
 *  Created on: Oct 8, 2023
 *      Author: oscar
 */

#ifndef POLLING_USER_H_
#define POLLING_USER_H_

#include "stm32f4xx.h"

void USART1_Write(uint8_t *buffer, uint32_t nbytes);

#endif /* POLLING_USER_H_ */
