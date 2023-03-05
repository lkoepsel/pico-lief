// blink_bit - uses bit operations to blink pins

#include "pico/stdlib.h"
#define PIN_ALL_MASK    0b1111000000000000

const uint interval = 1000;

void blink_all(void)
{
    for (int i = 0; i< 8; i++)
    {
        gpio_xor_mask(PIN_ALL_MASK);
        sleep_ms(interval);    
    }    
}

int main() {
    gpio_init_mask(PIN_ALL_MASK);
    gpio_set_dir_masked(PIN_ALL_MASK, PIN_ALL_MASK);

    blink_all();
    return 0;
}
