#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"
#include "font.h"

#define I2C_PORT i2c0

SSD1306_t disp; // Variável global para o display

void display_init() {
    disp.width = 128;
    disp.height = 64;
    disp.external_vcc = false;

    // Inicializa a I2C
    i2c_init(I2C_PORT, 400000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);

    // Inicializa o display. Correção principal:
    ssd1306_init(&disp, disp.width, disp.height, disp.external_vcc, 0x3C, I2C_PORT); // Passa todos os argumentos, incluindo a instância I2C

    ssd1306_clear(&disp);
}

void display_char(char c) {
    ssd1306_putc(&disp, c, &font_8x8); // Use sua fonte 8x8 ou outra de sua preferência. Certifique-se que font_8x8 esteja definida.
}

void display_string(const char *msg) {
    ssd1306_puts(&disp, msg, &font_8x8); // Use sua fonte 8x8 ou outra de sua preferência. Certifique-se que font_8x8 esteja definida.
}

void display_update() {
    ssd1306_update(&disp);
}