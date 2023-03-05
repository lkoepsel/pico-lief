// blink_multi - blink multiple pins
#include "pico/stdlib.h"

int main() {
    const uint LED_0 = PICO_DEFAULT_LED_PIN;
    const uint INTERVAL_0 = 500;
    gpio_init(LED_0);
    gpio_set_dir(LED_0, GPIO_OUT);
    const uint LED_1 = 15;
    const uint INTERVAL_1 = 500;
    gpio_init(LED_1);
    gpio_set_dir(LED_1, GPIO_OUT);
    const uint LED_2 = 14;
    const uint INTERVAL_2 = 500;
    gpio_init(LED_2);
    gpio_set_dir(LED_2, GPIO_OUT);
    while (true) {
        gpio_put(LED_0, 1);
        sleep_ms(INTERVAL_0);
        gpio_put(LED_0, 0);
        sleep_ms(INTERVAL_0);
        gpio_put(LED_1, 1);
        sleep_ms(INTERVAL_1);
        gpio_put(LED_1, 0);
        sleep_ms(INTERVAL_1);
        gpio_put(LED_2, 1);
        sleep_ms(INTERVAL_2);
        gpio_put(LED_2, 0);
        sleep_ms(INTERVAL_2);
    }
}
