#include<LiquidCrystal.h>
int ledPin = 2;
int tmpPin = A0;
int rs = 5;
int en = 6;
int d4 = 10        ;
int d5 = 11;
int d6 = 12;
int d7 = 13;
float val,mv,cel;
char * message = "Welcome To Our Smart Home";
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup()
{
  
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ledPin, OUTPUT);
  pinMode(tmpPin, INPUT);
}
void showLetters(int printStart, int startLetter)
{
  lcd.setCursor(printStart,0);
  for (int currentLetter = startLetter; currentLetter < strlen(message); currentLetter++)
  {
    lcd.print(message[currentLetter]);
  } 
  lcd.print(" ");
  delay(250); 
}

void loop(){
  val = analogRead(tmpPin);
  mv = ( val/1024.0)*5000; 
  cel = mv/10;
  Serial.println(cel);
  for (int printStart = 15; printStart >= 0; printStart--)  //scroll on from right
  {
    showLetters(printStart, 0); 
  }

  for (int letter = 1; letter <= strlen(message); letter++)  //scroll off to left
  {
    showLetters(0, letter);
  }

  delay(1000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("TEMP = ");
  lcd.print(cel);
  lcd.print((char)223);
  
  delay(1000);
  lcd.clear();
  
}
