add_executable(blink_bit
        blink_bit.c
        )

# pull in common dependencies
target_link_libraries(blink_bit pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_bit)

# add url via pico_set_program_url
example_auto_set_url(blink_bit)
