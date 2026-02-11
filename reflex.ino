int ledPin = 13;
int switchPin = 2;
int long ranDelay = 0;
int sensorValue = 0;
float reactime;

void setup()
{
  Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop(){
   Serial.println("");
  Serial.println("");
  Serial.println("");
   Serial.println("Push button to start");
  
  while (digitalRead(switchPin)== LOW) {
  }
  Serial.println("");
  Serial.println("");
  Serial.println("");
   Serial.println("Eliminating bugs...");
  delay(1000);
  Serial.println("Capturing IP...");
   delay(1000);
  ranDelay = random(5000);
  delay(ranDelay);
  Serial.println("Go");

  unsigned long nowtime;
  unsigned long starttime=millis();
 
  while   (digitalRead(switchPin) == HIGH) {
    nowtime=millis();
  }
  digitalWrite(ledPin, LOW);
   Serial.println("Time:");
  reactime = millis()-reactime;
  Serial.print(reactime/1000,2);
   Serial.println(" seconds");
   Serial.println("Or more exactly,");
  Serial.print(reactime);
   Serial.println(" milliseconds");
 delay(2000); 
}
