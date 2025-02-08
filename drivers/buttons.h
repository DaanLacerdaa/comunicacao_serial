#pragma once
#include "pico/stdlib.h"

typedef void (*button_callback_t)(void);

void buttons_init(button_callback_t a_cb, button_callback_t b_cb);