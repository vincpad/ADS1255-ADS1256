// Arudino Sample Code to use ADS1256 library
// http://www.ti.com/lit/ds/symlink/ads1256.pdf

// Reads channel 0 continuously

// Written by Axel Sepulveda, May 2020

//#include <ADS1256.h>
#include "ADS1256.h" // Use relative path 
#include <SPI.h>

// Construct and init ADS1256 object
ADS1256 adc; // 

float sensor1;

void setup()
{
  // Start serial
  Serial.begin(250000);  
  
  // start the ADS1256
  adc.begin();  
  Serial.println("ADC Started");
  
  // Set mux to read ch0
  Serial.println("Channel set to Single end ch0");
  adc.setChannel(0);
}

void loop()
{ 
  adc.waitDRDY(); // wait for DRDY to go low before next register read
  sensor1 = adc.readCurrentChannel(); // read as voltage according to gain and vref
  
  Serial.println(sensor1 , 10); // Print as decimal, 10 decimal places
}
