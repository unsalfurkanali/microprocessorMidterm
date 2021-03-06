#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)

#use fast_io(b)
#use fast_io(d)

#byte portb = 0x06

#define col1 pin_d0
#define col2 pin_d1
#define col3 pin_d2
#define row1 pin_d3
#define row2 pin_d4
#define row3 pin_d5

char tus=0;

char keypad_read() {
   output_d(0x00);
   
   output_high(row1);
   if(input(col1)) {
      delay_ms(20);
      tus = 1;
   }
   if(input(col2)) {
      delay_ms(20);
      tus = 2;
   }
   if(input(col3)) {
      delay_ms(20);
      tus = 3;
   }
   output_low(row1);
   
   output_high(row2);
   if(input(col1)) {
      delay_ms(20);
      tus = 4;
   }
   if(input(col2)) {
      delay_ms(20);
      tus = 5;
   }
   if(input(col3)) {
      delay_ms(20);
      tus = 6;
   }
   output_low(row2);
   
   output_high(row3);
   if(input(col1)) {
      delay_ms(20);
      tus = 7;
   }
   if(input(col2)) {
      delay_ms(20);
      tus = 8;
   }
   if(input(col3)) {
      delay_ms(20);
      tus = 9;
   }
   output_low(row3);
   
   return tus;
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
   set_tris_d(0x07);
   output_b(0x00);
   
   while(TRUE)
   {
      portb=keypad_read();
   }

}


