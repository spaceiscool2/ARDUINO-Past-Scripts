const int analogIn = A0;
int z = 0;
unsigned long t = 0;
const int N = 100;
unsigned long zsum = 0;

float z_6in = 800;
float z_12in = 400;
float z_18in = 267;
float z_24in = 200;
float z_30in = 160;
float z_36in = 133;

float displacement = 36;

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
    if ( z>z_6in ) {
      displacement = 6;
    }
    else if ( z > z_12in ) {
    displacement = 6 + 6/(z_6in-z_12in)*(z_6in-z);
    }
    else if ( z > z_18in ) {
    displacement = 12 + 6/(z_12in-z_18in)*(z_12in-z);
    }
    else if ( z > z_24in ) {
    displacement = 18 + 6/(z_18in-z_24in)*(z_18in-z);
    }
    else if ( z > z_30in ) {
    displacement = 24 + 6/(z_24in-z_30in)*(z_24in-z);
    }
    else if ( z > z_36in ) {
    displacement = 30 + 6/(z_30in-z_36in)*(z_30in-z);
    }
    else {
    displacement = 36;
  }
  Serial.println(displacement);
    t = millis();
  }
}
