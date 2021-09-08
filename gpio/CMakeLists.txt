add_executable(gpio
        gpio.c
        )

# Pull in our pico_stdlib which aggregates commonly used features
target_link_libraries(gpio pico_stdlib)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(gpio)
