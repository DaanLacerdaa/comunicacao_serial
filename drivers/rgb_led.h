#pragma once
#include "pico/stdlib.h"

void rgb_led_init(uint red_pin, uint green_pin, uint blue_pin);
void rgb_led_set_color(uint red, uint green, uint blue);
