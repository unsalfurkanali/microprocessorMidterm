#include <16F877A.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=8000000)
#define use_portb_lcd TRUE
#include <lcd.c>

char temp[] = "Temp =     ";
signed int16 sensorData;

void main(){
  setup_adc(ADC_CLOCK_INTERNAL);                 // ADC Module uses its internal oscillator
  setup_adc_ports(AN0);                          // Configure AN0 pin as analog
  set_adc_channel(0);                            // Select channel 0 (AN0)
  lcd_init();                                    // Initialize LCD module
  lcd_putc('\f');                                // Clear LCD
  while(TRUE){
    delay_ms(1000);
    sensorData = read_adc() * 0.489;                 // Read analog voltage and convert it to Kelvin (0.489 = 500/1023)
    temp[8]  = (sensorData / 100) % 10 + 48;
    temp[9]  = (sensorData / 10) % 10 + 48;
    temp[10] = sensorData % 10 + 48;
    lcd_gotoxy(1, 1);                            // Go to column 1 row 1
    printf(lcd_putc, temp);                  // Display message1
  }
}
 
// end of code.
