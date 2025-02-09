#include "display.h"
#include "ssd1306.h"
#define I2C_PORT i2c0

SSD1306_t disp; // Variável global para o display

void display_init() {
    disp.width = 128;
    disp.height = 64;
    disp.external_vcc = false;
    i2c_init(I2C_PORT, 400000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);
    ssd1306_init(&disp, 0x3C, i2c_write_blocking); // Use o endereço correto do seu display
    ssd1306_clear(&disp);
}

void display_char(char c) {
    ssd1306_putc(&disp, c, &font_8x8); // Use sua fonte 8x8 ou outra de sua preferência
}

void display_string(const char *msg) {
    ssd1306_puts(&disp, msg, &font_8x8); // Use sua fonte 8x8 ou outra de sua preferência
}

void display_update() {
    ssd1306_update(&disp);
}