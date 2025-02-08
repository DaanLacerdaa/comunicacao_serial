#include "rgb_led.h"

static uint red_pin, green_pin, blue_pin;

void rgb_led_init(uint red_pin, uint green_pin, uint blue_pin) {
    red_pin = red_pin;
    green_pin = green_pin;
    blue_pin = blue_pin;

    gpio_init(red_pin);
    gpio_set_dir(red_pin, GPIO_OUT);
    gpio_init(green_pin);
    gpio_set_dir(green_pin, GPIO_OUT);
    gpio_init(blue_pin);
    gpio_set_dir(blue_pin, GPIO_OUT);
}

void rgb_led_set_color(uint red, uint green, uint blue) {
    gpio_put(red_pin, red);
    gpio_put(green_pin, green);
    gpio_put(blue_pin, blue);
}