
#include <ADC.h>

const int micPin = A0;

// Create an IntervalTimer object 
// https://www.pjrc.com/teensy/td_timing_IntervalTimer.html
IntervalTimer myTimer;

// Create an ADC object to make measurements
// https://forum.pjrc.com/threads/25532-ADC-library-update-now-with-support-for-Teensy-3-1
ADC *adc = new ADC(); // adc object;


volatile unsigned long miccount = 0;
int lastTime = 0;
long value = 0;




void setup() {
  adc->setAveraging(1); // set number of averages
  adc->setResolution(16); // set bits of resolution
  adc->setConversionSpeed(ADC_MED_SPEED); // change the conversion speed
  // it can be ADC_VERY_LOW_SPEED, ADC_LOW_SPEED, ADC_MED_SPEED, ADC_HIGH_SPEED or ADC_VERY_HIGH_SPEED
  adc->setSamplingSpeed(ADC_HIGH_SPEED); // change the sampling speed

  Serial.begin(115200);
  adc->startContinuous(micPin);
  // setup a timer to make measurements - delay is in 
  myTimer.begin(getinput, 22.67);

  
}

void getinput(void) {
  value = adc->analogReadContinuous();
  // keep track of how many times we read a value
  miccount++;

  // send the value to the raspi
  sendData(value);
}


void sendData(long sendVal) {
  
}




// at 16bits, HIGH_SPEED for both conversion and sampling, we get about 380k samples/second
// however, speed settings doesn't change this when using continuousread
void loop() {
  // every second
  if (millis()-lastTime > 999) {
    // print in how many samples were taken
    Serial.println(miccount);
    miccount = 0;
    lastTime= millis();
  } 
}








