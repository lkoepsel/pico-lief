# Raspberry Pi Pico SDK Examples

## Getting started

See [Developing in C on the RP2040](https://wellys.com/posts/courses_pico_c/) for information on getting up and running.

### First  Examples (Same as pico-examples)

App|Description | Link to prebuilt UF2
---|---|---
[hello_serial](hello_world/serial) | The obligatory Hello World program for Pico (Output over serial version) |
[hello_usb](hello_world/usb) | The obligatory Hello World program for Pico (Output over USB version) | https://rptl.io/pico-hello-usb
[blink](blink) | Blink an LED on and off. | https://rptl.io/pico-blink

### blink variations

App|Description
---|---
[blink_array](blink_array)|blink multiple LEDs using an array
[blink_bit](blink_bit)|blink multiple LEDs using low level hardware API
[blink_multi](blink_multi)|blink multiple LEDs using in-line coce
[blink_struct](blink_struct)|blink multiple LEDs, non-blocking using a struct
[blink_timer](blink_timer)|blink multiple LEDs, non-blocking using hardware API and repeating timer

### gpio

App|Description
---|---
[gpio](gpio) | Interactive GPIO test program, great for testing if header is properly soldered| 

### CMake (same as pico-examples)

App|Description
---|---
[build_variants](cmake/build_variants)| Builds two version of the same app with different configurations

### tasks
[One-line multi-tasking kernal, almost](https://www.embedded.com/a-multitasking-kernel-in-one-line-of-code-almost/)

App|Description
---|---
[tasks](tasks)| One line kernal for multitasking, Uses direct pin manipulation using a set bit on Input Port, Delivers 62kHz signal from 10 tasks


## Code Sizing (From previous work, needs validation)
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