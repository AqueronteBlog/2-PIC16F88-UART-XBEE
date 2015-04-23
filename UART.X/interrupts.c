/**
* @file		interrupts.c
* @author	Manuel Caballero
* @date 	26/2/2015
* @brief 	Interrupciones del sistema.
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
#include "interrupts.h"


/**
 *  \brief     void ISR (void) interrupt service routine
 *  \details   Subrutina de interrupci�n. En caso de recibirse alg�n dato por
 *             la UART, se generar� un ainterrupci�n.
 *
 *             Se leer� el valor recibido por la UART y dependiendo del valor,
 *             se cambiar� el estado de los LEDs.
 *
 *             El flag de interrupci�n de Rx UART se pone a cero cuando se lee.
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      26/2/2015
 */
void interrupt ISR ( void )
{
    if ( PIR1bits.RCIF == 1 )       // �Ha llegado dato por la UART?
    {
        Buffer  =   RCREG;          // Se lee dato

        if ( Buffer == LED1)
            PORTBbits.RB3   =   ~PORTBbits.RB3;  // Toggle LED 1  ( Red LED )
        else
            PORTBbits.RB4   =   ~PORTBbits.RB4;  // Toggle LED 2  ( Green LED )
    }
}