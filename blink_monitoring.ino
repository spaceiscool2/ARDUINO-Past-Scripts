int t = 0;
float f = 0;
const int outputPin = 11;
int x = 0;
float v = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);
}

void loop() {
    t = millis();
  f = sin(t/1000.0);
  if (f > 0) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  Serial.print("f =");
  Serial.println(f);
  delay(10);
  v = (1+f)*2.5;
  x = 255/5*v;
  analogWrite(outputPin,x);
}
