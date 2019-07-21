/*
 * Programa: Hola Mundo. 
 * Microcontrolador: PIC16F1936.
 * Autor: Borxo García.
 */

//Palabras de configuración
// CONFIG1
#pragma config FOSC = INTOSC    
#pragma config WDTE = OFF       
#pragma config PWRTE = OFF      
#pragma config MCLRE = OFF      
#pragma config CP = OFF         
#pragma config CPD = OFF        
#pragma config BOREN = OFF      
#pragma config CLKOUTEN = OFF   
#pragma config IESO = OFF      
#pragma config FCMEN = OFF      

// CONFIG2
#pragma config WRT = OFF        
#pragma config PLLEN = OFF       
#pragma config STVREN = OFF     
#pragma config BORV = LO        
#pragma config LVP = OFF        

//Velocidad del oscilador interno//
#define _XTAL_FREQ 4000000

//Librerias//
#include <xc.h>

void main (void)
{
    //Configuración de los Puertos//
    TRISA=0x00;
    
    //Oscilador//
    OSCCON=0b01101000; //4Mhz
    
    while(1)
    {
        RA2=0;
        __delay_ms(500);
        RA2=1;
        __delay_ms(500);
    }
}

