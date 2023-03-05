add_executable(blink_struct
        blink_struct.c
        )

# pull in common dependencies
target_link_libraries(blink_struct pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink_struct)

# add url via pico_set_program_url
example_auto_set_url(blink_struct)
