// blink_struct - blink multiple pins non-blocking, using a struct
// Uses the Arduino method of non-blocking by tracking time expired
// uses static uint32_t time_us_32 (void) instead of millis()
#include "pico/stdlib.h"

#define N_LEDS 4
struct blinker
{
  uint8_t ledPin;           // the number of the LED pin
  bool state;          // the state (HIGH/LOW) the LED pin
  uint32_t interval;      // interval at which to blink (milliseconds)
  uint32_t previous_micros;   // will store last time LED was updated
} ;

struct blinker LEDS[N_LEDS];

void init_blink(uint8_t index, uint8_t ledPin, uint8_t state, 
    uint32_t interval, uint32_t previous_micros)
{
    LEDS[index].ledPin = ledPin;
    LEDS[index].state = state;
    LEDS[index].interval = interval;
    LEDS[index].previous_micros = previous_micros;

    gpio_init(LEDS[index].ledPin);
    gpio_set_dir(LEDS[index].ledPin, GPIO_OUT);

}

int main (void)
{
    init_blink(0, 15, false, 100000, 0);
    init_blink(1, 14, false, 200000, 0);
    init_blink(2, 13, false, 400000, 0);
    init_blink(3, 12, false, 800000, 0);

    while(1)
    {
        uint32_t current_micros = time_us_32();
        for (uint8_t i = 0; i < N_LEDS; i++)
        {
            if(current_micros - LEDS[i].previous_micros > LEDS[i].interval) 
            {
                LEDS[i].previous_micros = current_micros;   
                LEDS[i].state = !LEDS[i].state;
                gpio_put(LEDS[i].ledPin, LEDS[i].state);
            }
        }
    }
}
