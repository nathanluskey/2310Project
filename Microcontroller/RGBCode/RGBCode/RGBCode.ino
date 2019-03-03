

// the setup routine runs once when you press reset:
int rPin = 1;
int gPin = 1;
int bPin = 1;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);     
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  setColor(255,255,255);
  delay(1000);
}

//rgb led controller, sets the pins to rgb from 0-255
static void setColor( int r, int g, int b) {
  analogWrite(rPin,r);
  analogWrite(gPin,g);
  analogWrite(bPin,b);
  Serial.printf("Color set to: %d, %d, %d \n",r,g,b);
}
