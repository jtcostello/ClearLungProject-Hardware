
#include <ADC.h>

const int micPin = A0;

// Create an IntervalTimer object 
IntervalTimer myTimer;
ADC *adc = new ADC(); // adc object;


int counter = 0;
volatile unsigned long miccount = 0;
int t = 0;
int t1 = 0;
int value = 0;




void setup() {
  adc->setAveraging(1); // set number of averages
  adc->setResolution(16); // set bits of resolution
  adc->setConversionSpeed(ADC_MED_SPEED); // change the conversion speed
  // it can be ADC_VERY_LOW_SPEED, ADC_LOW_SPEED, ADC_MED_SPEED, ADC_HIGH_SPEED or ADC_VERY_HIGH_SPEED
  adc->setSamplingSpeed(ADC_MED_SPEED); // change the sampling speed


  Serial.begin(115200);
  adc->startContinuous(micPin);
  myTimer.begin(getinput, 22.67);

  
}

void getinput(void) {
  value = adc->analogReadContinuous();
  miccount++;
}



// at 16bits, HIGH_SPEED for both conversion and sampling, we get about 380k samples/second
// however, speed settings doesn't change this when using continuousread
void loop() {

 if (millis()-t > 999) {
  Serial.println(value);
  miccount = 0;
  counter = 0;
  t = millis();
 } 
}

