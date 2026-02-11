int t = 0;
float f = 0;
float g = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  t = millis();
  f = sin(t/1000.0);
  g = cos(t/1000.0);
  if (f > 0 && g > 0) {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
