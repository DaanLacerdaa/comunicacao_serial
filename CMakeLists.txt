
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
# ============================================================

cmake_minimum_required(VERSION 3.12)

# Definição do board antes da inicialização do SDK
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importação do SDK do Raspberry Pi Pico
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Nome do projeto
project(bitdog_project)

# Inicialização do SDK
pico_sdk_init()

# Criação do executável com todos os arquivos de código-fonte
add_executable(main
    main.c
    drivers/display.c
    drivers/buttons.c
    drivers/neopixel.c
    drivers/rgb_led.c
    drivers/ssd1306.c 
    drivers/ws2812.c
)

# Adiciona as bibliotecas necessárias
target_link_libraries(main 
    pico_stdlib 
    hardware_uart 
    hardware_i2c 
    hardware_pio
)

# Configuração de entrada/saída padrão
pico_enable_stdio_uart(main 1)
pico_enable_stdio_usb(main 0)

# Geração de arquivos binários extras (UF2, ELF, etc.)
pico_add_extra_outputs(main)
