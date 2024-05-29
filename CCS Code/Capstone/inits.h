

#ifndef CAPSTONE_INITS_H_
#define CAPSTONE_INITS_H_

#include "csl_uart.h"
#include "csl_general.h"




extern CSL_UartHandle    hUart;


extern CSL_Status UART_initiation(CSL_UartObj *  uartObj,Uint32 uartInstId,
        CSL_UartOpmode opmode);

extern Int16 UART_open( );
extern Int16 EVM5515_UART_putChar( char data );
extern Int16 EVM5515_UART_getChar( char* data );
//extern Int16 UART_str( char* data[5] );
extern Int16 I2S_opening( );
extern CSL_I2sHandle I2S_initiation(I2S_Instance		i2sInstNum,
					   I2S_OpMode		opMode,
					   I2S_ChanType 	chType);


#endif /* CAPSTONE_INITS_H_ */
