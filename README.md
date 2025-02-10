#  Comunicação Serial com RP2040 usando BitDogLab

Este projeto explora o uso de periféricos do RP2040, combinando comunicação serial (UART e I2C) com a manipulação de dispositivos como display OLED SSD1306, matriz de LEDs WS2812, LED RGB e botões. A interação é feita através do monitor serial do VS Code, proporcionando uma experiência interativa.

##  Metas

*   ✅ Dominar a comunicação UART e I2C no RP2040.
*   ✨ Controlar LEDs WS2812 e LED RGB de forma eficiente.
*   ⚙️ Implementar tratamento de interrupções (IRQ) e debounce para botões.
*   ️ Exibir informações no display SSD1306 e na matriz WS2812.
*    Desenvolver um código modular, organizado e bem documentado.

## ⚙️ Componentes

*   **️ Display SSD1306:** (I2C - GPIOs 14 e 15)
*   ** Matriz 5x5 de LEDs WS2812:** (GPIO 7)
*   **🟢 LED RGB:** (GPIOs 11, 12 e 13)
*   ** Botão A:** (GPIO 5)
*   ** Botão B:** (GPIO 6)

## ✨ Funcionalidades

1.  ** Biblioteca `font.h` Aprimorada:**

    *   Inclusão de caracteres minúsculos para exibição no display SSD1306.

2.  **⌨️ Entrada de Dados via Serial:**

    *   Digite caracteres no monitor serial para visualizá-los no display SSD1306.
    *   Números de 0 a 9 acionam a matriz WS2812, exibindo símbolos correspondentes.

3.  ** Interação com Botões:**

    *   **Botão A:** Alterna o LED Verde (GPIO 11) e exibe o estado no monitor serial e display.
    *   **Botão B:** Alterna o LED Azul (GPIO 12) e exibe o estado no monitor serial e display.
    *   Implementação via interrupção (IRQ) e debounce para maior confiabilidade.

## ️ Estrutura do Projeto

comunicacao-serial-rp2040/
├── build/                      # Arquivos de compilação
├── lib/                        # Bibliotecas e cabeçalhos
│   ├── animacoes.h
│   ├── botao.h
│   ├── font.h
│   ├── led-rgb.h
│   ├── matriz-led.h
│   ├── ssd1306.h
├── src/                        # Código fonte
│   ├── animacoes.c
│   ├── botao.c
│   ├── led-rgb.c
│   ├── matriz-led.c
│   ├── ssd1306.c
├── main.c                      # Código principal
├── ws2812.pio                  # Código PIO para matriz de LEDs
├── CMakeLists.txt               # Configuração do CMake
├── pico_sdk_import.cmake        # Importação do SDK do Pico
├── wokwi.toml                   # Configuração para simulação no Wokwi
└── README.md                    # Documentação


##  Execução

### ️ Pré-requisitos

*   Placa RP2040 (e.g., Raspberry Pi Pico)
*   SDK do Pico instalado
*   Ambiente de desenvolvimento configurado (e.g., VS Code com PICO-GO)

### ⚙️ Passos

1.  Clone o repositório:

    ```bash
    git clone <link_para_o_seu_repositorio>
    cd comunicacao-serial-rp2040
    ```

2.  Compile o projeto:

    ```bash
    mkdir build && cd build
    cmake ..
    ninja
    ```

3.  Flashe o código para a placa:

    ```bash
    picotool load -x comunicacao-serial-rp2040.uf2
    ```

4.  Abra o monitor serial para interagir.

##  Recursos

*   **Pico SDK:** <https://github.com/raspberrypi/pico-sdk>


##  Demonstração

[Link para o vídeo de demonstração no YouTube]

##  Simulação

[[Link para a simulação no Wokwi]](https://wokwi.com/projects/422467626758478849)

## ‍ Autor

[![Danilo Lacerda](https://github.com/DaanLacerdaa.png?size=100)](https://github.com/DaanLacerdaa)

