add_executable(blink_array
        blink_array.c
        )

# pull in common dependencies
target_link_libraries(blink_array pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_array)

# add url via pico_set_program_url
example_auto_set_url(blink_array)
