#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 12
#define GREEN_LED_PIN 13

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    static int state = 0;

    // Alterna entre os estados do semáforo
    switch (state) {
        case 0:
            gpio_put(RED_LED_PIN, 1);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 0);
            printf("LED Vermelho aceso\n");
            break;
        case 1:
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 1);
            gpio_put(GREEN_LED_PIN, 0);
            printf("LED Amarelo aceso\n");
            break;
        case 2:
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 1);
            printf("LED Verde aceso\n");
            break;
    }

    state = (state + 1) % 3; // Próximo estado
    return true;
}

int main() {
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    // Configura e inicia o temporizador
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        printf("Sistema funcionando...\n");
        sleep_ms(1000);
    }

    return 0;
}
