#ifndef RENDER_H_INCLUDED
#define RENDER_H_INCLUDED

#define render_width 127
#define render_height 44

#include <windows.h>
#include <stdio.h>
#include "colors.h"

struct dots {

    char symbol;
    color sycolor;
    color bgcolor;

};

class RENDER {
private:

    COORD position;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    dots back_buffer[render_height][render_width];
    dots screen_buffer[render_height][render_width];

    int display_x, display_y;

    bool active_draw;

public:

    RENDER(bool active_draw);

    /// ### DRAW ON THE BACK BUFFER ###

    void draw();

	void writeLine(int x, int y, char *text, color textColor, color bgColor);

	void writeText(int x, int y, unsigned short width, char *text, color textColor, color bgColor);

	void addSymbol(int x, int y, char s, color cs, color bg);

	/// ### COLOR ###

	void resetColor();

	void setColor(color syColor, color bgColor);

	/// ### CURSOR ###

	void setCursor(bool visible);

	void gotoXY(int x, int y);

	/// ### CLEAR BUFFER ###
    void clear();

	void clear(char symbol, color syColor, color bgColor);

	void clear(color bgColor);

	void clearArea(unsigned short x, unsigned short y, unsigned short width, unsigned short height, color colorText, color colorBack);

	void delSymbol(int x, int y);

	/// ### DIRECT DRAW ###

	void drawSymbolOnScreen(int x, int y, char symbol, color color_text, color bg_color);

    void drawSymbolsOnScreen(int x, int y, char* text, color color_text, color bg_color);

    void clearAreaOnScreen(unsigned short x, unsigned short y, unsigned short width, unsigned short height, color colorText, color colorBack);

};

#endif // RENDER_H_INCLUDED
