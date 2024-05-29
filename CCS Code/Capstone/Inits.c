
#include "ezdsp5535_i2s.h"
#include "csl_i2s.h"
#include "csl_uart.h"
#include "csl_general.h"
#include "ezdsp5535_i2s.h"

CSL_I2sHandle   hI2s2;

CSL_I2sHandle I2S_initiation(I2S_Instance		i2sInstNum,
					   I2S_OpMode		opMode,
					   I2S_ChanType 	chType)
{
	CSL_I2sHandle hI2s2;
	ioport volatile CSL_SysRegs		*sysRegs;

	hI2s2 = NULL;
	/* Check device is already in used*/
	if(i2sInstNum == I2S_INVALID)
	{
		return (NULL);
	}

	hI2s2 = &I2S_InstanceNum[i2sInstNum];

	if((i2sInstNum >= 0) & (i2sInstNum <= 3))
	{
		hI2s2->i2sNum    = i2sInstNum;
		hI2s2->chType    = chType;
		hI2s2->opMode    = opMode;
		hI2s2->firstRead = TRUE;

		sysRegs = (CSL_SysRegs *)CSL_SYSCTRL_REGS;


		/* Set Instance hardware registers*/
				hI2s2->hwRegs = (CSL_I2sRegs *)(CSL_I2S2_REGS);
				CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S2CG,
										CSL_SYS_PCGCR1_I2S2CG_ACTIVE);

				CSL_FINS(sysRegs->EBSR, SYS_EBSR_PPMODE,
										CSL_SYS_EBSR_PPMODE_MODE1);


		}

	hI2s2->configured = FALSE;
	return(hI2s2);
}






Int16 I2S_opening( )
{
    I2S_Config      hwConfig;
    Int16           result = 0;

    hI2s2 = I2S_open(I2S_INSTANCE2, I2S_POLLED, I2S_CHAN_STEREO);

    hwConfig.dataType           = I2S_STEREO_ENABLE;
    hwConfig.loopBackMode       = I2S_LOOPBACK_DISABLE;
    hwConfig.fsPol              = I2S_FSPOL_LOW;
    hwConfig.clkPol             = I2S_RISING_EDGE;
    hwConfig.datadelay          = I2S_DATADELAY_ONEBIT;
    hwConfig.datapack           = I2S_DATAPACK_ENABLE;
    hwConfig.signext            = I2S_SIGNEXT_DISABLE;
    hwConfig.wordLen            = I2S_WORDLEN_32;
    hwConfig.i2sMode            = I2S_SLAVE;
    hwConfig.FError             = I2S_FSERROR_ENABLE;
    hwConfig.OuError            = I2S_OUERROR_ENABLE;

    result += I2S_setup(hI2s2, &hwConfig);
    result += I2S_transEnable(hI2s2, TRUE);

    return result;
}






CSL_UartObj uartObj;
CSL_UartHandle    hUart;
ioport volatile CSL_SysRegs		*sysRegs;

CSL_Status UART_initiation(CSL_UartObj *  uartObj,Uint32 uartInstId,
                     CSL_UartOpmode opmode)
{
	CSL_Status status = CSL_SOK;

	if(NULL == uartObj)
	{
		return CSL_ESYS_INVPARAMS;
	}

    if(opmode ==  UART_OPMODE_OTHER)
    {
        return CSL_ESYS_INVPARAMS;
    }
   	/* Set the base address  */
	switch ( uartInstId)
	{
        case CSL_UART_INST_0:
   				uartObj->insId = uartInstId;
                uartObj->sysAddr = CSL_SYSCTRL_REGS;
                uartObj->uartRegs = CSL_UART_REGS;
                uartObj->opmode = opmode;
                break;
		default:
                uartObj->insId = CSL_UART_INST_INVALID;
                status = CSL_EUART_INVALID_INST_ID;
                break;
    }

    if(CSL_UART_INST_INVALID != uartObj->insId)
    {

        //Enable Master clock
        CSL_FINST(uartObj->sysAddr->PCGCR1,SYS_PCGCR1_SYSCLKDIS,ACTIVE);
        //Enable uart peripheral clock gating
        CSL_FINST(uartObj->sysAddr->PCGCR1,SYS_PCGCR1_UARTCG,ACTIVE);
        //Enable
        //Resetting UART  module
        CSL_FINS(sysRegs->PRCR, SYS_PRCR_PG3_RST, CSL_SYS_PRCR_PG3_RST_RST);
        //CSL_FINST(uartObj->sysAddr->PRCR, SYS_PRCR_PG4_RST,RST);

    }
    return status;
}


Int16 UART_open( ){

	   CSL_Status        status;
	    CSL_UartConfig 		    Config;

	    Config.DLL = 0x36;  // Set baud rate
	    Config.DLH = 0x00;

	    Config.FCR = 0x0000;            // Clear UART TX & RX FIFOs
	    Config.LCR = 0x0003;            // 8-bit words,
	                                    // 1 STOP bit generated,
	                                    // No Parity, No Stick paritiy,
	                                    // No Break control
	    Config.MCR = 0x0000;            // RTS & CTS disabled, Loopback mode disabled,Autoflow disabled
	    //Config.MCR = 0x0022; 			   // 100010, rts and CTS autoflow enable?


	    status = UART_initiation(&uartObj, CSL_UART_INST_0, UART_INTERRUPT); // sets PCGCR1
	    sysRegs = (CSL_SysRegs *)CSL_SYSCTRL_REGS;
	    CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S2CG, CSL_SYS_PCGCR1_I2S2CG_ACTIVE);

	    hUart = (CSL_UartHandle)&uartObj;
	    status |= UART_reset(hUart);
	    status |= UART_config(hUart,&Config);
	    status |= UART_resetOff(hUart);

	    CSL_SYSCTRL_REGS->EBSR &= ~0xF000;
	    CSL_SYSCTRL_REGS->EBSR |=  0x1000;
	}

Int16 EVM5515_UART_putChar( char data )
{
	UART_fputc(hUart, data, 0);

    return 0;
}


Int16 UART_str( char *data)
{

	UART_fgets(hUart, data, 4, 0);

    return 0;
}


Int16 EVM5515_UART_getChar( char* data )
{
	UART_fgetc(hUart, data, 0);

    return 0;
}
