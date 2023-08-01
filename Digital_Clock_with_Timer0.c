
// Lcd Pins
sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D7 at RB5_bit;

// Pin direction
sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB5_bit;



char time[14]= "hh:mm:ss";     //hh:mm:ss(end)
              //123456789
char date[14]= "dd:mm:yy";

                              

int sec = 55, min = 59, hrs = 23;
int day = 7, mon=4, year=1;
int overflows = 0;
//const colon=time[11],time[8],date[11],date[8];

void blink_colon(){
     while(1){
              time[2]=":";
              delay_ms(250);
              time[2]=" ";
              delay_ms(250);
     }
}
void set_time_string(){
      time[7] = sec%10 + 48;
      time[6] = sec/10 + 48;

      time[4] = min%10 + 48;
      time[3] = min/10 + 48;

      time[1] = hrs%10 + 48;
      time[0] = hrs/10 + 48;
      


}

void set_date_string(){
        date[7] = day%10+48;
        date[6] = day/10+48;
        
        date[4] = mon%10+48;
        date[3] = mon/10+48;
                
        date[1] = year%10+48;
        date[0] = year/10+48;
        

}

void set_time(){
     if(sec==60){
         min++;
         sec = 0;
     }
     if(min==60){
         hrs++;
         min = 0;
     }
     if(hrs==24){
         day++;
         hrs = 0;
     }
     if(day==30){
         mon++;
         day=0;
     }
     if (mon==12){
        year++;
        mon=0;
     }

}

void initialize_code(){
     
     Lcd_Init();
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Cmd( _LCD_CLEAR );
     Lcd_Out(1,1, "Time");
     Lcd_Out(2,1, "Date");

     T0CS_bit = 0;    // Set the clock source to internal clock cycle
     PSA_bit = 0;     // Assign the pre-scaler to Timer0
     PS0_bit = 1;     // Assign pre-scaler as 256
     PS1_bit = 1;
     PS2_bit = 1;

     TMR0 = 190;
     TMR0IF_bit = 0;
     TMR0IE_bit = 1;
     GIE_bit = 1;
     
     TRISC=1;
}

void interrupt(){
    if(TMR0IF_bit == 1){
         overflows++;
         if(overflows ==16){             // including the partial overflow it is required to complete 16 overflows for a 1 s period
               sec++;
               overflows = 0;
               TMR0 = 190;
         }
         TMR0IF_bit = 0;
    }
}



void main() {
     initialize_code();
     while(1){
          if(PORTC.B0==0){
               hrs++;
               }
          if(PORTC.B1==0){
               hrs--;
               }
          if(PORTC.B2==0){
               min++;
          }
          if(PORTC.B3==0){
               min--;
          }
          set_time();
          set_time_string();
          set_date_string();
          Lcd_out(1,1,"TIME:");
          Lcd_Out(1,6,time);
          Lcd_out(2,1,"DATE:");
          Lcd_Out(2,6,date);
     }

}