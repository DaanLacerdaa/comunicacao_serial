# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico w CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.12)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(bitdog_project)

pico_sdk_init()

add_executable(main 
    main.c 
    drivers/display.c 
    drivers/buttons.c 
    drivers/neopixel.c
    drivers/rgb_led.c
   

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

