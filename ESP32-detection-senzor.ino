#include <Adafruit_NeoPixel.h>

// ----- PIN SETUP -----
#define SENSOR_PIN 25   // IR sensor OUT
#define LED_PIN 26      // RGB LED circle DI
#define NUM_LEDS 8      // change to number of LEDs on your ring

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(SENSOR_PIN, INPUT);  // IR sensor input
  strip.begin();               // initialize LED strip
  strip.show();                // turn all LEDs off
  Serial.begin(115200);
  Serial.println("Obstacle sensor + RGB LED ready!");
}

// ----- FUNCTION TO SET LED COLOR -----
void setColor(uint32_t color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void loop() {
  int obstacle = digitalRead(SENSOR_PIN);

  if (obstacle == LOW) { // obstacle detected
    setColor(strip.Color(255, 0, 0));  // RED
    Serial.println("Obstacle detected!");
  } else {               // path clear
    setColor(strip.Color(0, 255, 0));  // GREEN
    Serial.println("Path clear");
  }

  delay(50); // small delay to avoid flickering
}
