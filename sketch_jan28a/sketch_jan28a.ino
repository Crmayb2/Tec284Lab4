
#include <U8x8lib.h>

#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/
U8X8_PIN_NONE);
DHT dht(3, DHT11);
const int buzzerPin = 5;
void setup() {
  dht.begin();
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
}
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(humidity) || isnan(temperature)) {
    u8x8.clear();
    u8x8.setCursor(0, 0);
    u8x8.print("Failed to read sensor");
  } else {
    u8x8.clear();
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.setCursor(0, 0);
    u8x8.print("Temp: ");
    u8x8.print(temperature, 1);
    u8x8.print(" C");

    u8x8.setCursor(0, 2);
    u8x8.print("Humidity: ");
    u8x8.print(humidity, 1);
    u8x8.print(" %");
  }
  if (humidity > 70) {
      tone(buzzerPin, 1000);
    } else {
      noTone(buzzerPin);
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
}
}
