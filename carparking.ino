#include <LiquidCrystal.h>// initialize the library with the numbers of the interface pins
#include <Servo.h> //includes the servo library

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myservo1;

int ir_s1 = 2;
int ir_s2 = 4;

int Total = 5;
int Space;

int flag1 = 0;
int flag2 = 0;

void setup() {
pinMode(ir_s1, INPUT);
pinMode(ir_s2, INPUT);
  
myservo1.attach(3);
myservo1.write(100);

lcd.begin(16, 2);  
lcd.setCursor (0,0);
lcd.print("  Car  Parking  ");
lcd.setCursor (0,1);
lcd.print("     System     ");
delay (2000);
lcd.clear();  

Space = Total;
}

void loop(){ 

if(digitalRead (ir_s1) == LOW && flag1==0){
if(Space>0){flag1=1;
if(flag2==0){myservo1.write(0); Space = Space-1;}
}else{
lcd.setCursor (0,0);
lcd.print(" Sorry not Space ");  
lcd.setCursor (0,1);
lcd.print("    Available    "); 
delay (1000);
lcd.clear(); 
}
}

if(digitalRead (ir_s2) == LOW && flag2==0){flag2=1;
if(flag1==0){myservo1.write(0); Space = Space+1;}
}

if(flag1==1 && flag2==1){
delay (1000);
myservo1.write(100);
flag1=0, flag2=0;
}

lcd.setCursor (0,0);
lcd.print("Total Space: ");
lcd.print(Total);

lcd.setCursor (0,1);
lcd.print("Have  Space: ");
lcd.print(Space);

// if(Space<5) { 
//   lcd.print('parking slots empty'); 
// }
}
