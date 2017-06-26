//LED Pin Variables
int ledPins[] = {5,8}; //An array to hold the pin each LED is connected to
                                   //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                   //to address an array use ledPins[0] this would equal 2
                                   //and ledPins[7] would equal 9

int lightModulo = 0; // for which modulo to light
 
/*
 * setup() - this function runs once when you turn your Arduino on
 * We the three control pins to outputs
 */
void setup()
{
  
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 2; i++){         //this is a loop and will repeat eight times
      pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin to output
  }                                   //the code this replaces is below
  
  Serial.begin(9600);
}
 
 
/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called oneAfterAnother(). if you would like a different behaviour
 * uncomment (delete the two slashes) one of the other lines
 */
void loop()                     // run over and over again
{
  turnOnEvenOdd();
}

// turn on even LEDs, then odd LEDs.
// nice to have them set up as yellow/red
void turnOnEvenOdd() {
  int delayTime = 250;
  
  // print desired modulo.
  Serial.println(lightModulo);
  
  for (int i = 0; i < 2; i++) {
    if ((i % 2) == lightModulo) {
      // on
      // when desired modulo is 1 (odd),  odds  will light
      // when desired modulo is 0 (even), evens will light
      digitalWrite(ledPins[i], HIGH);
    } else {
      // off
      // ...and the others will be turned off
      digitalWrite(ledPins[i], LOW);
    }
  }
  
  // switch lightModulo to the other light
  lightModulo--;                   // decrease. 1 turns to 0, 0 turns to -1
  lightModulo = abs(lightModulo);  // when it's -1 (from 0), abs to 1
  
  delay(delayTime);
}
