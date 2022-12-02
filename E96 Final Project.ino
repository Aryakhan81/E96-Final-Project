// #include "fft.h"
// #include <LiquidCrystal.h>

// //LCD setup:
// const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// int contrastPin = 6;

// //Gloabl constants
// const unsigned short pinin = A0;

// //Global time variables
// unsigned long startMillis;
// unsigned long currentMillis;

// //Global data variables
// int i = -1;
// int inputval;
// int data[256] = {
// 560, 
// 583, 
// 574, 
// 575, 
// 556, 
// 435, 
// 548, 
// 648, 
// 602, 
// 584, 
// 579, 
// 570, 
// 563, 
// 562, 
// 555, 
// 551, 
// 540, 
// 527, 
// 514, 
// 499, 
// 479, 
// 458, 
// 439, 
// 464, 
// 503, 
// 538, 
// 561, 
// 571, 
// 576, 
// 589, 
// 582, 
// 586, 
// 579, 
// 578, 
// 576, 
// 579, 
// 579, 
// 584, 
// 585, 
// 586, 
// 587, 
// 579, 
// 584, 
// 582, 
// 581, 
// 580, 
// 587, 
// 581, 
// 577, 
// 580, 
// 578, 
// 583, 
// 561, 
// 545, 
// 544, 
// 562, 
// 572, 
// 582, 
// 582, 
// 546, 
// 435, 
// 625, 
// 650, 
// 601, 
// 579, 
// 571, 
// 567, 
// 560, 
// 559, 
// 554, 
// 551, 
// 545, 
// 531, 
// 521, 
// 497, 
// 472, 
// 452, 
// 450, 
// 480, 
// 517, 
// 546, 
// 566, 
// 578, 
// 587, 
// 590, 
// 587, 
// 586, 
// 585, 
// 582, 
// 576, 
// 578, 
// 577, 
// 575, 
// 581, 
// 576, 
// 578, 
// 578, 
// 581, 
// 583, 
// 578, 
// 580, 
// 581, 
// 582, 
// 581, 
// 581, 
// 552, 
// 546, 
// 549, 
// 572, 
// 574, 
// 583, 
// 579, 
// 515, 
// 481, 
// 664, 
// 641, 
// 601, 
// 584, 
// 575, 
// 567, 
// 563, 
// 558, 
// 549, 
// 543, 
// 534, 
// 525, 
// 507, 
// 483, 
// 462, 
// 444, 
// 454, 
// 486, 
// 527, 
// 548, 
// 566, 
// 574, 
// 577, 
// 582, 
// 578, 
// 581, 
// 583, 
// 589, 
// 582, 
// 580, 
// 573, 
// 576, 
// 572, 
// 576, 
// 570, 
// 577, 
// 571, 
// 572, 
// 569, 
// 571, 
// 568, 
// 570, 
// 575, 
// 575, 
// 572, 
// 564, 
// 546, 
// 545, 
// 549, 
// 571, 
// 581, 
// 582, 
// 567, 
// 477, 
// 509, 
// 659, 
// 617, 
// 593, 
// 582, 
// 574, 
// 568, 
// 558, 
// 556, 
// 552, 
// 545, 
// 538, 
// 528, 
// 504, 
// 484, 
// 461, 
// 445, 
// 458, 
// 497, 
// 530, 
// 556, 
// 568, 
// 575, 
// 576, 
// 580, 
// 575, 
// 579, 
// 574, 
// 574, 
// 576, 
// 577, 
// 581, 
// 581, 
// 580, 
// 577, 
// 580, 
// 578, 
// 575, 
// 578, 
// 576, 
// 573, 
// 573, 
// 574, 
// 578, 
// 574, 
// 571, 
// 568, 
// 553  
// };
// const int delayTime = 15;

// //Heartrate variables
// double heart_freq = -1;
// double bpm = -1;

// //Write a function to learn the 
// void setup() {
//   //LCD display setup
//   lcd.begin(16, 2);
//   pinMode(contrastPin, OUTPUT);
//   lcd.clear();

//   Serial.begin(9600);
//   startMillis = millis();
// }

// void loop() { 
//   analogWrite(contrastPin, 70);

//   //Update values
//   i++;
//   inputval = analogRead(pinin);
//   //data[i] = inputval;
//   currentMillis = millis() - startMillis;
//   //Serial.println(data[i]);

