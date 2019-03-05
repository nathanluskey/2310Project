

// the setup routine runs once when you press reset:
int rPin = A1;
int gPin = A2;
int bPin = A3;
int piezoPin = A0;

void setup() {
  // initialize the digital pin as an output.
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  //just an example of how to set color and have a delay, delay is in ms
  setColor(255, 255, 255);
  delay(3000);
  setColor(0, 0, 0);
  delay(3000);
  setColor(255, 0, 0);
  delay(3000);
  setColor(255, 0, 0);
  delay(3000);
  setColor(0, 0, 255);
  delay(3000);

  //buzzer code
  /*Tone needs 2 arguments, but can take three
    2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
    3) Duration - how long teh tone plays
  */
  tone(piezoPin, 1000, 500);
  delay(1000);
}

//rgb led controller, sets the pins to rgb from 0-255
static void setColor( int r, int g, int b) {
  analogWrite(255 - rPin, r);
  analogWrite(255 - gPin, g);
  analogWrite(255 - bPin, b);
  Serial.printf("Color set to: %d, %d, %d \n", r, g, b);
}
