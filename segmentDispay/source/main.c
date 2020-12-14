#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)
#use fast_io(b)

int i, j = 0;

/* Timer interrupt function */
#int_timer0
void timer0interrupt() {
   set_timer0(60);
   output_b(i);
   i++;
   if(i==9) i=0;

}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_b(0x00);
   set_tris_d(0x00);
   set_tris_c(0x80);
   output_b(0x00);
   output_d(0x00);
   
   /*Timer 1 Interrupt enabled. */
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   set_timer0(60);
   enable_interrupts(INT_timer0);
   enable_interrupts(GLOBAL);
   while(TRUE)
   {
     if(input(pin_c7)) {
         output_d(++j);
         if(j==9) j=0;
         while(input(pin_c7)) ;
     }
   }

}
