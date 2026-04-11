#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

// inicializa o display OLED
void setup_display(void);

// atualiza o texto de acordo com o modo
void atualizar_display(int modo);

#endif
