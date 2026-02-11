const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 9;
const int LED4 = 10;
const int LED5 = 11;

int T = 1000;

int arrayState = 1;
unsigned long lastTime = 0;

bool buttonState = false;
const int buttonPin = 3;
int increment = 1;

long z = 0;
const int inputPin = A0;

int data_array[5][5] {
  {255, 204, 153, 102, 51},
  {51, 255, 204, 153, 102},
  {102, 51, 255, 204, 153},
  {153, 102, 51, 255, 204},
  {204, 153, 102, 51, 255}, };

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
pinMode(LED5,OUTPUT);

pinMode(buttonPin, INPUT);

digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
Serial.begin(9000);
}

void loop(){
  if (( millis() - lastTime) > T) {
    lastTime = millis();
    if (buttonState==true) {
      increment = -increment;
      if (increment < -1){increment = 1;}
      buttonState = false;
    }
    arrayState = arrayState + increment;
    if (arrayState > 5){arrayState = 1;}
    if (arrayState < 1){arrayState = 5;}
    if (arrayState == 1){analogWrite(LED1,255);}
    else {analogWrite(LED1,data_array[arrayState-1][0]);}
    if (arrayState == 2){analogWrite(LED2,255);}
    else {analogWrite(LED2,data_array[arrayState-1][1]);}
    if (arrayState == 3){analogWrite(LED3,255);}
    else {analogWrite(LED3,data_array[arrayState-1][2]);}
    if (arrayState == 4){analogWrite(LED4,255);}
    else {analogWrite(LED4,data_array[arrayState-1][3]);}
    if (arrayState == 5){analogWrite(LED5,255);}
    else {analogWrite(LED5,data_array[arrayState-1][4]);}
  }
  if (digitalRead(buttonPin)==HIGH){buttonState = true;}
  z = analogRead(inputPin);
  Serial.println(z);
}

