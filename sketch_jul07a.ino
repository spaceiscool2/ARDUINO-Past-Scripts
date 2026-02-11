//Temperature/Humidity Sensor
#include "DHT.h"
#include <Arduino.h>
#include <U8x8lib.h>

#define DHTPIN 3 // what pin we're connected to
#define DHTTYPE DHT11  // DHT 11

DHT dht(DHTPIN, DHTTYPE);

U8X8_SSD1306_128X64_ALTO_HW_I2C u8x8(/* reset=*/ U8X8_PIN-NONE);

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFlipMode(1);
}
