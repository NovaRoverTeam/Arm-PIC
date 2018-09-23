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

const uint16_t freq_period_array[3] = {0x8FF2, 0x732, 0xB8};
const uint16_t duty_cycle_table[3][3] = 
{
    {0x23FC, 0x47F8, 0x8FF2},
    {0x1CC, 0x399, 0x732},
    {0x2E, 0x5C, 0xB8}
};

void UpdatePWMStates(unsigned char duty_state, unsigned char freq_state)
{
    DUTY_25_SetLow();
    DUTY_50_SetLow();
    DUTY_100_SetLow();
    FREQ_50_SetLow();
    FREQ_1K_SetLow();
    FREQ_10K_SetLow();
    
    switch(duty_state){
        case QUARTER_DUTY_STATE:
            DUTY_25_SetHigh();
            switch(freq_state){
                case FIFTY_HERTZ_STATE:
                    FREQ_50_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0x8FF2);
                    PWM_DutyCycleSet(1, 0x23FC);
                    break;
                case ONE_K_HERTZ_STATE:
                    FREQ_1K_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0x732);
                    PWM_DutyCycleSet(1, 0x1CC);
                    break;
                case TEN_K_HERTZ_STATE:
                    FREQ_10K_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0xB8);
                    PWM_DutyCycleSet(1, 0x2E);
                    break;
            }
            break;
        case HALF_DUTY_STATE:
            DUTY_50_SetHigh();
            switch(freq_state){
                case FIFTY_HERTZ_STATE:
                    FREQ_50_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0x8FF2);
                    PWM_DutyCycleSet(1, 0x47F8);
                    break;
                case ONE_K_HERTZ_STATE:
                    FREQ_1K_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0x732);
                    PWM_DutyCycleSet(1, 0x399);
                    break;
                case TEN_K_HERTZ_STATE:
                    FREQ_10K_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0xB8);
                    PWM_DutyCycleSet(1, 0x5C);
                    break;
            }
            break;
        case FULL_DUTY_STATE:
            DUTY_100_SetHigh();
            switch(freq_state){
                case FIFTY_HERTZ_STATE:
                    FREQ_50_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0x8FF2);
                    PWM_DutyCycleSet(1, 0x8FF2);
                    break;
                case ONE_K_HERTZ_STATE:
                    FREQ_1K_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0x732);
                    PWM_DutyCycleSet(1, 0x732);
                    break;
                case TEN_K_HERTZ_STATE:
                    FREQ_10K_SetHigh();
                    PWM_PrimaryMasterPeriodSet(0xB8);
                    PWM_DutyCycleSet(1, 0xB8);
                    break;
            }
            break;
    }
    
    //PWM_DutyCycleSet(1, duty_cycle_table[freq_state, duty_state]);
    //PWM_PrimaryMasterPeriodSet(freq_period_array[freq_state]);
}

int ButtonPressed(uint16_t value)
{
    if(value == 0) return true;
    else return false;
}

int main(void)
{
    unsigned char duty_cycle_state = 0;
    unsigned char freq_state = 0;
    unsigned char duty_button_enabled = 1;
    unsigned char freq_button_enabled = 1;
    unsigned char pwm_has_changed = 1;
    // initialize the device
    SYSTEM_Initialize();

    // Read RB5
    // When using interrupts, you need to set the Global Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalDisable();
    
    while (1)
    {        
        if(ButtonPressed(DUTY_INPUT_GetValue()))
        {
            if(duty_button_enabled)
            {
                duty_cycle_state++;
                if(duty_cycle_state == 3) duty_cycle_state = 0;
                duty_button_enabled = 0;
                pwm_has_changed = 1;
            }
        }
        else duty_button_enabled = 1;
        
        if(ButtonPressed(FREQ_INPUT_GetValue()))
        {
            if(freq_button_enabled)
            {
                freq_state++;
                if(freq_state == 3) freq_state = 0;
                freq_button_enabled = 0;
                pwm_has_changed = 1;
            }
        }
        else freq_button_enabled = 1;
        if(pwm_has_changed)
        {
            UpdatePWMStates(duty_cycle_state, freq_state);
            pwm_has_changed = 0;
        }
        __delay_ms(50);
    }
}
/**
 End of File
*/