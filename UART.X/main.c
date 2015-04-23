/**
* @file		main.c
* @author	Manuel Caballero
* @date 	26/2/2015
* @brief 	Archivo principal.
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
#include <xc.h>
#include <stdint.h>
#include "variables.h"
#include "functions.h"
#include "interrupts.h"

/**
 *  \brief     void main( void )
 *  \details   Este programa consiste en encender un LED rojo o un LED verde
 *             por medio del módulo UART.
 *
 *             Todas las acciones se realizarán en el servicio de interrupción
 *             de la UART.
 *
 *             Este programa se ha probado con un par de módulos XBee modelo
 *             XBee XB24-ZB ( uno Coordinator y el otro End Device ).
 * 
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      26/2/2015
 *  \pre       Este firmware está probado para el PIC16F88.
 *  \pre       El LED rojo estará conectado al pin RB3
 *             ( un resistor de 220 Ohms en serie ).
 *  \pre       El LED verde estará conectado al pin RB4
 *             ( un resistor de 220 Ohms en serie ).
 *
 *  \pre       MPLAB X IDE v2.30.
 *  \pre       Compiler XC8 v1.33.
 */
void main( void ) {

    conf_CLK    ();     // Configura Relojes
    conf_IO     ();     // Configura Pins
    conf_UART   ();     // Configura UART

    ei  ();             // enable interrupts
    
    while ( 1 );        // espera dato procedente de la UART
}

