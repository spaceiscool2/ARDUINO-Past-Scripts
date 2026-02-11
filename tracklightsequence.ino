const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 9;
const int LED4 = 10;
const int LED5 = 11;

int T = 1000;

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
pinMode(LED5,OUTPUT);

digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1,HIGH);
delay(T);
digitalWrite(LED1,LOW);
digitalWrite(LED2,HIGH);
delay(T);
digitalWrite(LED2,LOW);
digitalWrite(LED3,HIGH);
delay(T);
digitalWrite(LED3,LOW);
digitalWrite(LED4,HIGH);
delay(T);
digitalWrite(LED4,LOW);
digitalWrite(LED5,HIGH);
delay(T);
digitalWrite(LED5,LOW);
}
