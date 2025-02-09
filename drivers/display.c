#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "font.h"
#include "ssd1306.h"


#define I2C_PORT i2c0

// Inicialização do display
void display_init(ssd1306_t *disp) {
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

// Atualização do display
void display_update(ssd1306_t *disp) {
    ssd1306_send_data(disp); // Função correta para enviar os dados
}

void display_string(ssd1306_t *disp, const char *msg) {
    ssd1306_draw_string(disp, msg, 0, 0); 
}