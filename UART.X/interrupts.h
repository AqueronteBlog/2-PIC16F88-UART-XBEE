/**
* @file		interrupts.h
* @author	Manuel Caballero
* @date 	26/2/2015
* @brief 	Variables de las rutinas de interrupción.
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


// DEFINICIONES
#define LED1    0x30               /**< LED1 = LED ROJO */


// VARIABLES EXTERNAS
extern uint8_t  Buffer;