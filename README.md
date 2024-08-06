# Extend.h

`Extend.h` é uma biblioteca C para facilitar a manipulação de cores no console do Windows e a impressão de mensagens formatadas. Esta biblioteca fornece funções para mudar a cor do texto e do fundo, além de funções auxiliares para impressão.

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
Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests.

Licença
Este projeto está licenciado sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.
