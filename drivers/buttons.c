#include "buttons.h"

#define BTN_A 5
#define BTN_B 6

static button_callback_t btn_a_cb = NULL;
static button_callback_t btn_b_cb = NULL;
static volatile uint32_t last_interrupt = 0;

static void gpio_isr(uint gpio, uint32_t events) {
    if (to_ms_since_boot(get_absolute_time()) - last_interrupt > 50) { // Debounce
        if (gpio == BTN_A && btn_a_cb) btn_a_cb();
        if (gpio == BTN_B && btn_b_cb) btn_b_cb();
    }
    last_interrupt = to_ms_since_boot(get_absolute_time());
}

void buttons_init(button_callback_t a_cb, button_callback_t b_cb) {
    btn_a_cb = a_cb;
    btn_b_cb = b_cb;

    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);

    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, gpio_isr); // Interrupção na borda de descida
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, gpio_isr); // Interrupção na borda de descida
}