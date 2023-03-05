// blink_timer - uses the repeating timer function for timing
// passes the pin bit number using user_data
#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_ALL_MASK    0b1111000000000000
#define PIN_12_MASK     0b0001000000000000
#define PIN_13_MASK     0b0010000000000000
#define PIN_14_MASK     0b0100000000000000
#define PIN_15_MASK     0b1000000000000000

bool toggle_led(struct repeating_timer *t) 
{
    gpio_xor_mask(*(int*) t->user_data);
    printf("Repeat at %lld\n", time_us_64());
    return true;
}

int main() {
    stdio_init_all();
    printf("Hello Timer!\n");
    gpio_init_mask(PIN_ALL_MASK);
    gpio_set_dir_out_masked(PIN_ALL_MASK);

    // Create a repeating timer that calls toggle_led.
    uint PIN0 = PIN_12_MASK;
    uint PIN1 = PIN_13_MASK;
    uint PIN2 = PIN_14_MASK;
    uint PIN3 = PIN_15_MASK;
    struct repeating_timer timer0;
    struct repeating_timer timer1;
    struct repeating_timer timer2;
    struct repeating_timer timer3;

    const uint32_t PRIME_INTERVAL = 400000;

    add_repeating_timer_us(PRIME_INTERVAL*8, toggle_led, &PIN0, &timer0);
    add_repeating_timer_us(PRIME_INTERVAL*4, toggle_led, &PIN1, &timer1);
    add_repeating_timer_us(PRIME_INTERVAL*2, toggle_led, &PIN2, &timer2);
    add_repeating_timer_us(PRIME_INTERVAL, toggle_led, &PIN3, &timer3);
    busy_wait_us_32(PRIME_INTERVAL*16);
    gpio_clr_mask(PIN_ALL_MASK);
    return 0;
}
