add_executable(blink_multi
        blink_multi.c
        )

# pull in common dependencies
target_link_libraries(blink_multi pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_multi)

# add url via pico_set_program_url
example_auto_set_url(blink_multi)
