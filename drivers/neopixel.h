#pragma once
#include "hardware/pio.h"

void neopixel_init();
void neopixel_put(uint32_t color);
void neopixel_clear(); // Adicione esta função para apagar todos os LEDs