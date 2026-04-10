//testando uart
#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    sleep_ms(2000);  // Aguarda a conexão USB
    
    printf("TESTE 1\n");
    printf("TESTE 2\n");
    printf("TESTE 3\n");
    
    while (true) {
        printf("Oi! Estou vivo!\n");
        sleep_ms(1000);
    }
    
    return 0;
}
