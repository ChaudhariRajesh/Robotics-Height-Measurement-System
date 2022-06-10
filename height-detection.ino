

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,7,4,2);

int trigPin=A4;
int echoPin=A3;
int cm1;
int duration;
int temp;
int ldr1=A0;
int ldr2=A1;
int green_led=A2;
int red_led=A5;
int white_led=11;
float feet;
int RST=10;


void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(white_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(ldr1,INPUT);
  pinMode(ldr2,INPUT);  
  pinMode(ldr1,INPUT);
  
  digitalWrite(white_led,LOW);
  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,LOW);
  
  
  temp=0;
  digitalWrite(white_led,LOW);
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Automatic Height");
  lcd.setCursor(4,1);
  lcd.print("Detector");
  
  
}

void loop() 
{
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);

  Serial.println("1");
  duration=pulseIn(echoPin,HIGH);
  Serial.print("Duration=>");
  Serial.println(duration);

  cm1=((duration/29)/2);
  temp=temp+(duration%29);

  if(temp>29)
  {
    cm1+=1;
    temp-=29;
  }
  
  delay(500);
  
  Serial.print("CM=>");
  Serial.println(cm1);


  //lcd.setCursor(0,0);
  //lcd.print(cm1);
  delay(500); 
  Serial.println(A0);
  Serial.println(A1);

  if(digitalRead(A0)==HIGH && digitalRead(A1)==HIGH)
  {
      Serial.println("First");
    
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Automatic Height");
      lcd.setCursor(4,1);
      lcd.print("Detector");

  }
  else if(digitalRead(A0)==HIGH || digitalRead(A1)==HIGH)
  {
      Serial.println("Second");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Please Stand");
      lcd.setCursor(0,1);
      lcd.print("Properly !");

  }
  while(digitalRead(A0)==LOW && digitalRead(A1)==LOW)
  {
     Serial.println("Third");
    
    delay(2000);
    int temp1=206-cm1;

    feet=(temp1/30.48);
    
    
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(temp1);

    digitalWrite(green_led,LOW);
    digitalWrite(red_led,HIGH);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Your Height :");
    lcd.setCursor(0,1);
    lcd.print(temp1);
    lcd.setCursor(3,1);
    lcd.print("cm");
    lcd.setCursor(7,1);
    lcd.print(feet);
    lcd.setCursor(11,1);
    lcd.print("feet");
    
    //delay(5000);

//  digitalWrite(RST,HIGH);
  //  digitalWrite(green_led,HIGH);
    //digitalWrite(red_led,LOW);

  }
  //else
  {
    Serial.println ("4");

    digitalWrite(green_led,HIGH);
    digitalWrite(red_led,LOW);
    
  }
 
 
}


