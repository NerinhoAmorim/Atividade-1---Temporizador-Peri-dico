# Temporizador de um Disparo (One Shot) para Acionamento de LEDs

Este projeto implementa um sistema de temporização para o acionamento de LEDs utilizando a função `add_alarm_in_ms()` da Pico SDK. O sistema é acionado por um botão (pushbutton) e controla três LEDs (azul, vermelho e verde) em uma sequência específica.

## Componentes Necessários

- Microcontrolador Raspberry Pi Pico W
- 3 LEDs (azul, vermelho e verde)
- 3 Resistores de 330 Ω
- 1 Botão (Pushbutton)
- Placa de prototipagem (Breadboard)
- Fios de conexão

## Circuito

Conecte os componentes conforme a descrição abaixo:

- **LED Azul:** 
  - Ânodo no GPIO 11 (via resistor de 330 Ω)
  - Cátodo no GND
- **LED Vermelho:** 
  - Ânodo no GPIO 12 (via resistor de 330 Ω)
  - Cátodo no GND
- **LED Verde:** 
  - Ânodo no GPIO 13 (via resistor de 330 Ω)
  - Cátodo no GND
- **Botão (Pushbutton):**
  - Um terminal no GPIO 5
  - Outro terminal no GND

## Configuração do VSCode com Extensão para Raspberry Pi Pico

### Passo 1: Instale o Visual Studio Code

Caso ainda não tenha o Visual Studio Code instalado, faça o download e instale a partir do site oficial: [Visual Studio Code](https://code.visualstudio.com/).

### Passo 2: Instale a Extensão do Pico SDK

1. Abra o Visual Studio Code.
2. Vá para a aba de Extensões (ícone de quadrado no painel à esquerda).
3. Pesquise por "Raspberry Pi Pico SDK" e instale a extensão correspondente.

### Passo 3: Configure o Ambiente de Desenvolvimento

1. Instale o [Pico SDK](https://github.com/raspberrypi/pico-sdk) no seu ambiente de desenvolvimento.
2. Configure o ambiente de desenvolvimento conforme as instruções do Pico SDK.

### Passo 4: Clone o Repositório e Abra no VSCode

1. Baixe ou clone este repositório no seu ambiente local:
    ```sh
    git clone https://github.com/NerinhoAmorim/ClockeTemporizadores.git
    ```

## Funcionamento

- Quando o botão é pressionado, todos os LEDs (azul, vermelho e verde) são acesos.
- Após 3 segundos, o LED azul é desligado.
- Após mais 3 segundos, o LED vermelho é desligado.
- Finalmente, após mais 3 segundos, o LED verde é desligado.
- O botão só pode ser pressionado novamente após todos os LEDs serem desligados.

## Autor

Este projeto foi desenvolvido por [Nerinho Amorim](https://github.com/NerinhoAmorim).