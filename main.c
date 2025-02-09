#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/uart.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "drivers/neopixel.h"
#include "drivers/rgb_led.h"
#include "drivers/ws2812.pio.h" // Arquivo PIO para WS2812

#define UART_ID uart0
#define BAUD_RATE 115200

#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13

volatile bool led_verde_ligado = false;
volatile bool led_azul_ligado = false;

static void handle_btn_a() {
    led_verde_ligado = !led_verde_ligado;
    rgb_led_set_color(0, led_verde_ligado, 0); // Acende/Apaga o LED verde
    display_string(led_verde_ligado ? "LED Verde: Ligado" : "LED Verde: Desligado");
    display_update(); // Atualiza o display para mostrar a mensagem
    printf("LED Verde: %s\n", led_verde_ligado ? "Ligado" : "Desligado");
}

static void handle_btn_b() {
    led_azul_ligado = !led_azul_ligado;
    rgb_led_set_color(0, 0, led_azul_ligado); // Acende/Apaga o LED azul
    display_string(led_azul_ligado ? "LED Azul: Ligado" : "LED Azul: Desligado");
    display_update(); // Atualiza o display para mostrar a mensagem
    printf("LED Azul: %s\n", led_azul_ligado ? "Ligado" : "Desligado");
}

int main() {
    stdio_init_all();
    uart_init(UART_ID, BAUD_RATE); // Inicializa a UART

    // Inicializa os drivers
    display_init();
    buttons_init(handle_btn_a, handle_btn_b);
    neopixel_init();
    rgb_led_init(LED_RED, LED_GREEN, LED_BLUE); // Inicializa o driver RGB

    // Configura o LED RGB inicialmente apagado
    rgb_led_set_color(0, 0, 0);

    // Loop principal
    while (true) {
        // Entrada de caracteres via PC
        if (uart_is_readable(UART_ID)) {
            char ch = getchar();
            printf("Caractere recebido: %c\n", ch);

            // Exibe o caractere no display SSD1306
            display_char(ch);
            display_update();

            // Se for um número entre 0 e 9, exibe o símbolo correspondente na matriz WS2812
            if (ch >= '0' && ch <= '9') {
                int num = ch - '0';
                neopixel_put(num); // Função neopixel_put precisa ser implementada
                neopixel_show();    // Função neopixel_show precisa ser implementada
            }
        }
    }

    return 0;
}


