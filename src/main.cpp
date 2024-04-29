#define DEBUG 1

#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
#define YELLOW 255,255,0
#define CYAN 0,255,255
#define MAGENTA 255,0,255
#define WHITE 255,255,255
#define ORANGE 255,165,0
#define PINK 255,192,203
#define PURPLE 128,0,128
#define BROWN 165,42,42



#define LED_PIN_1   2   
#define LED_PIN_2   3 
#define LED_PIN_3   4 
#define LED_PIN_4   5 
#define LED_PIN_5   6 
#define LED_PIN_6   7 
#define LED_PIN_7   8 
#define LED_PIN_8   9

#define LED_COUNT_1 30    
#define LED_COUNT_2 30
#define LED_COUNT_3 30
#define LED_COUNT_4 30
#define LED_COUNT_5 30
#define LED_COUNT_6 30
#define LED_COUNT_7 30
#define LED_COUNT_8 30

#define BRIGHTNESS 255


#define NUMBER_OF_ON_LED_FOR_STRIP_1 4
#define NUMBER_OF_OFF_LED_FOR_STRIP_1 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_1_IN_us 70000

#define NUMBER_OF_ON_LED_FOR_STRIP_2 4
#define NUMBER_OF_OFF_LED_FOR_STRIP_2 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_2_IN_us 70000

#define NUMBER_OF_ON_LED_FOR_STRIP_3 4
#define NUMBER_OF_OFF_LED_FOR_STRIP_3 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_3_IN_us 70000

#define NUMBER_OF_ON_LED_FOR_STRIP_4 4
#define NUMBER_OF_OFF_LED_FOR_STRIP_4 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_4_IN_us 70000

#define NUMBER_OF_ON_LED_FOR_STRIP_5 4
#define NUMBER_OF_OFF_LED_FOR_STRIP_5 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_5_IN_us 70000

#define NUMBER_OF_ON_LED_FOR_STRIP_6 4
#define NUMBER_OF_OFF_LED_FOR_STRIP_6 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_6_IN_us 70000

#define NUMBER_OF_ON_LED_FOR_STRIP_7 4
#define NUMBER_OF_OFF_LED_FOR_STRIP_7 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_7_IN_us 70000

#define NUMBER_OF_ON_LED_FOR_STRIP_8  4
#define NUMBER_OF_OFF_LED_FOR_STRIP_8 8
#define TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_8_IN_us 70000



#include <Arduino.h>
#include <Adafruit_NeoPixel.h>



uint32_t current_led_number_1 = 0;
uint32_t current_led_number_2 = 0;
uint32_t current_led_number_3 = 0;
uint32_t current_led_number_4 = 0;
uint32_t current_led_number_5 = 0;
uint32_t current_led_number_6 = 0;
uint32_t current_led_number_7 = 0;
uint32_t current_led_number_8 = 0;

uint32_t last_updated_time_for_strip_1 = 0;
uint32_t last_updated_time_for_strip_2 = 0;
uint32_t last_updated_time_for_strip_3 = 0;
uint32_t last_updated_time_for_strip_4 = 0;
uint32_t last_updated_time_for_strip_5 = 0;
uint32_t last_updated_time_for_strip_6 = 0;
uint32_t last_updated_time_for_strip_7 = 0;
uint32_t last_updated_time_for_strip_8 = 0;


