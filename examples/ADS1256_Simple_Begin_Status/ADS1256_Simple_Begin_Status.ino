// Arudino Sample Code to use ADS1256 library

// Samples per second testing

// http://www.ti.com/lit/ds/symlink/ads1256.pdf

// Written by Axel Sepulveda, May 2020

#include <ADS1256.h>
#include <SPI.h>

float clockMHZ = 7.68; // crystal frequency used on ADS1256
float vRef = 2.5; // voltage reference

// Initialize ADS1256 object
ADS1256 adc(clockMHZ,vRef,false); // RESETPIN is permanently tied to 3.3v

uint8_t ADCstatus;


void setup()
{
  Serial.begin(250000);
  
  Serial.println("Starting ADC");
  
  ADCstatus= adc.begin(); 

  Serial.print("ADC Started: ");
  
}

void loop()
{ 
  delay(1000);
  Serial.println(ADCstatus,BIN);
}
