#include <Servo.h> //includes the servo library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd1(0x27, 20,4);
LiquidCrystal_I2C lcd2(0x3F, 16, 2);

Servo In_servo;
Servo Out_servo;

#define Entry_out 2
#define Entry_in 3
#define Exit_in 4
#define Exit_out 5

#define car_1 8
#define car_2 9
#define car_3 10
#define car_4 11

int flag_entry = 0;
int flag_exit = 0;
int startTime;
int currentTime;
int exitStartTime;
int exitCurrentTime;
int preTotal;
int current_total;
int flag_buzzer=0;
int flag_exit_buzzer=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Entry_out, INPUT_PULLUP);
  pinMode(Entry_in, INPUT_PULLUP);
  pinMode(Exit_in, INPUT_PULLUP);
  pinMode(Exit_out, INPUT_PULLUP);

  pinMode(car_1, INPUT_PULLUP);
  pinMode(car_2, INPUT_PULLUP);
  pinMode(car_3, INPUT_PULLUP);
  pinMode(car_4, INPUT_PULLUP);
  pinMode(12,OUTPUT);
  In_servo.attach(6);
  Out_servo.attach(7);
  In_servo.write(90);
  Out_servo.write(90);

  lcd1.init();  
  lcd1.backlight();
  lcd2.init();  
  lcd2.backlight();
  lcd1.setCursor(0,1);
  lcd1.print("     WELCOME TO     ");
  lcd1.setCursor(0,2);
  lcd1.print("     Parking 2.0    ");
  delay(2000);
  lcd1.clear();
  lcd1.setCursor(0,2);
  lcd1.print("The New Horizon  ");
  lcd1.setCursor(0,3);
  lcd1.print("  of Parking  ");
  delay(2000);
  lcd1.clear();
  //lcd2.setCursor(0,1);
  //lcd2.print(" Tax displayed ");
}

void loop() {
  
  // put your main code here, to run repeatedly:
  int total = digitalRead(car_1) + digitalRead(car_2) + digitalRead(car_3) + digitalRead(car_4);
  Serial.println(total);
  delay(500);
  lcd1.setCursor (0,0);
  lcd1.print("   Have Slot: "); 
  lcd1.print(total);
  lcd1.print("    "); 
  
  lcd1.setCursor(0,1);
  lcd1.print("Parking1:");
  
  lcd1.setCursor(11,1);
  lcd1.print("Parking2:");
  
  lcd1.setCursor (0,2);
  if(digitalRead(car_1)==0){lcd1.print("S1:Fill ");}
       else{lcd1.print("S1:Empty");}
  
  lcd1.setCursor (10,2);
  if(digitalRead(car_3)==0){lcd1.print("S3:Fill ");}
       else{lcd1.print("S3:Empty");}
  
  lcd1.setCursor (0,3);
  if(digitalRead(car_2)==0){lcd1.print("S2:Fill ");}
       else{lcd1.print("S2:Empty");}
  lcd1.setCursor (10,3);
  if(digitalRead(car_4)==0){lcd1.print("S4:Fill ");}
       else{lcd1.print("S4:Empty");}
  if (digitalRead(Entry_out) == 0)
  {
    flag_entry = 1;
  }
  else if (digitalRead(Entry_in) == 0 && flag_entry == 1)
  {
    flag_entry = 0;
    startTime=millis();
    flag_buzzer=1;
    preTotal=total;
  }
  if(flag_buzzer==1){
    currentTime=millis();
    if((currentTime-startTime>5000)&&(preTotal==total)){
      digitalWrite(12,1);
    }
    else if(preTotal!=total){
      flag_buzzer=0; 
      digitalWrite(12,0);
    }
  }
  if (flag_entry == 1 && total >0){
    In_servo.write(180);
  }
  else{
    In_servo.write(90);
  }
  if (digitalRead(Exit_in) == 0)
  {
    flag_exit = 1;
  }
  if (digitalRead(Exit_out) == 0 && flag_exit == 1)
  {
    flag_exit = 0;
  }
  current_total = digitalRead(car_1) + digitalRead(car_2) + digitalRead(car_3) + digitalRead(car_4);
  if(current_total>total){
    exitStartTime=millis();
    flag_exit_buzzer=1;
  }
  if(flag_exit_buzzer==1){
    exitCurrentTime=millis();
    if((exitCurrentTime-exitStartTime>5000) && flag_exit_buzzer==1){
      digitalWrite(12,1);
    }
  }
  if(flag_exit==1){
    flag_exit_buzzer=0;
     digitalWrite(12,0);
    Out_servo.write(180);
  }
  else{
    Out_servo.write(90);
  }
}
