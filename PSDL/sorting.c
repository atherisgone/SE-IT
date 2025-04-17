#include<xc.h>
#include <stdlib.h>
#include<pic18f4550.h>

int main(void){
    int i,j,t;
    int a[]={0x05,0x03,0x02,0x08,0x04};
    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(a[i]>a[i+1]){
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
    
    TRISB=0;
    TRISD=0;
    for(i=0;i<5;i++){
        
        PORTD=a[i];
        for(int n=0;n<1000;n++){
            for(int k=0;k<100;k++){

            }
        }
    }
}