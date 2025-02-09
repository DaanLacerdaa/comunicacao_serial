#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"
#include "font.h"

#define I2C_PORT i2c0

// Declaração da fonte (externa ou definida aqui)
const font_t my_font = {
    .data = font,        // Ponteiro para os dados da fonte (o array font)
    .start_char = '0',  // O caractere inicial da sua fonte (ajuste conforme necessário)
    .char_width = FONT_WIDTH, // Largura da fonte
    .char_height = FONT_HEIGHT, // Altura da fonte
};





// Inicialização do display
void display_init(ssd1306_t *disp) { // Passa disp como argumento
    disp->width = 128;
    disp->height = 64;
    disp->external_vcc = false;

    i2c_init(I2C_PORT, 400000);
    gpio_set_function(14, GPIO_FUNC_I2C);
    gpio_set_function(15, GPIO_FUNC_I2C);

    ssd1306_init(disp, disp->width, disp->height, disp->external_vcc, 0x3C, I2C_PORT);
    ssd1306_config(disp); // Configura o display
    ssd1306_clear(disp);   // Limpa o display
}

// Funções corrigidas para receber disp como argumento
void display_char(ssd1306_t *disp, char c) {
    ssd1306_putc(disp, c, &my_font);
}

void display_string(ssd1306_t *disp, const char *msg) {
    ssd1306_puts(disp, msg, &my_font);
}

void display_update(ssd1306_t *disp) {
    ssd1306_send_data(disp); // Função correta
}