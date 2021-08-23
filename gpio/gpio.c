/**
 * Interactive Program to test GPIO 
 * by Lief Koepsel
 */

#include <stdio.h>
#include "pico/stdlib.h"

const int min_GPIO = 0;
const int max_GPIO = 28;

int get_gpio() {
    int gpio = 0;
    int gpio_state = 1;
    
    while (gpio_state == 1){
        int tens_good = 0;
        printf("\nEnter the GPIO (not Pin) number to test (%d - %d) or e to exit: ", min_GPIO, max_GPIO);

        char tens = getchar();
        if (tens == 'e' ){
            gpio_state = 0;
            return -1;
        }
        else if (tens < '0') {
            printf("GPIO tens digit < 0");
        }
        else if (tens > '9') {
            printf("GPIO tens digit > 9");
        }
        else {
            gpio = (int)(tens - '0') * 10;
            tens_good = 1;
        }

        if (tens_good == 1) {
            char ones = getchar();
            if (ones == 'e' ){
                gpio_state = 0;
                return -1;
            }
            else if (ones == '\n' || ones == '\r') {
                gpio = gpio / 10;
            }
            else if (ones < '0') {
                printf("GPIO ones digit < 0");
            }
            else if (ones > '9') {
                printf("GPIO ones digit > 9");
            }
            else {
                gpio = (int)(ones - '0') + gpio;
            }
            if (gpio < min_GPIO) {
                printf("GPIO pin is too low, must be greater than 0");
            }
            else if (gpio > max_GPIO) {
                printf("GPIO pin is too high, must be less than 29");
            }
            else {
                printf("\nTesting GPIO: %d ", gpio);
                gpio_state = 0;
            }
        }
    }
    return gpio;
}

void test1 (int *gpio) {
    printf(" Set %d High", *gpio);
    gpio_init(*gpio);
    gpio_set_dir(*gpio, GPIO_OUT);
    gpio_put(*gpio, 1);
}

void test2 (int *gpio) {
    printf(" Set %d Low", *gpio);
    gpio_init(*gpio);
    gpio_set_dir(*gpio, GPIO_OUT);
    gpio_put(*gpio, 0);
}

void test3 (int *gpio) {
    volatile int sleep_time = 500;
    printf(" Blink (1s) %d", *gpio);
    gpio_init(*gpio);
    gpio_set_dir(*gpio, GPIO_OUT);
    gpio_put(*gpio, 1);
    sleep_ms(sleep_time);
    gpio_put(*gpio, 0);
    sleep_ms(sleep_time);
}

void test4 (int *gpio) {
    volatile int sleep_time = 2000;
    printf(" Long Blink (4s) %d", *gpio);
    gpio_init(*gpio);
    gpio_set_dir(*gpio, GPIO_OUT);
    gpio_put(*gpio, 1);
    sleep_ms(sleep_time);
    gpio_put(*gpio, 0);
    sleep_ms(sleep_time);
}

void test5 (int *gpio) {
    printf(" State of GPIO %d %d", *gpio, gpio_get(*gpio));
}

void test6 (int *gpio) {
    printf(" Using GPIO %d", *gpio);
}

void test7 (int *gpio) {
    volatile int sleep_time = 500;
    printf(" Blink %d 4 times", *gpio);
    for (int i=1;i<5;++i) {
        gpio_init(*gpio);
        gpio_set_dir(*gpio, GPIO_OUT);
        gpio_put(*gpio, 1);
        sleep_ms(sleep_time);
        gpio_put(*gpio, 0);
        sleep_ms(sleep_time);
    }
}

void get_test(int *gpio) {
    int test_state = 1;
    int test;

    while (test_state == 1) {
        printf("\nEnter Test (0-New GPIO 1-High 2-Low 3-Blink 4-Long Blink 5-Get State 6-ID GPIO 7-Blink 4: ");
        test = getchar();
        switch(test) {
            case ('0'):
                test_state = 0;
                printf("\nNew GPIO");
            break;
            case ('1'):
                test1(gpio);
            break;
            case ('2'):
                test2(gpio);
            break;
            case ('3'):
                test3(gpio);
            break;
            case ('4'):
                test4(gpio);
            break;
            case ('5'):
                test5(gpio);
            break;
            case ('6'):
                test6(gpio);
            break;
            case ('7'):
                test7(gpio);
            break;
            default :
                printf(" Test must be 0-7");
            break;
        }
    }
    return;
}

int main() {
    stdio_init_all();
    int GPIO = 0;
    int exit = 1;

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Print Program title and burn char in buffer
    printf("\nInteractive GPIO Test");
    getchar();

    // Main loop, continue until 'e' has been entered
    // 1. Get GPIO to test
    // 2. Get test then execute test
    // if test 0, get new GPIO or 'e' to exit
    while (exit == 1) {
        GPIO = get_gpio();
        if (GPIO > -1){ 
        
            get_test(&GPIO);
        }
        else {
            exit = 0;
        }
    }

    printf("\nCompleted testing.\n");
    gpio_put(LED_PIN, 1);
    sleep_ms(2000);
    gpio_put(LED_PIN, 0);
    return 0;
}
