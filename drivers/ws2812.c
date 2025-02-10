#include "pico/stdlib.h"
#include "ws2812.pio.h" // Inclua o arquivo gerado pelo PIO assembler

// Definições (pinos, número de LEDs, etc.)
#define WS2812_PIO pio0
#define WS2812_SM 0
#define WS2812_PIN 7
#define NUM_LEDS 25 
// Buffer para armazenar as cores dos LEDs
uint32_t neopixel_buffer[NUM_LEDS];

// Função para enviar um único pixel para o PIO
static inline void ws2812_send_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(WS2812_PIO, WS2812_SM, pixel_grb);
}

// Função ws2812_set_pixels
void ws2812_set_pixels(uint32_t *pixels, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        neopixel_buffer[i] = pixels[i];
    }
}

// Função ws2812_show
void ws2812_show() {
    for (int i = 0; i < NUM_LEDS; i++) {
        ws2812_send_pixel(neopixel_buffer[i]);
    }
}

// Inicializa o PIO para controlar os LEDs WS2812
void ws2812_init() {
    PIO pio = WS2812_PIO;
    int sm = WS2812_SM;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, false);
}