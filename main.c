#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "drivers/display.h"
#include "drivers/buttons.h"
#include "drivers/neopixel.h"
#include "drivers/rgb_led.h"

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
    display_update();
    printf("LED Verde: %s\n", led_verde_ligado ? "Ligado" : "Desligado");
}

static void handle_btn_b() {
    led_azul_ligado = !led_azul_ligado;
    rgb_led_set_color(0, 0, led_azul_ligado); // Acende/Apaga o LED azul
    display_string(led_azul_ligado ? "LED Azul: Ligado" : "LED Azul: Desligado");