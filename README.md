#  Projeto Raspberry Pi Pico - OLED + WS2812 + Botões

Este projeto foi desenvolvido utilizando a **Raspberry Pi Pico**, integrando um **display OLED SSD1306**, uma **matriz de LEDs WS2812** e **botões físicos** para controle de modos de operação.

---

 Funcionalidades

-  Exibição de informações no display OLED (SSD1306 via I2C)
-  Controle de matriz de LEDs WS2812 (25 LEDs)
-  Botões físicos para troca de modos
-  Modo automático com animação
-  Feedback via UART (terminal serial)

---

##  Modos de operação

- **Modo 0 - Desligado**
  - LED e display apagados

- **Modo 1 - Normal**
  - Exibe padrão normal no LED

- **Modo 2 - Invertido**
  - Inverte a animação da matriz

- **Modo 3 - Automático**
  - Animação progressiva do coração

---

##  Hardware utilizado

- Raspberry Pi Pico / Pico W
- Display OLED SSD1306 (I2C)
- Matriz de LEDs WS2812 (25 LEDs)
- 2 botões físicos (GPIO)
- Resistores de pull-up internos

---

##  Pinos utilizados

- **OLED I2C**
  - SDA: GPIO 14  
  - SCL: GPIO 15  

- **Botões**
  - Botão A: GPIO 5  
  - Botão B: GPIO 6  

- **LED WS2812**
  - GPIO 7  

---
