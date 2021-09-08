# Raspberry Pi Pico SDK Examples from Lief

## Getting started

See [Getting Started with the Raspberry Pi Pico](https://rptl.io/pico-get-started) and the README in the [pico-sdk](https://github.com/raspberrypi/pico-sdk) for information
on getting up and running.

### First  Examples

App|Description | Link to prebuilt UF2
---|---|---
[blink](blink) | The obligatory blink program modified for 4 LEDs | 
[blink](blink) | The obligatory Hello World program for Pico (Output over USB version) | 
[blink](blink) | Blink 4 LEDs on and off. | 

App|Description | Link to prebuilt UF2
---|---|---
[gpio](gpio) | A test gpio program to determine if a board header has been properly soldered | 
[gpio](gpio) | Interactive GPIO test program | 
[gpio](gpio) | Select GPIO pin and set high, low or blink | 

Notes:

1. Changed the ENV variable in .github/cmake.yaml to be Debug as compared to release. When running cmake, add DPICO_DEOPTIMIZED_DEBUG=1 which will further reduce the optimization and add more debugging info (to be confirmed). Essentially this becomes:
```
cmake -DCMAKE_BUILD_TYPE=Debug -DPICO_DEOPTIMIZED_DEBUG=1 .
```
This blog entry also confirms this:
* [Disabling all Compiler Optimizations in the Pi Pico SDK](https://hackaday.io/project/177082-raspberry-pi-pico-emulator/log/191090-disabling-all-compiler-optimizations-in-the-pi-pico-sdk)

This said, performing the above optimization (or lack of, actually) will cause signficant issues with performance:
* [Pico debugging with GDB -- value has been optimized out](https://www.raspberrypi.org/forums/viewtopic.php?t=316648)