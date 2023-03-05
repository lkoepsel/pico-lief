// blink_array - blink multiple pins
#include "pico/stdlib.h"

int main() {
    const uint LED[] = {PICO_DEFAULT_LED_PIN, 15, 14, 13, 12};
    const uint INTERVAL[] = {50, 100, 200, 400, 800};
    for (uint8_t i = 0; i<5;i++)
    {    
            gpio_init(LED[i]);
            gpio_set_dir(LED[i], GPIO_OUT);
    }

    while (true) {
        for (uint8_t i = 0; i<5;i++)
        {    
            gpio_put(LED[i], 1);
            sleep_ms(INTERVAL[i]);
        }
        for (uint8_t i = 0; i<5;i++)
        {    
                gpio_put(LED[i], 0);
                sleep_ms(INTERVAL[i]);
        }
    }
}
