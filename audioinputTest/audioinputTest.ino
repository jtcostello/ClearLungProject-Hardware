// Create an IntervalTimer object 
IntervalTimer myTimer;
const int micPin = A0;
volatile unsigned long micval = 0; // use volatile for shared variables
volatile unsigned long miccount = 0;

//int myInts[];



void setup(void) {
  pinMode(micPin, INPUT);
  Serial.begin(115200);
  myTimer.begin(getinput, 22.67);  // blinkLED to run every 0.15 seconds

  // turn on LED to indicate running
  pinMode(LED_BUILTIN, INPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}



void getinput(void) {
  micval = analogRead(micPin);
  miccount++;
}






// The main program will print the mic analog value
// to the Arduino Serial Monitor
void loop(void) {
  unsigned long micCopy; 
  unsigned long countCopy; 
  
  noInterrupts();
  micCopy = micval;
  countCopy = miccount;
  miccount=0;  
  interrupts();

//  Serial.println(countCopy);
  Serial.println(micCopy);
  delay(1);
}





// holds a copy of the blinkCount

  // to read a variable which the interrupt code writes, we
  // must temporarily disable interrupts, to be sure it will
  // not change while we are reading.  To minimize the time
  // with interrupts off, just quickly make a copy, and then
  // use the copy while allowing the interrupt to keep working.
