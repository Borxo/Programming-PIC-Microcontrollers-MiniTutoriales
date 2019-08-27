/*
 * Programa: Timer0_Contador. 
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
#define _XTAL_FREQ 1000000

//Librerias//
#include <xc.h>

void main (void)
{
    //Configuración de los Puertos//
    TRISA=0xFF;                 //Puerto A como Entradas.
    TRISC=0x00;                 //Puerto C como Salidas.
    
    //Configuración Timer0//
    OPTION_REG=0b10111000;      // Reloj Externo,Flanco de Subida y
                                // 2X prescaler. 
    T0XCS=0;                    // Desactivado en el Modo contador.
    
    //Oscilador//
    OSCCON=0b01011000;          //1Mhz.
    
    while (1)
        {
            TMR0=250;           //Valor de inicio del Timer0.    
            TMR0IF=0;           //Se borra el flag desbordamiento del Timer0.
            while(TMR0IF==0);   //Se espera desbordamiento del Timer0.
            RC2^=1;             //Conmutación del Pin RC2. 
        }    
}
