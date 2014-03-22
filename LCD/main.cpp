int RED = 4;
int GREEN = 3;
int BLUE = 2;
int Brightness = 5;
int Button = 13;
int n =0;
int inc = 1;
int colour =1;
int colourmode;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(RED, OUTPUT);     
  pinMode(GREEN, OUTPUT);     
  pinMode(BLUE, OUTPUT);  
  pinMode(Brightness,OUTPUT);
  pinMode(Button,INPUT); //connect pin 13 to the button and connect the button to ground
  
}

void backlightOff()
{
  digitalWrite(GREEN,HIGH);
  digitalWrite(RED,HIGH);
  digitalWrite(BLUE,HIGH);
}
void backlightColour(int brightness)
{delay(100); //dont want it to do more than one click at a time!
  if (digitalRead(Button)==LOW)
  {
    colour++; //if the button is pressed increment the colour value (this is a bit mask thingy)
  }
  analogWrite(Brightness,brightness);
  switch (colourmode = colour % 8 )
  {
    case 1 : //red
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,HIGH);
      digitalWrite(BLUE,HIGH);
      break;
    case 2: //GREEN
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,LOW);
      digitalWrite(BLUE,HIGH);
      break;
   case 3: // YELLOW
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,LOW);
      digitalWrite(BLUE,HIGH);
      break;
  case 4://BLUE
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,HIGH);
      digitalWrite(BLUE,LOW);
      break;
  case 5://PURPLE
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,HIGH);
      digitalWrite(BLUE,LOW);
      break;
 case 6://TURQUOISE
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,LOW);
      digitalWrite(BLUE,LOW);
      break;
 case 7://WHITE
      digitalWrite(RED,LOW);
      digitalWrite(GREEN,LOW);
      digitalWrite(BLUE,LOW);
      break;
  default:
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN,HIGH);
      digitalWrite(BLUE,HIGH);
  break;
  }
}

int fade(int inc)
{
  n = n+inc;
  delay(10);
  return n;  
}


void loop() {
  inc = 1;
  backlightOff();//
 while (n < 255)
 {
   backlightColour(fade(inc));
 }
 inc = inc * -1;
 while (n > 0 )
 {
   backlightColour(fade(inc));
 }
 
 
}