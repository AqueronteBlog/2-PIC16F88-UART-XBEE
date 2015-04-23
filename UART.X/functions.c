/**
* @file		functions.c
* @author	Manuel Caballero
* @date 	26/2/2015
* @brief 	Funciones del sistema.
* \copyright
* 	AqueronteBlog@gmail.com
*
* Este archivo es propiedad intelectual del blog Aqueronte,
* cuya direccion web, es la siguiente:
*
* 	http://unbarquero.blogspot.com/
*
* Se permite cualquier modificacion del archivo siempre y cuando
* se mantenga la autoria del autor.
*/
#include "functions.h"

/**
 *  \brief     void conf_CLK (void)
 *  \details   Configura los relojes disponibles
 *                  - Reloj Principal: INTERNO 8 MHz.
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      26/2/2015
 */
void conf_CLK (void)
{
    OSCCONbits.IRCF0    =   1;      // Internal clock...
    OSCCONbits.IRCF1    =   1;
    OSCCONbits.IRCF2    =   1;      //...8 MHz.

    //OSCCONbits.IOFS     =   1;      // Frequency is stable
    //OSCCONbits.OSTS     =   1;      // Device is running from the primary system clock
}



/**
 *  \brief     void conf_IO (void)
 *  \details   Configura los pines del MCU a usar en este proyecto.
 *                  - Puerto B: LEDs y UART.
 *  			- RB3:	Salida.	  RED LED       ( RESISTOR 220 Ohms en serie)
 *  			- RB4:	Salida.	  GREEN LED     ( RESISTOR 220 Ohms en serie)
 *  			- RB2:	Salida.	  Rx            ( UART )
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      26/2/2015
 */
void conf_IO (void)
{
    TRISBbits.TRISB2    =   1;      // RB2 -> Rx
    //TRISBbits.TRISB5    =   0;      // RB5 -> Tx
    TRISBbits.TRISB3    =   0;      // RB3 -> RED LED
    TRISBbits.TRISB4    =   0;      // RB4 -> GREEN LED

    PORTBbits.RB3       =   0;      // Reset: RB3 = 0 ( RED LED OFF )
    PORTBbits.RB4       =   0;      // Reset: RB4 = 0 ( GREEN LED OFF )
}



/**
 *  \brief     void conf_UART (void)
 *  \details   Configura el módulo UART a 9600 Baud Rate.
 *
 * 		· Reloj UART: F_OSC ~ 8 MHz ( INTERNO ).
 *              · Alta Velocidad: BRGH = 1.
 *              · Rx interrupción ON.
 * 		· Buad Rate ~ 9600:
 *
 *     		Baud Rate = FOSC/(16(X + 1))
 *
 *                  9600 = 8·10^6/(16(X + 1))
 *
 * 		Por lo tanto:
 *
 *                  X ~ 51.08 = 51
 *
 *  \pre       Para ampliar información: DataSheet PIC16F88, apartado 11.0 ADDRESSABLE UNIVERSAL
 *             SYNCHRONOUS ASYNCHRONOUS RECEIVER TRANSMITTER (AUSART), concretamente en
 *             TABLE 11-6: INTRC BAUD RATES FOR ASYNCHRONOUS MODE (BRGH = 1)
 *             se pueden encontrar datos tabulados a distintas frecuencias.
 *
 *             La inicialización de la UART aconsejada se encuentra en el subcapítulo:
 *             18.7  Initialization del documento: Mid-Range Reference Manual.
 *
 *  \pre       El reloj interno debe estar a 8 MHz.
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      26/2/2015
 */
void conf_UART (void)
{
    SPBRG               =   51;     // BaudRate ~ 9600
    TXSTAbits.BRGH      =   1;      // High Speed
    PIE1bits.RCIE       =   1;      // Rx interrupt ON
    RCSTAbits.CREN      =   1;      // Continuos receive
    RCSTAbits.SPEN      =   1;      // Serial port ENABLE

    INTCONbits.PEIE     =   1;      // Peripheral Interrupt Enable
}