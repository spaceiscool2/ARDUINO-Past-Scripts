const int analogIn = A0;
int z = 0;
unsigned long t = 0;

void setup() {

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-t > 100){
    z = analogRead(analogIn);
    Serial.println(z);
    t = millis();
  }
}
