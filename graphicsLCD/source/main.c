#include <16F877A.h>
#device ADC=16
#use delay(crystal=4000000)
#include <HDM64GS12.c>
#include <graphics.c>

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O



char text1[] = "KSU";
char text2[] = "University";
int i, x1, x2, y1, y2;

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED, 0, 1);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   glcd_init(ON);
   
   while(TRUE)
   {
   glcd_init(ON);
   glcd_text57(39,5, text1, 2, ON);
   glcd_text57(5,30, text2, 2, ON);
   delay_ms(2000);
   glcd_init(ON);
   glcd_line(5, 0, 80, 0, ON);
   glcd_line(5, 50, 80, 50, ON);
   delay_ms(2000);
   glcd_init(ON);
   delay_ms(20);
   }

}


