int temperaturePin = A0;
const float T0 = 298.15;
const float R0 = 10000;
const float B = 3950; // Thermistor Coefficient [K]

int Z = 0; // stores output of ADC
float R = 10000;
float R_series = 10000; // series resistance for voltage divide
float T = 300;
int t_update = 1000; // sample time
unsigned long t_last = 0; // stores last sample time

const int analogIn = A0;
const int N = 1;
unsigned long Zsum = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(millis()-T > 100) {
    Zsum = 0;
    for(int i = 0;i<N;i++) {
      Zsum += analogRead(analogIn);
    }
    Z = Zsum/N;
    Serial.println(Z);
    T = millis();
  }
  if((millis() - (t_last) > t_update)) {
    t_last = millis();
    Z = analogRead(temperaturePin);
    R = Z/(1023.0-Z)*R_series;
    T = 1/(1/T0 + 1/B*log(R/R0));
    Serial.print( "Temperature [C] : " );
    Serial.println(T-273.15);
  }
}
