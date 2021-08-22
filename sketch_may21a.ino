#include <FastLED.h>

#define NUM_LEDS    100
#define DATA_PIN    2

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(90);
  
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  
  pacman(0);
}

void lightsaber() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(20);
  }
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(20);
  }
}

void whiteDance() {
  for (int i = 0; i < NUM_LEDS;i += 2){
    leds[i] = CRGB::White;
  }
  delay(200);
  FastLED.show();
  for(int i = 0; i < NUM_LEDS; i += 2) {
    leds[i] = CRGB::Black;
  }
  
  for(int i = 1; i < NUM_LEDS; i += 2) {
    leds[i] = CRGB::White;
  }
  delay(200);
  FastLED.show();
  for(int i = 1; i < NUM_LEDS; i += 2) {
    leds[i] = CRGB::Black;
  }
  
}

void pacman(int j) {
  
  for (int i = j; i >=0; i--) {
    leds[i] = CRGB::White;
    leds[i + 1] = CRGB::Black;
    if (j % 2 == 0) {
      leds[0] = CRGB::White;
    }else {
      leds[0] = CRGB::Black;
    }
    i--;
    continue;
  }
  delay(200);
  FastLED.show();
  if (j + 1 < NUM_LEDS) {
    pacman(j + 1); 
  } else {
    pacman(j - 1);
  }
}
