#include <stdio.h>       // Biblioteca padrão do C.
#include "pico/stdlib.h" // Biblioteca padrão do Raspberry Pi Pico para controle de GPIO, temporização e comunicação serial.
#include "pico/time.h"   // Biblioteca para gerenciamento de temporizadores e alarmes.

// Definição dos pinos dos LEDs e do botão
const uint LED_BLUE_PIN = 11;  // Pino GPIO para o LED azul.
const uint LED_RED_PIN = 12;   // Pino GPIO para o LED vermelho.
const uint LED_GREEN_PIN = 13; // Pino GPIO para o LED verde.
const uint BUTTON_PIN = 5;     // Pino GPIO para o botão.

bool led_active = false; // Indica se os LEDs estão atualmente acesos.
// Declarações antecipadas das funções de callback
int64_t turn_off_red_callback(alarm_id_t id, void *user_data);   // Declaração da função de callback para desligar o LED vermelho.
int64_t turn_off_green_callback(alarm_id_t id, void *user_data); // Declaração da função de callback para desligar o LED verde.

// Função de callback para desligar o LED azul após 3 segundos.
int64_t turn_off_blue_callback(alarm_id_t id, void *user_data)
{
    gpio_put(LED_BLUE_PIN, false); // Desliga o LED azul.
    // Agenda o desligamento do LED vermelho após 3 segundos.
    add_alarm_in_ms(3000, turn_off_red_callback, NULL, false);
    return 0; // Retorna 0 para indicar que o alarme não deve se repetir.
}

// Função de callback para desligar o LED vermelho.
int64_t turn_off_red_callback(alarm_id_t id, void *user_data)
{
    gpio_put(LED_RED_PIN, false); // Desliga o LED vermelho.
    // Agenda o desligamento do LED verde após 3 segundos.
    add_alarm_in_ms(3000, turn_off_green_callback, NULL, false);
    return 0; // Retorna 0 para indicar que o alarme não deve se repetir.
}

// Função de callback para desligar o LED verde.
int64_t turn_off_green_callback(alarm_id_t id, void *user_data)
{
    gpio_put(LED_GREEN_PIN, false); // Desliga o LED verde.
    led_active = false;             // Atualiza o estado de 'led_active' para falso.
    return 0;                       // Retorna 0 para indicar que o alarme não deve se repetir.
}

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial.

    // Inicializa os pinos dos LEDs como saída.
    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_put(LED_BLUE_PIN, false); // Garante que o LED azul comece desligado.

    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_put(LED_RED_PIN, false); // Garante que o LED vermelho comece desligado.

    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_put(LED_GREEN_PIN, false); // Garante que o LED verde comece desligado.

    // Inicializa o botão.
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // Habilita o resistor pull-up interno.

    // Loop principal do programa.
    while (true)
    {
        // Verifica se o botão foi pressionado e se os LEDs não estão ativos.
        if (gpio_get(BUTTON_PIN) == 0 && !led_active)
        {
            sleep_ms(50); // Debounce.

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(BUTTON_PIN) == 0)
            {
                // Liga todos os LEDs.
                gpio_put(LED_BLUE_PIN, true);
                gpio_put(LED_RED_PIN, true);
                gpio_put(LED_GREEN_PIN, true);
                led_active = true; // Atualiza o estado de 'led_active' para verdadeiro.
                // Agenda um alarme para desligar o LED azul após 3 segundos.
                add_alarm_in_ms(3000, turn_off_blue_callback, NULL, false);
            }
        }

        sleep_ms(10); // Pausa para reduzir o uso da CPU.
    }

    return 0; // Retorno de 0, que nunca será alcançado devido ao loop infinito.
}
