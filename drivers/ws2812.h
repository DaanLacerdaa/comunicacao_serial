#ifndef WS2812_H
#define WS2812_H

#include <stdint.h> // Para uint32_t

// Definições (você pode mover algumas definições para cá, se preferir)
#define NUM_LEDS 25 // Exemplo

// Declarações das funções
void ws2812_set_pixels(uint32_t *pixels, int num_pixels);
void ws2812_show();
void ws2812_init();

#endif