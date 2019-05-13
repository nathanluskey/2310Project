//Helpful Website: https://randomnerdtutorials.com/electronics-basics-how-do-rgb-leds-work/

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
  pinMode(A0, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  setColor(0,0,0);
  tone(piezoPin, 0);
  //1st alert
  for (int i = 0; i < 1; i++); {
    setColor(255, 0, 0);
    delay(2500);
    setColor(0, 0, 0);
    tone(piezoPin, 800);
    delay(500);
    tone(piezoPin,0);
    setColor(255, 0, 0);
    delay(2000);
  }
  //2nd alert
  for (int i = 0; i < 2; i++) {
    setColor(255, 0, 0);
    delay(1000);
    setColor(0, 0, 0);
    tone(piezoPin, 800);
    delay(250);
    tone(piezoPin, 0);
    setColor(255,0,0);
  }
  //3rd alert
  for (int i = 0; i < 3; i++) {
    setColor(255,0,0);
    tone(piezoPin, 800);
    delay(500);
  }
}

//rgb led controller, sets the pins to rgb from 0-255
// check if it's anode or cathode because it might need to be x = 255 - x if it's common anode;
// WE HAVE A COMMON CATHODE LED! no need to subtract
static void setColor( int r, int g, int b) {
  analogWrite(rPin, r);
  analogWrite(gPin, g);
  analogWrite(bPin, b);
  Serial.print("Color set to: ");
  Serial.print(r);
  Serial.print(g);
  Serial.println(b);
}
