#include &lt;xc.h&gt;
#include&lt;p18f4550.h&gt;
#define LCD_EN LATAbits.LA1
#define LCD_RS LATAbits.LA0
#define LCDPORT LATB

void lcd_delay(unsigned int time){
unsigned int j, i;
for(i=0; i&lt;time; i++){
for(j=0; j&lt;100; j++){}
}
}

void SendInstruction(unsigned char command){
LCD_RS=0;
LCDPORT=command;
LCD_EN=1;
lcd_delay(10);
LCD_EN=0;
lcd_delay(10);

}

void SendData(unsigned char LcdData){ LCD_RS=1;
LCDPORT=LcdData;
LCD_EN=1;
lcd_delay(10);
LCD_EN=0;
lcd_delay(10);
}

void initLCD(void){
ADCON1=0x0F;
TRISB=0x00;
TRISAbits.RA0=0;
TRISAbits.RA1=0;
SendInstruction(0x38); SendInstruction(0x06);
SendInstruction(0x0C); SendInstruction(0x01);
SendInstruction(0x80); }

unsigned char* string1=&quot;MicroEmbeded&quot;; unsigned char*
string2=&quot;PIC Kit&quot;;

void main(void) {
ADCON1=0x0F;
TRISB=0x00;
TRISAbits.RA0=0; TRISAbits.RA1=0;
SendInstruction(0x38); SendInstruction(0x06);
SendInstruction(0x0C); SendInstruction(0x01);
SendInstruction(0x80);

while(*string1){ SendData(*string1); string1++; }
SendInstruction(0xC0); while(*string2){
SendData(*string2); string2++; }
while(1);

return;
}
