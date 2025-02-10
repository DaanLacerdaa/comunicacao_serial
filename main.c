#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "drivers/ssd1306.h"
#include "drivers/ws2812.h"
#include "drivers/buttons.h"

// Variáveis globais
ssd1306_t display;

// Definições de LEDs RGB
#define LED_RED_PIN    11
#define LED_GREEN_PIN  12
#define LED_BLUE_PIN   13

// Definições de botões
#define BUTTON_A_PIN   5
#define BUTTON_B_PIN   6

// Estados dos LEDs
bool led_green_on = false;
bool led_blue_on = false;

// Função de callback para o botão A (LED verde)
void button_a_callback() {
    led_green_on = !led_green_on;
    
    // Atualiza o display
    ssd1306_clear(&display);
    ssd1306_draw_string(&display, "LED Verde: ", 0, 0);
    ssd1306_draw_string(&display, led_green_on ? "Ligado" : "Desligado", 0, 10);
    ssd1306_send_data(&display);
    
    // Envia mensagem ao Serial Monitor
    uart_puts(uart0, "Botao A pressionado: LED Verde ");
    uart_puts(uart0, led_green_on ? "Ligado" : "Desligado");
    uart_puts(uart0, "\n");
    
    // Aciona ou desliga o LED verde
    gpio_put(LED_GREEN_PIN, led_green_on);
}

// Função de callback para o botão B (LED azul)
void button_b_callback() {
    led_blue_on = !led_blue_on;
    
    // Atualiza o display
    ssd1306_clear(&display);
    ssd1306_draw_string(&display, "LED Azul: ", 0, 0);
    ssd1306_draw_string(&display, led_blue_on ? "Ligado" : "Desligado", 0, 10);
    ssd1306_send_data(&display);
    
    // Envia mensagem ao Serial Monitor
    uart_puts(uart0, "Botao B pressionado: LED Azul ");
    uart_puts(uart0, led_blue_on ? "Ligado" : "Desligado");
    uart_puts(uart0, "\n");

    // Aciona ou desliga o LED azul
    gpio_put(LED_BLUE_PIN, led_blue_on);
}

void setup() {
    // Inicializa o display SSD1306
    i2c_init(i2c0, 400000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);
    
    ssd1306_init(&display, 128, 64, false, 0x3C, i2c0);
    ssd1306_clear(&display);

    // Inicializa os LEDs RGB
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    // Inicializa os botões A e B
    button_init(button_a_callback, button_b_callback);

    // Inicializa a porta serial para comunicação com o PC
    uart_init(uart0, 9600);  // Configura UART0 para 9600 bps
}

void loop() {
    char input_char = 0;
    if (uart_is_readable(uart0)) {
        input_char = uart_getc(uart0);

        // Exibe o caractere na tela
        ssd1306_clear(&display);
        ssd1306_draw_string(&display, "Caractere: ", 0, 0);
        ssd1306_draw_string(&display, &input_char, 0, 10);
        ssd1306_send_data(&display);

        // Se for um número entre 0 e 9, aciona a matriz WS2812
        if (input_char >= '0' && input_char <= '9') {
            int num = input_char - '0'; // Converte para número
            uint32_t color = (num == 0) ? 0xFF0000 :  // Vermelho para 0
                             (num == 1) ? 0x00FF00 :  // Verde para 1
                             (num == 2) ? 0x0000FF :  // Azul para 2
                             0xFFFFFF;                // Branco para outros números

            uint32_t pixels[NUM_LEDS];  // Matriz de LEDs WS2812
            for (int i = 0; i < NUM_LEDS; i++) {
                pixels[i] = color; // Aplica a cor em todos os LEDs
            }
            ws2812_set_pixels(pixels, NUM_LEDS);
            ws2812_show();
        }
    }

    sleep_ms(100); // Delay para não sobrecarregar a CPU
}

int main() {
    stdio_init_all();
    setup();

    while (true) {
        loop();
    }

    return 0;
}
