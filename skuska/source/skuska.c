/*
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    skuska.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

void delay(long long bound){
	long long i;
	for(i = 0; i < bound;i++);
}

int main(void) {

    /* Init board hardware. */
	gpio_pin_config_t pin_config =
	{
			kGPIO_DigitalOutput,1,
	};

	//gpio_pin_config_t pin_config2 =
	//{
	//		kGPIO_DigitalInput,1,
	//};

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

   	GPIO_PinInit(GPIOB, 0U ,&pin_config);
   	GPIO_PinInit(GPIOB, 1U ,&pin_config);
   	GPIO_PinInit(GPIOE, 21U ,&pin_config);
   	GPIO_PinInit(GPIOE, 20U ,&pin_config);
   	GPIO_PinInit(GPIOC, 0U ,&pin_config);
   	GPIO_PinInit(GPIOE, 16U ,&pin_config);
   	GPIO_PinInit(GPIOA, 1U ,&pin_config);
   	GPIO_PinInit(GPIOA, 2U ,&pin_config);
   	GPIO_PinInit(GPIOA, 12U ,&pin_config);
   	GPIO_PinInit(GPIOE, 25U ,&pin_config);
   	GPIO_PinInit(GPIOA, 13U ,&pin_config);
   	GPIO_PinInit(GPIOC, 9U ,&pin_config);
   	GPIO_PinInit(GPIOC, 8U ,&pin_config);
   	GPIO_PinInit(GPIOE, 31U ,&pin_config);
   	GPIO_PinInit(GPIOA, 5U ,&pin_config);
   	GPIO_PinInit(GPIOC, 4U ,&pin_config);
   	GPIO_PinInit(GPIOC, 6U ,&pin_config);
   	GPIO_PinInit(GPIOC, 7U ,&pin_config);
   	GPIO_PinInit(GPIOC, 5U ,&pin_config);
   	GPIO_PinInit(GPIOD, 6U ,&pin_config);
   	GPIO_PinInit(GPIOD, 7U ,&pin_config);

   	//GPIO_PinInit(GPIOE, 24U ,&pin_config2);
   	PORTE->PCR[24] = ( PORT_PCR_ISF(0x01)
   	                | PORT_PCR_IRQC(0x09)
   	                | PORT_PCR_MUX(0x01)
   	                | PORT_PCR_PE(0x01)
   	                | PORT_PCR_PS(0x01));

   	PORTE->PCR[21] = ( PORT_PCR_ISF(0x01)
   	                | PORT_PCR_IRQC(0x09)
   	                | PORT_PCR_MUX(0x01)
   	                | PORT_PCR_PE(0x01)
   	                | PORT_PCR_PS(0x01));

   	PORTE->PCR[16] = ( PORT_PCR_ISF(0x01)
   	                | PORT_PCR_IRQC(0x09)
   	                | PORT_PCR_MUX(0x01)
   	                | PORT_PCR_PE(0x01)
   	                | PORT_PCR_PS(0x01));

   	//IRQn_Type nieco = 1073741824;
   	//NVIC_EnableIRQ(nieco);

   	//GPIOB->PDDR = 0x2; 	  //  10 = 0x2
   	//GPIOA->PDDR = 0x3026; //  11 0000 0010 0110 = 0x3026
   	//GPIOC->PDDR = 0x3f1;  	  //  11 1111 0001 = 0x3f1
   	//GPIOD->PDDR = 0xc0;	  //  1100 0000 = 0xc0
   	//GPIOE->PDDR = 0x82110000;	  //  1000 0010 0001 0001 0000 0000 0000 0000 = 0x82110000

   	GPIOA->PDOR = 0;
   	GPIOB->PDOR = 0;
   	GPIOC->PDOR = 0;
   	GPIOD->PDOR = 0;
   	GPIOE->PDOR = 0;
   	PORTE->ISFR = 0;

   	while(1){
   		GPIOE->PDOR = 1048576 + 33554432;

   		GPIOA->PDOR =  34; //zelena na vedlajsej a cervena na vedaljsej
   		GPIOB->PDOR =  2; // zelena na rovnej trati
   		GPIOD->PDOR =  128; // aj tam aj sspat
   		GPIOC->PDOR =  640;
   		delay(5000000);

   	   	GPIOB->PDOR = 0;
   	   	GPIOC->PDOR = 0;

   	   	GPIOA->PDOR = 32;// CERVENE SVETLO
   	   	GPIOB->PDOR = 1; //oranzove vsade
   	   	GPIOC->PDOR = 544;



   	   	delay(3000000);

   	   	GPIOB->PDOR = 0;
   	   	GPIOC->PDOR = 512;

   	   	GPIOA->PDOR = 36;
   	   	GPIOD->PDOR = 192;
   	   	GPIOE->PDOR = 2148532224 + 33554432;

   	   	delay(5000000);

   	    GPIOA->PDOR = 4;
   	   	GPIOD->PDOR = 0;
   	   	GPIOC->PDOR = 560;

   	    delay(3000000);

   	    GPIOC->PDOR = 704;
   	    GPIOA->PDOR = 6;


   	    delay(5000000);

   	    GPIOA->PDOR = 2;
   	    GPIOC->PDOR = 656;
   	    GPIOB->PDOR = 1;
   	    GPIOE->PDOR = 1048576 + 33554432;


   	   	if ((PORTE->ISFR & 0x10000) || (PORTE->ISFR & 0x200000) || (PORTE->ISFR & 0x1000000)){
   	   	//0x10000 pri porte
   	    //0x200000  v rohu
   	   	//0x1000000 osamoteny pin
   	   		if ((PORTE->ISFR & 0x10000) && (PORTE->ISFR & 0x200000) && (PORTE->ISFR & 0x1000000)){
   	   			GPIOA->PDOR = 0;
   	   			delay(3000000);
   	   			GPIOA->PDOR = 36 + 4096;
   	   			GPIOB->PDOR = 0;
   	   			GPIOC->PDOR = 129 + 256;
   	   			GPIOE->PDOR = 0;
   	   		}
   	   		if (!(PORTE->ISFR & 0x10000) && (PORTE->ISFR & 0x200000) && (PORTE->ISFR & 0x1000000)){
   	   			GPIOA->PDOR = 0;
   	   		   	delay(3000000);
   	   		    GPIOA->PDOR = 36 + 4096;
   	   		   	GPIOB->PDOR = 0;
   	   		   	GPIOC->PDOR = 129 + 512;
   	   		   	GPIOE->PDOR = 0;
   	   		}
   	   		if ((PORTE->ISFR & 0x10000) && !(PORTE->ISFR & 0x200000) && (PORTE->ISFR & 0x1000000)){
   	   			GPIOA->PDOR = 0;
   	   		   	delay(3000000);
   	   		    GPIOA->PDOR = 36 + 4096;
   	   		   	GPIOB->PDOR = 0;
   	   		   	GPIOC->PDOR = 128 + 256;
   	   		   	GPIOE->PDOR = 1048576;
   	   		}
   	   		if (!(PORTE->ISFR & 0x10000) && !(PORTE->ISFR & 0x200000) && (PORTE->ISFR & 0x1000000)){
   	   			GPIOA->PDOR = 0;
   	   		   	delay(3000000);
   	   		    GPIOA->PDOR = 36 + 4096;
   	   		   	GPIOB->PDOR = 0;
   	   		   	GPIOC->PDOR = 128 + 512;
   	   		   	GPIOE->PDOR = 1048576;
   	   			GPIOD->PDOR = 128;
   	   		}
   	   		if ((PORTE->ISFR & 0x10000) && (PORTE->ISFR & 0x200000) && !(PORTE->ISFR & 0x1000000)){
   	   			GPIOA->PDOR = 0;
   	   			delay(3000000);
   	   			GPIOA->PDOR = 36;
   	   			GPIOB->PDOR = 0;
   	   			GPIOC->PDOR = 129 + 256;
   	   			GPIOE->PDOR = 33554432;

   	   		}
   	   		if (!(PORTE->ISFR & 0x10000) && (PORTE->ISFR & 0x200000) && !(PORTE->ISFR & 0x1000000)){

   	   			GPIOA->PDOR = 0;
   	   			delay(3000000);
   	   			GPIOA->PDOR = 36;
   	   			GPIOB->PDOR = 0;
   	   			GPIOC->PDOR = 129 + 512;
   	   			GPIOE->PDOR = 2148532224 - 1048576 + 33554432;
   	   		}
   	   		if ((PORTE->ISFR & 0x10000) && !(PORTE->ISFR & 0x200000) && !(PORTE->ISFR & 0x1000000)){
   	   			GPIOA->PDOR = 0;
   	   			delay(3000000);
   	   			GPIOA->PDOR = 36 + 2;
   	   			GPIOB->PDOR = 0;
   	   			GPIOC->PDOR = 128 + 256;
   	   			GPIOE->PDOR = 33554432 + 1048576;
   	   		}
   	   		delay(10000000);
   	   		PORTE->ISFR = 0x1210000;
   	   	}
   	   	GPIOB->PDOR = 1;
   	   	delay(3000000);
   	}

//   	GPIO_WritePinOutput (GPIOB, 0U, 1);
//   	GPIO_WritePinOutput (GPIOB, 0U, 0);
   	//GPIOA->PDDR = 0xffffffff;
   	//GPIOA->PTOR = 0xffffffff;


    //PTB0 = 1;
    // LPUART0->PTA1=1;

    return 0 ;
}
