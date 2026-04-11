//main do projeto final
int main() {

    stdio_init_all();

    setup_display();

    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);

    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B);

    gpio_set_irq_enabled_with_callback(
        BOTAO_A,
        GPIO_IRQ_EDGE_FALL,
        true,
        &tratar_botao
    );

    gpio_set_irq_enabled(
        BOTAO_B,
        GPIO_IRQ_EDGE_FALL,
        true
    );

    // matriz dos LEDs WS2812

    PIO pio = pio0;
    int sm = 0;

    uint offset = pio_add_program(pio, &ws2812_program);

    inicializar_matriz(pio, sm, offset, PINO_MATRIZ, 800000, false);

    while (true) {
        mostrar_modo_uart();

        atualizar_display();

        for (int i = 0; i < TOTAL_LEDS; i++) {

            // s2 normal
            if (modo == 1) {
                if (coracao[i])
                    enviar_cor(criar_cor(50, 0, 0));
                else
                    enviar_cor(criar_cor(0, 0, 0));
            }

            // s2 invertido
            else if (modo == 2) {

                int inv = TOTAL_LEDS - 1 - i;

                if (coracao[inv])
                    enviar_cor(criar_cor(0, 50, 0));
                else
                    enviar_cor(criar_cor(0, 0, 0));
            }

            // s2 auto
            else if (modo == 3) {

                if (i < passo_auto && coracao[i])
                    enviar_cor(criar_cor(0, 0, 50));
                else
                    enviar_cor(criar_cor(0, 0, 0));
            }

            // s2 desligado
            else {
                enviar_cor(criar_cor(0, 0, 0));
            }
        }

        // animação automática em loop do coração
if (modo == 3) {

    if (passo_auto < TOTAL_LEDS) {
        passo_auto++;
    } 
    else {
        sleep_ms(2000);   // espera 2 segundos
        passo_auto = 0;   // reinicia animação
    }
}

        sleep_ms(150);
    }
}
