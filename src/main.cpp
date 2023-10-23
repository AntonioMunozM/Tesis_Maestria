

#include <Arduino.h>
#include <ADS1115_WE.h> 
#include <Wire.h>
#include <01_definiciones.h>
ADS1115_WE adc1 = ADS1115_WE(ADC1);
ADS1115_WE adc2 = ADS1115_WE(ADC2);
//ADS1115_WE adc2 = ADS1115_WE(ADC2);
#include <02_Sensor_init.h>
#include <03_Funciones.h>

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
  Serial.begin(115200);
  Pin_Init();
  Wire.begin();
  Setup_ADC1();
  //Setup_ADC2();
  inicio_led();
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

