#include "ssd1306.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"
#define SCL_PIN 15
#define SDA_PIN 14
ssd1306_t disp;
void setup_display()
{
    i2c_init(i2c1, 400000);

    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);

    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    disp.external_vcc = false;

    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);

    ssd1306_clear(&disp);

    ssd1306_draw_string(&disp, 0, 0, 1, "Projeto Final");
    ssd1306_show(&disp);
}
void atualizar_display(int modo)
{
    ssd1306_clear(&disp);

    if (modo == 0) {
        ssd1306_draw_string(&disp, 0, 10, 2, "Desligado");
    }
    else if (modo == 1) {
        ssd1306_draw_string(&disp, 0, 10, 2, "Normal");
    }
    else if (modo == 2) {
        ssd1306_draw_string(&disp, 0, 10, 2, "Invertido");
    }
    else if (modo == 3) {
        ssd1306_draw_string(&disp, 0, 10, 2, "Auto");
    }

    ssd1306_show(&disp);
}
