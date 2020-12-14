#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)

#use fast_io(b)
#use fast_io(a)

int i=5;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   
   set_tris_a(0x03);
   set_tris_c(0x00);
   
   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   
   setup_timer_2(T2_DIV_BY_16, 120, 5);
   
   set_pwm1_duty(i);
   set_pwm2_duty(i*10);
   
   
   while(TRUE) {
   }

}


