#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)

#use fast_io(b)
#use fast_io(c)

int i = 0;

#INT_CCP1
void increasing() {
   i++;
   if(i==10) i=0;
   output_b(i);
}

#INT_CCP2
void decreasing() {
   if(i==0) i=1;
   
   i--;
   output_b(i);
}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   
   set_tris_b(0x00);
   set_tris_c(0x07);
   
   output_b(0x00);
   
   enable_interrupts(INT_CCP1);
   enable_interrupts(INT_CCP2);
   enable_interrupts(GLOBAL);
   
   setup_ccp1(CCP_CAPTURE_RE);
   setup_ccp2(CCP_CAPTURE_RE);
   
   CCP_1_HIGH=0x00;
   CCP_1_LOW=0x00;
   
   CCP_2_HIGH=0x00;
   CCP_2_LOW=0x00;
   
   while(TRUE)
   {
   }

}


