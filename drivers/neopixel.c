#include "neopixel.h"
#include "ws2812.h"
#include "ws2812.pio.h" 

#define MATRIX_PIN 7
#define MATRIX_COUNT 25 // 5x5

static PIO pio = pio0;
static uint sm = 0;
static uint32_t neopixel_buffer[MATRIX_COUNT];

void neopixel_init() {
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, MATRIX_PIN, 800000, false);
    neopixel_clear();
}

void neopixel_put(uint32_t color) {
    for (int i = 0; i < MATRIX_COUNT; i++) {
        neopixel_buffer[i] = color;
    }
    pio_sm_put_blocking(pio, sm, color << 8u);
}

void neopixel_clear() {
    for (int i = 0; i < MATRIX_COUNT; i++) {
        neopixel_buffer[i] = 0;
    }
    ws2812_set_pixels(neopixel_buffer, MATRIX_COUNT);
    ws2812_show();
}

void neopixel_show() {
    ws2812_show();
}