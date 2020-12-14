#include <16F877A.h>
#device ADC=16

#fuses HS, NOWDT, NOPROTECT, NOLVP

#use delay(crystal=4000000)

#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7)

#use fast_io(b)
#use fast_io(c)

unsigned int8 x;


void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);   
   setup_ccp1(CCP_OFF);
   setup_ccp2(CCP_OFF);
   
   printf("Get 1-8");
   x = getchar();
   
   printf(x);
   putc(x);
   
   
   while(TRUE)
   {
   }

}


