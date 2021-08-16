/**
 * A variation on the blink routine
 *
 * Feather Pins 9-11 are connected to Yellow, Blue, Green Red LED's
 * System cycles through all four, then lites built-in LED
 */

#include "pico/stdlib.h"
void lite_led() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);
}

int main() {
    lite_led();
    // lite up built-in LED on entry to show program started
    sleep_ms(500);

// Cycle through 4 LED's, use an array to allow for non-sequential ports
    const uint PINS[4] = {9, 10, 11, 12};
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    for (int i=0; i<4; ++i) {
        gpio_init(PINS[i]);
        gpio_set_dir(PINS[i], GPIO_OUT);
    }
    while (true) {
        gpio_put(LED_PIN, 0);
        for (int i=0; i<4; ++i) {
            gpio_put(PINS[i], 1);
            sleep_ms(500*(i+1));
            gpio_put(PINS[i], 0);
            sleep_ms(100);
        }
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
    }
}
