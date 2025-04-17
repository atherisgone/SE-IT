#include &lt;xc.h&gt;
#include&lt;pic18f4550.h&gt;
#define Buzzer LATAbits.LATA5
unsigned int count=0;
void interrupt Timer1_ISR(){
if(TMR1IF==1){
TMR1L=0x20;
TMR1H=0xD1;
count++;
if(count&gt;=1000){
Buzzer=~Buzzer;
count=0;
}
TMR1IF =0;
}
}
void main(void) {

TRISB=0;
TRISAbits.TRISA5=0;

GIE=1;
PEIE=1;
TMR1IE=1;
TMR1IF=0;
T1CON=0x20;
TMR1L=0x20;
TMR1H=0xD1;
TMR1ON=1;
while(1);
return;
}

/*Steps to perform the buzzer on off in MPLAB
1.Create an empty folder on Desktop.
2. Create a New Project in MPLAB X IDE
 Open MPLAB X IDE.
 Go to File → New Project.
 Select Standalone Project.
 Choose your PIC Microcontroller (e.g., PIC16F877A).
 Select XC8 Compiler. And browse the path
 Click Finish.
3. Write the Buzzer Control Code
 In MPLAB X, open main.c and write the following code:
4. Compile the Code
 Click on the Build Project button (hammer icon) to compile the code.
 Ensure there are no errors.
 Right click on Your project,go to Properties ,choose XC8 linker .

 Then select option category as additional options then unlock and choose codeoffset as
“800” click on apply and ok.
5. Connect the Buzzer to the Microcontroller

 Open PICLoader with Run as Administrator
 In program go to settings choose COM3 port and click ok.
 Then click Break firmware and click book loader mode
 After this,load you Hex file
 Then perform write operation and click on RESET button on PIC18F4550 kit.

6. Test the Buzzer*/
