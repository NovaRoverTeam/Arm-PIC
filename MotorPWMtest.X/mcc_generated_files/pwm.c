
/**
  PWM Generated Driver API Source File 

  @Company
    Microchip Technology Inc.

  @File Name
    pwm.c

  @Summary
    This is the generated source file for the PWM driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for driver for PWM. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - pic24-dspic-pic32mm : 1.65
        Device            :  dsPIC33EP32MC502
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.35
        MPLAB 	          :  MPLAB X v4.20
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "pwm.h"

/**
  Section: Driver Interface
*/


void PWM_Initialize (void)
{
    // PCLKDIV 1; 
    PTCON2 = 0x0;
    // PTPER 5000; 
    PTPER = 0x1388;
    // SEVTCMP 0; 
    SEVTCMP = 0x0;
    // MDC 0; 
    MDC = 0x0;
    // CHOPCLK 0; CHPCLKEN disabled; 
    CHOP = 0x0;
    // PWMKEY 0; 
    PWMKEY = 0x0;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; DTCP disabled; 
    PWMCON1 = 0x0;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; DTCP disabled; 
    PWMCON2 = 0x0;
    // MDCS Primary; FLTIEN disabled; CAM Edge Aligned; DTC Positive dead time for all Output modes; TRGIEN disabled; XPRES disabled; ITB Master; IUE disabled; CLIEN disabled; MTBS disabled; DTCP disabled; 
    PWMCON3 = 0x0;
    //FLTDAT PWM1L Low, PWM1H Low; SWAP disabled; OVRENH disabled; PENL disabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM1L Low, PWM1H Low; OVRDAT PWM1L Low, PWM1H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON1, 0x8000, &PWMKEY);
    //FLTDAT PWM2L Low, PWM2H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM2L Low, PWM2H Low; OVRDAT PWM2L Low, PWM2H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON2, 0xC000, &PWMKEY);
    //FLTDAT PWM3L Low, PWM3H Low; SWAP disabled; OVRENH disabled; PENL enabled; PMOD Complementary Output Mode; OVRENL disabled; OSYNC disabled; POLL disabled; PENH enabled; CLDAT PWM3L Low, PWM3H Low; OVRDAT PWM3L Low, PWM3H Low; POLH disabled; 
    __builtin_write_PWMSFR(&IOCON3, 0xC000, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD Fault input is disabled; FLTSRC FLT32; 
    __builtin_write_PWMSFR(&FCLCON1, 0xFB, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM2H, PWM2L pins to FLTDAT values- Latched; FLTSRC FLT32; 
    __builtin_write_PWMSFR(&FCLCON2, 0xF8, &PWMKEY);
    //FLTPOL disabled; CLPOL disabled; CLSRC FLT1; CLMOD disabled; FLTMOD PWM3H, PWM3L pins to FLTDAT values- Latched; FLTSRC FLT32; 
    __builtin_write_PWMSFR(&FCLCON3, 0xF8, &PWMKEY);
    // PDC1 5000; 
    PDC1 = 0x1388;
    // PDC2 7500; 
    PDC2 = 0x1D4C;
    // PDC3 0; 
    PDC3 = 0x0;
    // PHASE1 0; 
    PHASE1 = 0x0;
    // PHASE2 0; 
    PHASE2 = 0x0;
    // PHASE3 0; 
    PHASE3 = 0x0;
    // DTR1 0; 
    DTR1 = 0x0;
    // DTR2 0; 
    DTR2 = 0x0;
    // DTR3 0; 
    DTR3 = 0x0;
    // ALTDTR1 0; 
    ALTDTR1 = 0x0;
    // ALTDTR2 0; 
    ALTDTR2 = 0x0;
    // ALTDTR3 0; 
    ALTDTR3 = 0x0;
    // TRGCMP 0; 
    TRIG1 = 0x0;
    // TRGCMP 0; 
    TRIG2 = 0x0;
    // TRGCMP 0; 
    TRIG3 = 0x0;
    // TRGDIV 1; TRGSTRT 0; 
    TRGCON1 = 0x0;
    // TRGDIV 1; TRGSTRT 0; 
    TRGCON2 = 0x0;
    // TRGDIV 1; TRGSTRT 0; 
    TRGCON3 = 0x0;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON1 = 0x0;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON2 = 0x0;
    // BPLL disabled; BPHH disabled; BPLH disabled; BCH disabled; FLTLEBEN disabled; PLR disabled; CLLEBEN disabled; BCL disabled; PLF disabled; PHR disabled; BPHL disabled; PHF disabled; 
    LEBCON3 = 0x0;
    // LEB 0; 
    LEBDLY1 = 0x0;
    // LEB 0; 
    LEBDLY2 = 0x0;
    // LEB 0; 
    LEBDLY3 = 0x0;
    // CHOPLEN disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; 
    AUXCON1 = 0x0;
    // CHOPLEN disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; 
    AUXCON2 = 0x0;
    // CHOPLEN disabled; CHOPHEN disabled; BLANKSEL No state blanking; CHOPSEL No state blanking; 
    AUXCON3 = 0x0;
    

    // SYNCOEN disabled; SEIEN disabled; SESTAT disabled; SEVTPS 1; SYNCSRC SYNCI1; SYNCEN disabled; PTSIDL disabled; PTEN enabled; EIPU disabled; SYNCPOL disabled; 
    PTCON = 0x8000;
}



/**
 End of File
*/
