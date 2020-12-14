#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)

#use fast_io(b)
#use fast_io(d)

int U[] = {0xff, 0x86, 0x7f, 0x7f, 0x7f, 0x86, 0xff, 0xff};
int B[] = {0xff, 0x00, 0x77, 0x77, 0x8f, 0xff, 0xff, 0xff};
int A[] = {0xff, 0x17, 0x57, 0x57, 0x0f, 0xff, 0xff, 0xff};
int selection(char s) {
   switch(s) {
      case 0: return 0x80; break;
      case 1: return 0x40; break;
      case 2: return 0x20; break;
      case 3: return 0x10; break;
      case 4: return 0x08; break;
      case 5: return 0x04; break;
      case 6: return 0x02; break;
      case 7: return 0x01; break;
   }
}

void writeMatrix(char letter[], int repeat) {
   int i, j, k;
   
   for(i = 1; i < repeat; i++) {
      for(j= 0; j < 10; j++) {
         for(k = 0; k < 8; k++) {
            output_d(selection(k));
            output_b(letter[k]);
            delay_ms(1);
         }
      }
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
   set_tris_d(0x00);
   output_b(0x00);
   output_d(0x00);
   while(1)
   {
      writeMatrix(U, 20);
      writeMatrix(B, 20);
      writeMatrix(A, 20);
   }

}
