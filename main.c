#include "graphic.h"
#include <windows.h> // Para a função Sleep

int main() {
    gwindows(800, 600, RGB(255, 255, 255)); // Cria uma janela gráfica 800x600 com fundo branco

    setcolor(RGB(255, 0, 0)); // Define a cor para vermelho
    circle(200, 200, 100); // Desenha um círculo vermelho

    setcolor(RGB(0, 0, 255)); // Define a cor para azul
    circle(200, 200, 80); // Desenha um círculo azul

    setcolor(RGB(255, 255, 0)); // Define a cor para amarelo
    circle(200, 200, 60); // Desenha um círculo amarelo

    setcolor(RGB(165, 42, 42)); // Define a cor para marrom
    circle(200, 200, 40); // Desenha um círculo marrom
    
setcolor(RGB(255, 42, 42)); // Define a cor para marrom
    circle(300, 350, 40); // Desenha um círculo marrom

    // Loop de mensagens para manter a janela aberta até que o usuário a feche
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
