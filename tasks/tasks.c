/* One line kernal for multitasking
*  https://www.embedded.com/a-multitasking-kernel-in-one-line-of-code-almost/
*  Uses direct pin manipulation using a set bit on Input Port
*  Delivers 62kHz signal from 10 tasks
*/
#include "pico/stdlib.h"
#define NTASKS 8

// Uno pin numbers
const int LED0 = 2; 
const int LED1 = 3;
const int LED2 = 4;
const int LED3 = 5;
const int LED4 = 6;
const int LED5 = 7;
const int LED6 = 8;
const int LED7 = 9;
const int mask = 0b0000001111111100;
const int mask0 = 0b0000000000000100;
const int mask1 = 0b0000000000001000;
const int mask2 = 0b0000000000010000;
const int mask3 = 0b0000000000100000;
const int mask4 = 0b0000000001000000;
const int mask5 = 0b0000000010000000;
const int mask6 = 0b0000000100000000;
const int mask7 = 0b0000001000000000;

typedef struct task {
   void (*TickFct)();    // Function to call for task's tick
} task;

task tasks[NTASKS];

void t0 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask0);
    return;
} 

void t1 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask1);
    return;
} 

void t2 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask2);
    return;
} 

void t3 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask3);
    return;
} 

void t4 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask4);
    return;
} 

void t5 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask5);
    return;
} 

void t6 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask6);
    return;
} 

void t7 (void) {
    /* toggle led on and off */
    gpio_xor_mask(mask7);
    return;
} 


int main(void)
{
    gpio_init_mask(mask);
    gpio_set_dir_masked(mask, mask);

    int i = 0;
    tasks[i].TickFct = &t0;
    ++i;
    tasks[i].TickFct = &t1;
    ++i;
    tasks[i].TickFct = &t2;
    ++i;
    tasks[i].TickFct = &t3;
    ++i;
    tasks[i].TickFct = &t4;
    ++i;
    tasks[i].TickFct = &t5;
    ++i;
    tasks[i].TickFct = &t6;
    ++i;
    tasks[i].TickFct = &t7;

    for (;;)
    {
    for (int taskcount=0; taskcount < NTASKS; ++taskcount)
        {
            tasks[taskcount].TickFct();
        }
    }
    return(0); 
}
