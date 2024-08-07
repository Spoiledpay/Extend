# Extend.h e Graphic.h

`Extend.h` é uma biblioteca C para facilitar a manipulação de cores no console do Windows e a impressão de mensagens formatadas. Esta biblioteca fornece funções para mudar a cor do texto e do fundo, além de funções auxiliares para impressão.

`graphic.h`A nova biblioteca gráfica, composta pelos arquivos graphic.h e graphic.c, fornece uma interface simples para criar e manipular uma janela gráfica no ambiente Windows. Ela oferece funções para desenhar formas básicas como linhas e círculos com cores personalizadas, além de gerenciar a janela gráfica.

# Biblioteca texto em C

Esta biblioteca fornece funções para mudar a cor do texto e do fundo, além de funções auxiliares para impressão.

## Funcionalidades

- Mudar a cor do texto e do fundo no console.
- Imprimir mensagens formatadas no console.
- Resetar a cor do console para a cor original.

## Instalação

Para usar a biblioteca `Extend.h`, basta incluir o arquivo `extend.h` no seu projeto:


#include "extend.h"

Uso
Mudança de Cor
Você pode mudar a cor do texto e do fundo usando a função color e resetar a cor original com a função resetcolor.

```c
#include "extend.h"

int main() {
    WORD Attributes = 0;

    // Muda a cor do texto para branco com fundo preto
    color(&Attributes, WHITE | BG_BLACK);
    println("Texto em branco com fundo preto");
    resetcolor(Attributes);

    // Muda a cor do texto para verde com fundo azul
    color(&Attributes, GREEN | BG_BLUE);
    println("Texto verde com fundo azul");
    resetcolor(Attributes);

    return 0;
}

```
Impressão de Mensagens
A biblioteca fornece funções para imprimir mensagens formatadas no console:
print: Imprime uma mensagem formatada.

```c
println: Imprime uma mensagem formatada seguida de uma nova linha.
print("valor de var1 = %d\n", var1);
println("valor de var2 = %d", var2);
```

Definições de Cores
A biblioteca define várias cores para texto e fundo:
```
Cores de Texto
BLACK
BLUE
GREEN
CYAN
RED
MAGENTA
BROWN
LIGHTGRAY
DARKGRAY
LIGHTBLUE
LIGHTGREEN
LIGHTCYAN
LIGHTRED
LIGHTMAGENTA
YELLOW
WHITE
Cores de Fundo
BG_BLACK
BG_BLUE
BG_GREEN
BG_CYAN
BG_RED
BG_MAGENTA
BG_BROWN
BG_LIGHTGRAY
BG_DARKGRAY
BG_LIGHTBLUE
BG_LIGHTGREEN
BG_LIGHTCYAN
BG_LIGHTRED
BG_LIGHTMAGENTA
BG_YELLOW
BG_WHITE
```
#include "Extend.h"

```
int main() {
    WORD attributes;
    color(&attributes, RED | BG_WHITE);
    println("Texto em vermelho com fundo branco");
    resetcolor(attributes);
    println("Texto com cor padrão");
    return 0;
}
```

# Biblioteca Gráfica em C

Esta biblioteca gráfica fornece uma interface simples para criar e manipular uma janela gráfica no ambiente Windows usando a API GDI. Ela permite desenhar formas básicas como linhas e círculos, além de gerenciar a janela gráfica.

## Funcionalidades

### 1. `gwindows(int width, int height, COLORREF color)`
Cria uma janela gráfica com as dimensões especificadas e uma cor de fundo.

- **Parâmetros:**
  - `width`: Largura da janela em pixels.
  - `height`: Altura da janela em pixels.
  - `color`: Cor de fundo da janela, especificada como um valor `COLORREF` (ex.: `RGB(255, 255, 255)` para branco).

### 2. `setcolor(COLORREF color)`
Define a cor atual para desenho de formas.

- **Parâmetro:**
  - `color`: Cor a ser definida para o desenho, especificada como um valor `COLORREF`.

### 3. `line(int x1, int y1, int x2, int y2)`
Desenha uma linha com a cor atual de `(x1, y1)` até `(x2, y2)`.

- **Parâmetros:**
  - `x1, y1`: Coordenadas do ponto inicial da linha.
  - `x2, y2`: Coordenadas do ponto final da linha.

### 4. `circle(int x, int y, int radius)`
Desenha um círculo com a cor atual, centrado em `(x, y)` e com o raio especificado.

- **Parâmetros:**
  - `x, y`: Coordenadas do centro do círculo.
  - `radius`: Raio do círculo.

### 5. `closegraph()`
Fecha a janela gráfica.

### 6. `process_messages()`
Processa as mensagens da fila de mensagens do Windows, necessário para manter a janela gráfica responsiva.

## Estrutura Interna

A biblioteca utiliza uma estrutura interna para gerenciar as formas desenhadas (linhas e círculos) e suas respectivas cores. As formas são armazenadas em arrays e desenhadas durante o processamento de mensagens do Windows.

- **Armazenamento de Formas:**
  - Linhas e círculos são armazenados em arrays `lines` e `circles` com tamanho máximo definido por `MAX_SHAPES`.
  - Cada linha e círculo possui sua cor associada, permitindo a definição de cores diferentes para cada forma desenhada.

- **Desenho de Formas:**
  - O desenho das formas é realizado na função de callback `WindowProc` associada à janela gráfica. Durante o evento `WM_PAINT`, as formas armazenadas são desenhadas na janela usando GDI (Graphics Device Interface) do Windows.

## Exemplo de Uso

```c
#include "graphic.h"
#include <windows.h>

int main() {
    gwindows(800, 600, WHITE); // Cria uma janela gráfica 800x600 com fundo branco

    setcolor(RED); // Define a cor para vermelho
    circle(200, 200, 100); // Desenha um círculo vermelho

    setcolor(BLUE); // Define a cor para azul
    circle(200, 200, 80); // Desenha um círculo azul

    setcolor(YELLOW); // Define a cor para amarelo
    circle(200, 200, 60); // Desenha um círculo amarelo

    setcolor(BROWN); // Define a cor para marrom
    circle(200, 200, 40); // Desenha um círculo marrom

    setcolor(GREEN); // Define a cor para verde
    line(50, 50, 300, 300); // Desenha uma linha verde de (50, 50) a (300, 300)

    setcolor(GREEN); // Define a cor para branco
    rectangle(150, 180, 250, 300); // Desenha um retângulo branco

    // Loop de mensagens para manter a janela aberta até que o usuário a feche
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
```
```
tcc -o graphic_example.exe graphic.c main.c -lgdi32 -luser32
```


Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests.

Licença
Este projeto está licenciado sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.
