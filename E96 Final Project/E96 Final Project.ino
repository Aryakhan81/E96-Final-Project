#include "arduinoFFT.h"
#include <LiquidCrystal.h>

//LCD setup:
//const int rs = 1, en = 2, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
int contrastPin = 9;

#define SAMPLES 128             //Must be a power of 2
#define SAMPLING_FREQUENCY 1000 //Hz, must be less than 10000 due to ADC

arduinoFFT FFT = arduinoFFT();

unsigned int sampling_period_us;
unsigned long microseconds;

double vReal[SAMPLES];
double vImag[SAMPLES];

void setup() {
    //Serial.begin(9600);

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
        //Serial.println(vReal[i]);
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

    //prints the second line on the display
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Heart Rate:");
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
