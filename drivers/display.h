#pragma once
#include "hardware/i2c.h"
#include "ssd1306.h"
#include "font.h" 

void display_init();
void display_char(char c);
void display_string(const char *msg);
void display_update(); 