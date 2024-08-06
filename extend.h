#ifndef EXTEND_H
#define EXTEND_H

#include <stdio.h>
#include <windows.h>
#include <stdarg.h>

// Definições de cores de texto
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

// Definições de cores de fundo
#define BG_BLACK 0
#define BG_BLUE BACKGROUND_BLUE
#define BG_GREEN BACKGROUND_GREEN
#define BG_CYAN (BACKGROUND_BLUE | BACKGROUND_GREEN)
#define BG_RED BACKGROUND_RED
#define BG_MAGENTA (BACKGROUND_BLUE | BACKGROUND_RED)
#define BG_BROWN (BACKGROUND_RED | BACKGROUND_GREEN)
#define BG_LIGHTGRAY (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED)
#define BG_DARKGRAY BACKGROUND_INTENSITY
#define BG_LIGHTBLUE (BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BG_LIGHTGREEN (BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_LIGHTCYAN (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_LIGHTRED (BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_LIGHTMAGENTA (BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_YELLOW (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_WHITE (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY)

// Função auxiliar para imprimir no console
void print_to_console(const char* message) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwCharsWritten;
    WriteConsole(hConsole, message, strlen(message), &dwCharsWritten, NULL);
}

// Função para imprimir múltiplos argumentos
void print(const char* format, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    print_to_console(buffer);
}

// Função para imprimir múltiplos argumentos com nova linha
void println(const char* format, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    print_to_console(buffer);
    print_to_console("\n");
}

// Função para mudar a cor do console
void color(WORD* Attributes, DWORD Colour) {
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

// Função para resetar a cor do console
void resetcolor(WORD Attributes) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, Attributes);
}

#endif // EXTEND_H
