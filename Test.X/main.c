/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC24 / dsPIC33 / PIC32MM MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - pic24-dspic-pic32mm : 1.65
        Device            :  dsPIC33EP32MC502
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.35
        MPLAB             :  MPLAB X v4.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#define FOSC    (7370000ULL)
#define FCY     (FOSC/2)
#include <libpic30.h>
#include "mcc_generated_files/mcc.h"

#define QUARTER_DUTY_STATE  0
#define HALF_DUTY_STATE     1
#define FULL_DUTY_STATE     2

#define FIFTY_HERTZ_STATE   0
#define ONE_K_HERTZ_STATE   1
#define TEN_K_HERTZ_STATE   2


/*
                         Main application
 */

void DutyStateMachine(unsigned char state)
{
    IO_RB12_SetHigh();
    IO_RB13_SetHigh();
    IO_RB14_SetHigh();
    IO_RB15_SetHigh();
    switch(state)
    {
        case QUARTER_DUTY_STATE:
            IO_RB15_SetLow();
            break;
        case HALF_DUTY_STATE:
            IO_RB14_SetLow();
            break;
        case FULL_DUTY_STATE:
            IO_RB13_SetLow();
            break;
    }
}

void FreqStateMachine(unsigned char state)
{
    IO_RB12_SetHigh();
    IO_RB13_SetHigh();
    IO_RB14_SetHigh();
    IO_RB15_SetHigh();
    switch(state)
    {
        case FIFTY_HERTZ_STATE:
            IO_RB15_SetLow();
            break;
        case ONE_K_HERTZ_STATE:
            IO_RB14_SetLow();
            break;
        case TEN_K_HERTZ_STATE:
            IO_RB13_SetLow();
            break;
    }
}

int ButtonPressed(uint16_t value)
{
    if(value == 0) return true;
    else return false;
}

int main(void)
{
    unsigned char duty_cycle_state = 0;
    unsigned char freq_cycle_state = 0;
    unsigned char duty_button_enabled = 1;
    unsigned char freq_button_enabled = 1;
    // initialize the device
    SYSTEM_Initialize();
    uint16_t duty_input_value;
    uint16_t freq_input_value;


    // Read RB5
    // When using interrupts, you need to set the Global Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalDisable();
    IO_RB12_SetHigh();
    IO_RB13_SetHigh();
    IO_RB14_SetHigh();
    IO_RB15_SetHigh();
    
    while (1)
    {
        duty_input_value = DUTY_INPUT_GetValue();
        freq_input_value = FREQ_INPUT_GetValue();
        
        if(ButtonPressed(DUTY_INPUT_GetValue()))
        {
            IO_RB12_SetHigh();
            if(duty_button_enabled)
            {
                duty_cycle_state++;
                if(duty_cycle_state == 3) duty_cycle_state = 0;
                DutyStateMachine(duty_cycle_state);
                duty_button_enabled = 0;
            }
        }
        else
        {
            duty_button_enabled = 1;
            IO_RB12_SetLow();
        }
        if(ButtonPressed(FREQ_INPUT_GetValue()))
        {
            if(freq_button_enabled)
            {
                freq_cycle_state++;
                if(freq_cycle_state == 3) freq_cycle_state = 0;
                FreqStateMachine(freq_cycle_state);
                freq_button_enabled = 0;
            }
        }
        else
        {
            freq_button_enabled = 1;
            IO_RB12_SetLow();
        }
        __delay_ms(50);
    }
}
/**
 End of File
*/