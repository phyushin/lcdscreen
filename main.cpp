/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int RED = 13;
int GREEN = 12;
int BLUE = 11;
int Brightness = 10;
int n =0;
int inc = 1;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(RED, OUTPUT);     
  pinMode(GREEN, OUTPUT);     
  pinMode(BLUE, OUTPUT);  
  pinMode(Brightness,OUTPUT);
  
}

void backlightOff()
{
  digitalWrite(GREEN,HIGH);
  digitalWrite(RED,HIGH);
  digitalWrite(BLUE,HIGH);
}
void backlightColour(boolean r,boolean g ,boolean b, int brightness)
{
  analogWrite(Brightness,brightness);
  r ? digitalWrite(RED,LOW) : digitalWrite(RED,HIGH); //if we want switch the red  cathode to 'off'
  g ? digitalWrite(GREEN,LOW) : digitalWrite(GREEN,HIGH);
  b ? digitalWrite(BLUE,LOW) : digitalWrite(BLUE,HIGH);
}

int fade(int inc)
{
  n = n+inc;
  delay(10);
  return n;  
}

// the loop routine runs over and over again forever:
void loop() {
  
  backlightOff();//
  

 int inc = 1;
 while (n < 255)
 {
   backlightColour(true,false,true,fade(inc));//turqoise
 }
 inc = inc * -1;
 while (n > 0 )
 {
   backlightColour(true,false,true,fade(inc));
 }
 
 
}