Adafruit_NeoPixel strip_1(LED_COUNT_1, LED_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2(LED_COUNT_2, LED_PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3(LED_COUNT_3, LED_PIN_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4(LED_COUNT_4, LED_PIN_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_5(LED_COUNT_5, LED_PIN_5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_6(LED_COUNT_6, LED_PIN_6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_7(LED_COUNT_7, LED_PIN_7, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_8(LED_COUNT_8, LED_PIN_8, NEO_GRB + NEO_KHZ800);


void pixel_1(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_1 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_1_IN_us) {
    return;
  }
  if (current_led_number_1 < (LED_COUNT_1 + NUMBER_OF_ON_LED_FOR_STRIP_1)) {
    current_led_number_1 += 1;
  } else {
    current_led_number_1 = (LED_COUNT_1 + NUMBER_OF_ON_LED_FOR_STRIP_1) - (NUMBER_OF_ON_LED_FOR_STRIP_1 + NUMBER_OF_OFF_LED_FOR_STRIP_1 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_1; k++) {
    strip_1.setPixelColor(k, strip_1.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_1; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_1 + NUMBER_OF_OFF_LED_FOR_STRIP_1))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_1); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_1),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_1),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_1),b,0);
      strip_1.setPixelColor(m, strip_1.Color(r, g, b));
    }
  }
  strip_1.show();
  last_updated_time_for_strip_1 = micros();
}
void pixel_2(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_2 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_2_IN_us) {
    return;
  }
  if (current_led_number_2 < (LED_COUNT_2 + NUMBER_OF_ON_LED_FOR_STRIP_2)) {
    current_led_number_2 += 1;
  } else {
    current_led_number_2 = (LED_COUNT_2 + NUMBER_OF_ON_LED_FOR_STRIP_2) - (NUMBER_OF_ON_LED_FOR_STRIP_2 + NUMBER_OF_OFF_LED_FOR_STRIP_2 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_2; k++) {
    strip_2.setPixelColor(k, strip_2.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_2; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_2 + NUMBER_OF_OFF_LED_FOR_STRIP_2))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_2); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_2),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_2),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_2),b,0);
      strip_2.setPixelColor(m, strip_2.Color(r, g, b));
    }
  }
  strip_2.show();
  last_updated_time_for_strip_2 = micros();
}

void pixel_3(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_3 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_3_IN_us) {
    return;
  }
  if (current_led_number_3 < (LED_COUNT_3 + NUMBER_OF_ON_LED_FOR_STRIP_3)) {
    current_led_number_3 += 1;
  } else {
    current_led_number_3 = (LED_COUNT_3 + NUMBER_OF_ON_LED_FOR_STRIP_3) - (NUMBER_OF_ON_LED_FOR_STRIP_3 + NUMBER_OF_OFF_LED_FOR_STRIP_3 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_3; k++) {
    strip_3.setPixelColor(k, strip_3.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_3; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_3 + NUMBER_OF_OFF_LED_FOR_STRIP_3))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_3); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_3),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_3),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_3),b,0);
      strip_3.setPixelColor(m, strip_3.Color(r, g, b));
    }
  }
  strip_3.show();
  last_updated_time_for_strip_3 = micros();
}

void pixel_4(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_4 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_4_IN_us) {
    return;
  }
  if (current_led_number_4 < (LED_COUNT_4 + NUMBER_OF_ON_LED_FOR_STRIP_4)) {
    current_led_number_4 += 1;
  } else {
    current_led_number_4 = (LED_COUNT_4 + NUMBER_OF_ON_LED_FOR_STRIP_4) - (NUMBER_OF_ON_LED_FOR_STRIP_4 + NUMBER_OF_OFF_LED_FOR_STRIP_4 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_4; k++) {
    strip_4.setPixelColor(k, strip_4.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_4; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_4 + NUMBER_OF_OFF_LED_FOR_STRIP_4))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_4); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_4),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_4),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_4),b,0);
      strip_4.setPixelColor(m, strip_4.Color(r, g, b));
    }
  }
  strip_4.show();
  last_updated_time_for_strip_4 = micros();
}

void pixel_5(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_5 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_5_IN_us) {
    return;
  }
  if (current_led_number_5 < (LED_COUNT_5 + NUMBER_OF_ON_LED_FOR_STRIP_5)) {
    current_led_number_5 += 1;
  } else {
    current_led_number_5 = (LED_COUNT_5 + NUMBER_OF_ON_LED_FOR_STRIP_5) - (NUMBER_OF_ON_LED_FOR_STRIP_5 + NUMBER_OF_OFF_LED_FOR_STRIP_5 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_5; k++) {
    strip_5.setPixelColor(k, strip_5.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_5; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_5 + NUMBER_OF_OFF_LED_FOR_STRIP_5))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_5); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_5),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_5),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_5),b,0);
      strip_5.setPixelColor(m, strip_5.Color(r, g, b));
    }
  }
  strip_5.show();
  last_updated_time_for_strip_5 = micros();
}

void pixel_6(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_6 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_6_IN_us) {
    return;
  }
  if (current_led_number_6 < (LED_COUNT_6 + NUMBER_OF_ON_LED_FOR_STRIP_6)) {
    current_led_number_6 += 1;
  } else {
    current_led_number_6 = (LED_COUNT_6 + NUMBER_OF_ON_LED_FOR_STRIP_6) - (NUMBER_OF_ON_LED_FOR_STRIP_6 + NUMBER_OF_OFF_LED_FOR_STRIP_6 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_6; k++) {
    strip_6.setPixelColor(k, strip_6.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_6; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_6 + NUMBER_OF_OFF_LED_FOR_STRIP_6))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_6); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_6),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_6),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_6),b,0);
      strip_6.setPixelColor(m, strip_6.Color(r, g, b));
    }
  }
  strip_6.show();
  last_updated_time_for_strip_6 = micros();
}

