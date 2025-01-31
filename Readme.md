# Semáforo com Temporizador Periódico

Este projeto implementa um semáforo simples utilizando um temporizador periódico na linguagem C para o microcontrolador Raspberry Pi Pico W. O semáforo altera as cores dos LEDs (vermelho, amarelo e verde) a cada 3 segundos e imprime o estado atual na porta serial.

## Componentes Necessários

- Microcontrolador Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo e verde)
- 3 Resistores de 330 Ω
- Placa de prototipagem (Breadboard)
- Fios de conexão

## Circuito

Conecte os componentes conforme a descrição abaixo:

- LED Vermelho: 
  - Ânodo no GPIO 11 (via resistor de 330 Ω)
  - Cátodo no GND
- LED Amarelo: 
  - Ânodo no GPIO 12 (via resistor de 330 Ω)
  - Cátodo no GND
- LED Verde: 
  - Ânodo no GPIO 13 (via resistor de 330 Ω)
  - Cátodo no GND

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
    git clone https://github.com/NerinhoAmorim/Atividade-1---Temporizador-Peri-dico
    ```
## Funcionamento

- O semáforo inicia com o LED vermelho aceso.
- A cada 3 segundos, o estado do semáforo muda na seguinte ordem: vermelho -> amarelo -> verde.
- A cada mudança de estado, o LED correspondente é aceso e o estado é impresso na porta serial.

## Autor

Este projeto foi desenvolvido por [Nerinho Amorim](https://github.com/NerinhoAmorim)
