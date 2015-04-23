/**
* @file		variables.h
* @author	Manuel Caballero
* @date 	26/2/2015
* @brief 	Variables del sistema.
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
#include <stdint.h>

// CONFIG
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSCIO  /**< Oscillator Selection bits (INTRC oscillator; port I/O function on both RA6/OSC2/CLKO pin and RA7/OSC1/CLKI pin) */
#pragma config WDTE = OFF       /**< Watchdog Timer Enable bit (WDT disabled) */
#pragma config PWRTE = OFF      /**< Power-up Timer Enable bit (PWRT disabled) */
#pragma config MCLRE = ON       /**< RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR) */
#pragma config BOREN = ON       /**< Brown-out Reset Enable bit (BOR enabled) */
#pragma config LVP = OFF        /**< Low-Voltage Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming) */
#pragma config CPD = OFF        /**< Data EE Memory Code Protection bit (Code protection off) */
#pragma config WRT = OFF        /**< Flash Program Memory Write Enable bits (Write protection off) */
#pragma config CCPMX = RB0      /**< CCP1 Pin Selection bit (CCP1 function on RB0) */
#pragma config CP = OFF         /**< Flash Program Memory Code Protection bit (Code protection off) */

// CONFIG2
#pragma config FCMEN = ON       /**< Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled) */
#pragma config IESO = OFF       /**< Internal External Switchover bit (Internal External Switchover mode off) */



/**
 *  \brief     Variables Globales
 *  \details
 * 		- Buffer:     Variable encargada de almacenar el dato recibido
 *                            por la UART.
 */
uint8_t Buffer = 0;