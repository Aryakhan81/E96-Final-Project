#include "fft.h"
#include <LiquidCrystal.h>

//LCD setup:
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int contrastPin = 6;

//Gloabl constants
const unsigned short pinin = A0;

//Global time variables
unsigned long startMillis;
unsigned long currentMillis;

//Global data variables
int i = -1;
int inputval;
int data[128];
const int delayTime = 15;

//Heartrate variables
double heart_freq = -1;
double bpm = -1;

//Write a function to learn the 
void setup() {
  //LCD display setup
  lcd.begin(16, 2);
  pinMode(contrastPin, OUTPUT);
  lcd.clear();

  Serial.begin(9600);
  startMillis = millis();
}

void loop() { 
  analogWrite(contrastPin, 70);

  //Update values
  i++;
  inputval = analogRead(pinin);
  data[i] = inputval;
  //currentMillis = millis() - startMillis;
  Serial.println(data[i]);

  //Check to see if we should perform an analysis and reset the data
  if(i == 127) {
    i = 0;
    float* arr = FFT(data, 128, 1000.0/delayTime);
    heart_freq = arr[0];
    
    bpm = 60 * heart_freq;

    //Now display this on the LCD here...
    lcd.clear();
    //prints the first line on the display
    lcd.setCursor(0, 0);
    lcd.print("Heart Beat:");
    //prints the second line on the display
    lcd.setCursor(0, 1);
    lcd.print(bpm);
    lcd.print(" BPM");
  }


  delay(delayTime);
}