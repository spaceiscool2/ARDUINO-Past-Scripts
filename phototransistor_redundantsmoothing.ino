const int analogIn = A0;
int z = 0;
unsigned long t = 0;
const int N = 100;
unsigned long zsum = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if(millis()-t > 1000){
    // put your main code here, to run repeatedly:
    zsum=0;
    for(int i=0;i<N;i++){
      zsum += analogRead(analogIn);
    }
    z = zsum/N;
    Serial.println(z);
    t = millis();
  }
}
