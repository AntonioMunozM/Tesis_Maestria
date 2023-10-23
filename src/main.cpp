

#include <Arduino.h>
#include <ADS1115_WE.h> 
#include <Wire.h>
#include <01_definiciones.h>
ADS1115_WE adc1 = ADS1115_WE(ADC1);
ADS1115_WE adc2 = ADS1115_WE(ADC2);
//ADS1115_WE adc2 = ADS1115_WE(ADC2);
#include <02_Sensor_init.h>
//#include <03_Funciones.h>

  /* Use this for the 16-bit version */

// constexpr int READY_PIN = 3;

// This is required on ESP32 to put the ISR in IRAM. Define as
// empty for other platforms. Be careful - other platforms may have
// other requirements.
//#ifndef IRAM_ATTR
//#define IRAM_ATTR
//#endif

float readChannel(ADS1115_MUX channel);


void setup() {
  Serial.begin(9600);
  Serial.println("queonda");
  pinMode(Pin_velocidad, INPUT);
  pinMode(Pin_frecuencia, INPUT);
  pinMode(Pin_1wire, OUTPUT);
  pinMode(Pin_ledverde, OUTPUT);
  pinMode(Pin_ledrojo, OUTPUT);
  pinMode(Pin_dac1, OUTPUT);
  pinMode(Pin_dac2, OUTPUT);
  Serial.println("Pines iniciados");
  Wire.begin();
  Serial.println("Biblioteca Wire iniciada");
  Setup_ADC1();
  Setup_ADC2();

}

void loop() {


  Serial.print("0: ");
  voltage = readChannel(ADS1115_COMP_0_GND);
  Serial.print(voltage);

  Serial.print(",   1: ");
  voltage = readChannel(ADS1115_COMP_1_GND);
  Serial.print(voltage);
  
  Serial.print(",   2: ");
  voltage = readChannel(ADS1115_COMP_2_GND);
  Serial.print(voltage);

  Serial.print(",   3: ");
  voltage = (readChannel(ADS1115_COMP_3_GND));
  Serial.println(voltage);

  delay(1000);
}

float readChannel(ADS1115_MUX channel) {
  float voltage = 0.0;
  adc1.setCompareChannels(channel);
  voltage = adc1.getRawResult(); // alternative: getResult_mV for Millivolt
  return voltage;
}