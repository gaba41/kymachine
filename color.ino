#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      24

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int r1, g1, b1, r2, g2, b2;

void setup() {
  Serial.begin(115200);
  pixels.begin();
}

void loop() {

if(Serial.available()){
    static int temp_val;
    byte in_byte = Serial.read();
    if((in_byte >= '0') && (in_byte <= '9'))
      temp_val = temp_val * 10 + in_byte - '0';

    else if(in_byte == 'r'){
      r1 = temp_val;
      temp_val = 0;
    }
    else if(in_byte == 'g'){
      g1 = temp_val;
      temp_val = 0;
    }
    else if(in_byte == 'b'){ 
      b1 = temp_val;
      temp_val = 0;
    }
    else if(in_byte == 'q'){
      r2 = temp_val;
      temp_val = 0;
    }
    else if(in_byte == 'w'){
      g2 = temp_val;
      temp_val = 0;
    }
    else if(in_byte == 'e'){ 
      b2 = temp_val;
      temp_val = 0;
    }
}

  for (int i = 0; i < NUMPIXELS; i++) {

    if (i % 2) {
      pixels.setPixelColor(i, pixels.Color(r1, g1, b1)); //pixels pari
    }
    else {
      pixels.setPixelColor(i, pixels.Color(r2, g2, b2)); //pixels dispari
    }
  }
    pixels.show();
  }
