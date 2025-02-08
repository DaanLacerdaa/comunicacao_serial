cmake_minimum_required(VERSION 3.12)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(bitdog_project)

pico_sdk_init()

add_executable(main 
    main.c 
    drivers/display.c 
    drivers/buttons.c 
    drivers/neopixel.c
)

target_link_libraries(main 
    pico_stdlib 
    hardware_uart 
    hardware_i2c 
    hardware_pio
)

pico_enable_stdio_uart(main 1)
pico_enable_stdio_usb(main 0)
pico_add_extra_outputs(main)