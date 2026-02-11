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
    if (arrayState == 1){ digitalWrite(LED1,HIGH); }
    else { digitalWrite(LED1,LOW);}
    if (arrayState == 2){ digitalWrite(LED2,HIGH); }
    else { digitalWrite(LED2,LOW);}
    if (arrayState == 3){ digitalWrite(LED3,HIGH); }
    else { digitalWrite(LED3,LOW);}
    if (arrayState == 4){ digitalWrite(LED4,HIGH); }
    else { digitalWrite(LED4,LOW);}
    if (arrayState == 5){ digitalWrite(LED5,HIGH); }
    else { digitalWrite(LED5,LOW);}
  }
  if (digitalRead(buttonPin)==HIGH){buttonState = true;}
  z = analogRead(inputPin);
  Serial.println(z);
}

