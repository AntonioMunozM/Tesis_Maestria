float readChannel(ADS1115_MUX channel) {
  float voltage = 0.0;
  adc1.setCompareChannels(channel);
  voltage = adc1.getResult_mV(); // alternative: getResult_mV for Millivolt, getRawResult for raw result
  return voltage;
}

void Pin_Init(){
  pinMode(Pin_velocidad, INPUT);
  pinMode(Pin_frecuencia, INPUT);
  pinMode(Pin_1wire, OUTPUT);
  pinMode(Pin_ledverde, OUTPUT);
  pinMode(Pin_ledrojo, OUTPUT);
  pinMode(Pin_dac1, OUTPUT);
  pinMode(Pin_dac2, OUTPUT);
}

void inicio_led(){
    for(i = 1; i<=5; i++){
        digitalWrite(Pin_ledrojo, 1);
        digitalWrite(Pin_ledverde, 1);
        delay(500);
        digitalWrite(Pin_ledrojo, 0);
        digitalWrite(Pin_ledverde, 0);
        delay(500);
    }
}