void pixel_7(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_7 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_7_IN_us) {
    return;
  }
  if (current_led_number_7 < (LED_COUNT_7 + NUMBER_OF_ON_LED_FOR_STRIP_7)) {
    current_led_number_7 += 1;
  } else {
    current_led_number_7 = (LED_COUNT_7 + NUMBER_OF_ON_LED_FOR_STRIP_7) - (NUMBER_OF_ON_LED_FOR_STRIP_7 + NUMBER_OF_OFF_LED_FOR_STRIP_7 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_7; k++) {
    strip_7.setPixelColor(k, strip_7.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_7; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_7 + NUMBER_OF_OFF_LED_FOR_STRIP_7))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_7); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_7),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_7),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_7),b,0);
      strip_7.setPixelColor(m, strip_7.Color(r, g, b));
    }
  }
  strip_7.show();
  last_updated_time_for_strip_7 = micros();
}

void pixel_8(uint8_t r, uint8_t g, uint8_t b)
{
  if (micros() - last_updated_time_for_strip_8 < TIME_DELAY_FOR_RUNNING_SPEED_FOR_STRIP_8_IN_us) {
    return;
  }
  if (current_led_number_8 < (LED_COUNT_8 + NUMBER_OF_ON_LED_FOR_STRIP_8)) {
    current_led_number_8 += 1;
  } else {
    current_led_number_8 = (LED_COUNT_8 + NUMBER_OF_ON_LED_FOR_STRIP_8) - (NUMBER_OF_ON_LED_FOR_STRIP_8 + NUMBER_OF_OFF_LED_FOR_STRIP_8 - 1);
  }
  for (uint16_t k = 1; k <= current_led_number_8; k++) {
    strip_8.setPixelColor(k, strip_8.Color(0, 0, 0));
  }
  for (int32_t j = current_led_number_8; j > 0; j -= (NUMBER_OF_ON_LED_FOR_STRIP_8 + NUMBER_OF_OFF_LED_FOR_STRIP_8))
  {
    for (int32_t i = j; i > (j - NUMBER_OF_ON_LED_FOR_STRIP_8); i--)
    {
      uint16_t m = i; if (m < 1) {
        m = 1;
      }
            uint8_t red = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_8),r,0);
            uint8_t green = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_8),g,0);
            uint8_t blue = map(m,j,(j- NUMBER_OF_ON_LED_FOR_STRIP_8),b,0);
      strip_8.setPixelColor(m, strip_8.Color(r, g, b));
    }
  }
  strip_8.show();
  last_updated_time_for_strip_8 = micros();
}

void allstripClear() {
  strip_1.clear();
  strip_2.clear();
  strip_3.clear();
  strip_4.clear();
  strip_5.clear();
  strip_6.clear();
  strip_7.clear();
  strip_8.clear();
  strip_1.show();
  strip_2.show();
  strip_3.show();
  strip_4.show();
  strip_5.show();
  strip_6.show();
  strip_7.show();
  strip_8.show();
}

void strip_light_setup() {
  strip_1.begin();
  strip_2.begin();
  strip_3.begin();
  strip_4.begin();
  strip_5.begin();
  strip_6.begin();
  strip_7.begin();
  strip_8.begin();

  strip_1.setBrightness(BRIGHTNESS);
  strip_2.setBrightness(BRIGHTNESS);
  strip_3.setBrightness(BRIGHTNESS);
  strip_4.setBrightness(BRIGHTNESS);
  strip_5.setBrightness(BRIGHTNESS);
  strip_6.setBrightness(BRIGHTNESS);
  strip_7.setBrightness(BRIGHTNESS);
  strip_8.setBrightness(BRIGHTNESS);
}


void setup() {
  Serial.begin(9600);
  strip_light_setup();
  

}
void loop() {

  pixel_1(RED);
  pixel_2(GREEN);
  pixel_3(BLUE);
  pixel_4(YELLOW);
  pixel_5(PURPLE);
  pixel_6(MAGENTA);
  pixel_7(ORANGE);
  pixel_8(CYAN);
  
}

