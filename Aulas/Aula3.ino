    
    
    // Hello World no display \\

#include <LiquidCrystal.h>

//              D15,RX2,TX2,D18,D19,D21,D23
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  lcd.setCursor(0, 1);
  lcd.print("World");
}

void loop() {
  // put your main code here, to run repeatedly:
}



    // Contador com botão \\

#include <LiquidCrystal.h>

LiquidCrystal lcd(19, 23, 18, 17, 16, 15);
void setup() {
  pinMode(5, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Número");
  lcd.setCursor(0, 1);
}

int num = 0;
int val;

void loop() {
  val = digitalRead(5);
  
  if (val == LOW)
  {
    num++;  
    delay(200);                                                                                                                                                                                                                        
  }
  lcd.clear();
  lcd.print(num);

}



    // Special Characters no display \\

#include <LiquidCrystal.h>

//              D15,RX2,TX2,D18,D19,D21,D23
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

byte customChar[] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Special");
  lcd.setCursor(2,2);
  lcd.print("Characters");
  lcd.createChar(0, customChar);  
  lcd.setCursor(13, 1);
  lcd.write(byte(0));

}

void loop() {
}



    // flechas indo e voltando \\

#include <LiquidCrystal.h>

//              D15,RX2,TX2,D18,D19,D21,D23
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

byte arrow[8] = {
  0b00000,
  0b00100,
  0b00010,
  0b11101,
  0b00010,
  0b00100,
  0b00000,
  0b00000
};

byte leftArrow[8] = {
  0b00000,
  0b00100,
  0b01000,
  0b10111,
  0b01000,
  0b00100,
  0b00000,
  0b00000
};

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.createChar(0, arrow); 
  lcd.createChar(1, leftArrow); 
}

void loop() {
  int i, j;

  for(i = 0, j = 15; i < 16; i++, j--)
  {
    lcd.setCursor(i, 0);
    lcd.write(byte(0));
    
    lcd.setCursor(j, 1);
    lcd.write(byte(1));
    
    delay(200);
    lcd.clear();
    }
}

