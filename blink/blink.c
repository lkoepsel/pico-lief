/**
 * A variation on the blink routine
 *
 * Pico Pins 18 a-21 are connected to Red, Green, Blue, Yellow LED's
 * System cycles through all four, then lites built-in LED
 */

#include "pico/stdlib.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void init_BI_LED() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

void on_BI_LED() {
    init_BI_LED();
    gpio_put(LED_PIN, 1);
}

void off_BI_LED() {
    init_BI_LED();
    gpio_put(LED_PIN, 0);
}

int main() {
    // lite up built-in LED on entry to show program started
    init_BI_LED();
    on_BI_LED();
    const uint sleep_time = 200;
    sleep_ms(500);

// Cycle through 4 LED's, use an array to allow for non-sequential ports
    const uint PINS[4] = {18, 19, 20, 21};
    for (int i=0; i<4; i++) {
        gpio_init(PINS[i]);
        gpio_set_dir(PINS[i], GPIO_OUT);
    }
    while (true) {
        off_BI_LED();
        for (int i=0; i<4; i++) {
            gpio_put(PINS[i], 1);
            sleep_ms(sleep_time);
            gpio_put(PINS[i], 0);
            sleep_ms(sleep_time);
        }
        on_BI_LED();
        sleep_ms(500);
    }
}
