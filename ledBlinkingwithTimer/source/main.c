#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)
#use fast_io(b)

int i=0;

/* Timer interrupt function */
#int_timer0
void timer0interrupt() {
   set_timer0(60);
   i++;
   
   if(i==50) output_high(pin_b0);
   if(i==100) {
      output_low(pin_b0);
      i=0;
   }
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
   output_b(0x00);
   
   /*Timer 1 Interrupt enabled. */
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   set_timer0(60);
   enable_interrupts(INT_timer0);
   enable_interrupts(GLOBAL);
   while(TRUE) {
      output_high(pin_b1);
      delay_ms(50);
      output_low(pin_b1);
      delay_ms(50);
   }

}
