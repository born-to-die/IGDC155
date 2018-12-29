#include "render.h"

RENDER::RENDER(bool active_draw) {
    this->active_draw = active_draw;
}

/// ### DRAW ON THE BACK BUFFER ###

void RENDER::draw() {

    for(int i = 0; i < render_height; i++) {
        for(int j = 0; j < render_width; j++) {
            if(screen_buffer[i][j].symbol != back_buffer[i][j].symbol ||
                screen_buffer[i][j].sycolor != back_buffer[i][j].sycolor ||
                screen_buffer[i][j].bgcolor != back_buffer[i][j].bgcolor) {
                    screen_buffer[i][j].symbol = back_buffer[i][j].symbol;
                    screen_buffer[i][j].sycolor = back_buffer[i][j].sycolor;
                    screen_buffer[i][j].bgcolor = back_buffer[i][j].bgcolor;
                    drawSymbolOnScreen(j, i, screen_buffer[i][j].symbol, screen_buffer[i][j].sycolor, screen_buffer[i][j].bgcolor);
            }
        }
    }
    gotoXY(0, 0);
}

void RENDER::writeLine(int x, int y, char *text, color textColor, color bgColor) {
    unsigned short i = 0;
    while(text[i] != '\0') {
        addSymbol(x + i, y, text[i], textColor, bgColor);
        i++;
    }
}

void RENDER::writeText(int x, int y, unsigned short width, char *text, color textColor, color bgColor) {

    unsigned short counts = 0;
    unsigned short offset = 0;
    char dels[] = " ";
    char *wrds;

    while(text[counts++] != '\0') {

    }

    char newtext[counts];

    for(int i = 0; i < counts; i++) {
        newtext[i] = text[i];
    }

    counts = 0;
    wrds = strtok(newtext, dels);


    while(wrds) {

        if(strlen(wrds) + counts > width) {
            offset++;
            counts = 0;
        }

        if(wrds[0] == '^' && wrds[1] == 'n') {
            offset++;
            counts = 0;
        }
        else if(wrds[0] == '^' && wrds[1] == 's') {

            unsigned short spaces = atoi(&wrds[2]);
            counts += spaces;

        }
        else {

            addSymbol(x + counts, y + offset, ' ', textColor, bgColor);
            writeLine(x + counts + 1, y + offset, wrds, textColor, bgColor);
            counts += (strlen(wrds) + 1);
        }
        wrds = strtok(NULL, dels);
    }
}

void RENDER::addSymbol(int x, int y, char s, color cs, color bg) {
    back_buffer[y][x].symbol = s;
    back_buffer[y][x].sycolor = cs;
    back_buffer[y][x].bgcolor = bg;
}

/// ### COLOR ###

void RENDER::resetColor() {
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
}

void RENDER::setColor(color syColor, color bgColor) {
    SetConsoleTextAttribute(hConsole, (WORD) ((bgColor << 4) | syColor));
}

/// ### CURSOR ###

void RENDER::setCursor(bool visible) {
    CONSOLE_CURSOR_INFO CCI;
    CCI.bVisible = visible;
    CCI.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CCI);
}

void RENDER::gotoXY(int x, int y) {
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position);
}

/// ### CLEAR BUFFER ###

void RENDER::clear() {
    for(int i = 0; i < render_height; i++) {
        for(int j = 0; j < render_width; j++) {
            back_buffer[i][j].symbol = char(0);
            back_buffer[i][j].sycolor = Black;
            back_buffer[i][j].bgcolor = Black;
        }
    }
}

void RENDER::clear(char symbol, color syColor, color bgColor) {
    for(int i = 0; i < render_height; i++) {
        for(int j = 0; j < render_width; j++) {
            back_buffer[i][j].symbol = symbol;
            back_buffer[i][j].sycolor = syColor;
            back_buffer[i][j].bgcolor = bgColor;
        }
    }
}

void RENDER::clear(color bgColor) {
    for(int i = 0; i < render_height; i++) {
        for(int j = 0; j < render_width; j++) {
            back_buffer[i][j].symbol = char(176);
            back_buffer[i][j].sycolor = Black;
            back_buffer[i][j].bgcolor = bgColor;
        }
    }
}

void RENDER::clearArea(unsigned short x, unsigned short y, unsigned short width, unsigned short height, color colorText, color colorBack) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            back_buffer[y + i][x + j].symbol = char(176);
            back_buffer[y + i][x + j].sycolor = colorText;
            back_buffer[y + i][x + j].bgcolor = colorBack;
        }
    }
}

void RENDER::delSymbol(int x, int y) {
    addSymbol(x, y, char(176), Black, LightMagenta);
    drawSymbolOnScreen(x, y, char(176), Black, LightMagenta);
}

/// ### DIRECT DRAW ###

void RENDER::drawSymbolOnScreen(int x, int y, char symbol, color color_text, color bg_color) {
    position.X = x;
    position.Y = y;
    SetConsoleTextAttribute(hConsole, (WORD) ((bg_color << 4) | color_text));
    SetConsoleCursorPosition(hConsole, position);
    printf("%c", symbol);
}

void RENDER::drawSymbolsOnScreen(int x, int y, char* text, color color_text, color bg_color) {
    unsigned short i = 0;
    while(text[i] != '\0') {
        drawSymbolOnScreen(x + i, y, text[i], color_text, bg_color);
        i++;
    }
}

void RENDER::clearAreaOnScreen(unsigned short x, unsigned short y, unsigned short width, unsigned short height, color colorText, color colorBack) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            drawSymbolOnScreen(x + j, y + i, ' ', colorText, colorBack);
        }
    }
}