//   //Check to see if we should perform an analysis and reset the data
//   if(i == 255) {
//     i = 0;
//     heart_freq = Approx_FFT(data, 256, 1000.0/delayTime);
//     //heart_freq = arr[0];
    
//     bpm = 60 * heart_freq;

//     //Now display this on the LCD here...
//     lcd.clear();
//     //prints the first line on the display
//     lcd.setCursor(0, 0);
//     lcd.print("Heart Beat:");
//     //prints the second line on the display
//     lcd.setCursor(0, 1);
//     lcd.print(bpm);
//     lcd.print(" BPM");
//     Serial.println(bpm);
//   }

// double data[128] = {
// 560, 
// 583, 
// 574, 
// 575, 
// 556, 
// 435, 
// 548, 
// 648, 
// 602, 
// 584, 
// 579, 
// 570, 
// 563, 
// 562, 
// 555, 
// 551, 
// 540, 
// 527, 
// 514, 
// 499, 
// 479, 
// 458, 
// 439, 
// 464, 
// 503, 
// 538, 
// 561, 
// 571, 
// 576, 
// 589, 
// 582, 
// 586, 
// 579, 
// 578, 
// 576, 
// 579, 
// 579, 
// 584, 
// 585, 
// 586, 
// 587, 
// 579, 
// 584, 
// 582, 
// 581, 
// 580, 
// 587, 
// 581, 
// 577, 
// 580, 
// 578, 
// 583, 
// 561, 
// 545, 
// 544, 
// 562, 
// 572, 
// 582, 
// 582, 
// 546, 
// 435, 
// 625, 
// 650, 
// 601, 
// 579, 
// 571, 
// 567, 
// 560, 
// 559, 
// 554, 
// 551, 
// 545, 
// 531, 
// 521, 
// 497, 
// 472, 
// 452, 
// 450, 
// 480, 
// 517, 
// 546, 
// 566, 
// 578, 
// 587, 
// 590, 
// 587, 
// 586, 
// 585, 
// 582, 
// 576, 
// 578, 
// 577, 
// 575, 
// 581, 
// 576, 
// 578, 
// 578, 
// 581, 
// 583, 
// 578, 
// 580, 
// 581, 
// 582, 
// 581, 
// 581, 
// 552, 
// 546, 
// 549, 
// 572, 
// 574, 
// 583, 
// 579, 
// 515, 
// 481, 
// 664, 
// 641, 
// 601, 
// 584, 
// 575, 
// 567, 
// 563, 
// 558, 
// 549, 
// 543, 
// 534, 
// 525, 
// 507
// };

#include "arduinoFFT.h"
#include <LiquidCrystal.h>

//LCD setup:
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int contrastPin = 6;
 
#define SAMPLES 128             //Must be a power of 2
#define SAMPLING_FREQUENCY 1000 //Hz, must be less than 10000 due to ADC
 
arduinoFFT FFT = arduinoFFT();
 
unsigned int sampling_period_us;
unsigned long microseconds;
 
double vReal[SAMPLES];
double vImag[SAMPLES];
 
void setup() {
    Serial.begin(9600);

    //LCD display setup
    lcd.begin(16, 2);
    pinMode(contrastPin, OUTPUT);
    lcd.clear();
 
    sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
}
 
void loop() {
    analogWrite(contrastPin, 70);
   
    /*SAMPLING*/
    for(int i=0; i<SAMPLES; i++)
    {
        microseconds = micros();    //Overflows after around 70 minutes!
     
        vReal[i] = analogRead(A0);
        Serial.println(vReal[i]);
        vImag[i] = 0;
     
        while(micros() < (microseconds + sampling_period_us)){
        }
    }
 
    /*FFT*/
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
 
    /*PRINT RESULTS*/
    //Serial.println(peak);     //Print out what frequency is the most dominant.

    //Now display this on the LCD here...
    lcd.clear();
    //prints the first line on the display
    lcd.setCursor(0, 0);
    lcd.print("Heart Beat:");
    //prints the second line on the display
    lcd.setCursor(0, 1);
    lcd.print(peak);
    lcd.print(" BPM");
 
    for(int i=0; i<(SAMPLES/2); i++)
    {
        /*View all these three lines in serial terminal to see which frequencies has which amplitudes*/
         
        // Serial.println((i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES, 1);
        // Serial.println(" ");
        //Serial.println(vReal[i], 1);    //View only this line in serial plotter to visualize the bins
    }
 
    delay(1000);  //Repeat the process every second OR:
    //while(1);       //Run code once
}




