#include "fft.h"

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
  Serial.begin(9600);
  startMillis = millis();
}

void loop() {
  
  //Update values
  i++;
  inputval = analogRead(pinin);
  data[i] = inputval;
  currentMillis = millis() - startMillis;

  //Check to see if we should perform an analysis and reset the data
  if(i == 127) {
    i = 0;
    float* arr = FFT(data, 128, 1000.0/delayTime);
    heart_freq = arr[0];
    
    bpm = 60 * heart_freq;
    //Now display this on the LCD here...
  }


  delay(delayTime);
}