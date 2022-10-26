/*
 * File:   newmain.c
 * Author: MOHAMED MOUNIR MOHAMED
 *
 * Created on December 12, 2021, 7:39 PM
 */

#include <xc.h>
#include "config.h"
void main(void) {
    TRISB = 0x00; // set all pins in port b to be output
    PORTB = 0x00; // Clear All port b Pins
    TRISD = 0x00;  // set all pins in port d to be output
    PORTD = 0x00; // Clear All port d Pins
    
    //--[Counter Mode ]--
    TMR1 = 0x00;// Clear The TMR1 Register    
    TMR1CS = 1; // Select The Clock Source: External Pin !
    T1SYNC = 0; //Synchronize external clock input
    T1OSCEN = 0; // Oscillator is shut-off
    T1CKPS0 = 0; //Set The Pre-scaler To 1:1
    T1CKPS1 = 0;
    TMR1ON = 1; // Turn On Timer1 Module

unsigned char segments_code[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
unsigned char counter=0;
unsigned char segments_code1[10] = {0xFC,0x60,0xDA,0xF2};
unsigned char counter1=0;
while (1)
{
    if (TMR1<31)
    {
            PORTB = segments_code[counter];
            PORTD = segments_code1[counter1];
            counter=TMR1%10;
            counter1=TMR1/10;
            
    }
    }
    return;
}