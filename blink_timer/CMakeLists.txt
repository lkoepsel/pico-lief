add_executable(blink_timer
        blink_timer.c
        )

# pull in common dependencies
target_link_libraries(blink_timer pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_timer)

# add url via pico_set_program_url
example_auto_set_url(blink_timer)
