add_executable(tasks
        tasks.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(tasks pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(tasks)

# add url via pico_set_program_url
example_auto_set_url(tasks)
