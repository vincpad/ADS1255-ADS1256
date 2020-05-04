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

float sensor1;
long lastTime, currentTime, elapsedTime; 
int counter; 

void setup()
{
  Serial.begin(115200);
  
  Serial.println("Starting ADC");

  // start the ADS1256 with data rate of 15 SPS
  // other data rates: 
  // ADS1256_DRATE_30000SPS
  // ADS1256_DRATE_15000SPS
  // ADS1256_DRATE_7500SPS
  // ADS1256_DRATE_3750SPS
  // ADS1256_DRATE_2000SPS
  // ADS1256_DRATE_1000SPS
  // ADS1256_DRATE_500SPS
  // ADS1256_DRATE_100SPS
  // ADS1256_DRATE_60SPS
  // ADS1256_DRATE_50SPS
  // ADS1256_DRATE_30SPS
  // ADS1256_DRATE_25SPS
  // ADS1256_DRATE_15SPS
  // ADS1256_DRATE_10SPS
  // ADS1256_DRATE_5SPS
  // ADS1256_DRATE_2_5SPS
  // 
  // NOTE : Data Rate vary depending on crystal frequency. Data rates listed below assumes the crystal frequency is 7.68Mhz
  //        for other frequency consult the datasheet.
  //Posible Gains 
  //ADS1256_GAIN_1 
  //ADS1256_GAIN_2 
  //ADS1256_GAIN_4 
  //ADS1256_GAIN_8 
  //ADS1256_GAIN_16 
  //ADS1256_GAIN_32 
  //ADS1256_GAIN_64 
  adc.begin(ADS1256_DRATE_1000SPS,ADS1256_GAIN_1,false); 

  Serial.println("ADC Started");
  
   // Set MUX Register to AINO so it start doing the ADC conversion
  adc.setChannel(0);
}

void loop()
{ 
  currentTime = millis();
  elapsedTime = currentTime - lastTime; 
  if (elapsedTime >= 1000){
    Serial.print("elapsed: ");
    Serial.print(elapsedTime);
    Serial.print(" SPS: ");
    Serial.println(counter*1.0/elapsedTime*1000);
    lastTime = currentTime; 
    counter=0;    
  }  
  adc.waitDRDY(); // wait for DRDY to go low before changing multiplexer register 
  sensor1 = adc.readCurrentChannel(); // DOUT arriving here is from MUX AIN0 and AIN8 (GND)
  //print the result.
  //Serial.println(sensor1,10);
  counter++; 
}
