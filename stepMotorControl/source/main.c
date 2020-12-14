#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)
#use fast_io(b)
#use fast_io(d)

#define forward pin_a0
#define back pin_a1

int fullstep[] = {0x09, 0x0c, 0x06, 0x03};

int i = 0, time = 400;
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
  set_tris_a(0x03);
  output_b(0x00);
   while(TRUE) {
      if(input(forward)) {
         output_b(fullstep[i]);
         while(input(forward));
         delay_ms(time);
         
         if(i==3) i=-1;
         i++;
      }
      
      if(input(back)) {
         if(i==0) i=4;
         output_b(fullstep[--i]);
         while(input(back));
         delay_ms(time);
      }
      
   
   }

}
