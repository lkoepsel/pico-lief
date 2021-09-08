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
## Code Sizing
Tests on blink.c to understand the code size for different compilation methods. Size calculations came from cll command executed in gdb.
Step not yet taken is to determine if "Deoptimized" helps in debugging.

```
cmake -DCMAKE_BUILD_TYPE=Debug -DPICO_DEOPTIMIZED_DEBUG=1 ..
```

Loading section .boot2, size 0x100 lma 0x10000000
Loading section .text, size 0x6178 lma 0x10000100
Loading section .rodata, size 0x1154 lma 0x10006278
Loading section .binary_info, size 0x20 lma 0x100073cc
Loading section .data, size 0x42c lma 0x100073ec
Start address 0x100001e8, load size 30744

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
```
Loading section .boot2, size 0x100 lma 0x10000000
Loading section .text, size 0x40e0 lma 0x10000100
Loading section .rodata, size 0xe58 lma 0x100041e0
Loading section .binary_info, size 0x1c lma 0x10005038
Loading section .data, size 0x24c lma 0x10005054
Start address 0x100001e8, load size 21152

```
cmake ..
```

Loading section .boot2, size 0x100 lma 0x10000000
Loading section .text, size 0x1d88 lma 0x10000100
Loading section .rodata, size 0xb8 lma 0x10001e88
Loading section .binary_info, size 0x1c lma 0x10001f40
Loading section .data, size 0x1cc lma 0x10001f5c
Start address 0x100001e8, load size 8488


This blog entry also confirms this:
* [Disabling all Compiler Optimizations in the Pi Pico SDK](https://hackaday.io/project/177082-raspberry-pi-pico-emulator/log/191090-disabling-all-compiler-optimizations-in-the-pi-pico-sdk)

This said, performing the above optimization (or lack of, actually) will cause signficant issues with performance:
* [Pico debugging with GDB -- value has been optimized out](https://www.raspberrypi.org/forums/viewtopic.php?t=316648)

2. Removed references to "example_auto_set_url" as the reference is for adding an url via the picotool. See here as a rough explanation:
https://github.com/raspberrypi/pico-examples/issues/113