#include "city.h"
#include <ctime>
#include <locale>

void CITY::logo(RENDER &Render) {
    Render.drawSymbolsOnScreen(80, 11, (char*)"                              ____", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 12, (char*)"                             /_ \\ \\", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 13, (char*)"                            /____\\_\\", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 14, (char*)"                            |____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 15, (char*)"                            |____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 16, (char*)"            __ ___       ___|____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 17, (char*)"          _/ ||   \\\\    |___|____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 18, (char*)"         |___||___||  __|___|____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 19, (char*)"         |___||___|| |__|___|____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 20, (char*)"         |___||___|| |__|___|____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 21, (char*)"      ___|___||___||    |___|____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 22, (char*)"     /____/|_||___||        |____| |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 23, (char*)"     |___| |_||___||        |____| | ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 24, (char*)"     |___| |_|/___|/        |    |/ ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 25, (char*)"     |___|/", DarkGray, Black);
}

CITY::CITY() {
    name = (char*)"городская сеть";
    countStation = 775;
}
void CITY::welcome(RENDER &Render) {
    logo(Render);

    Render.writeText(1, 8, 50, (char*)"ОБНАРУЖЕНЫ НОВЫЕ УСТРОЙСТВА [775]! ^n\
                                В СЕТИ \"MAN17\" ^n\
                                ... ^n\
                                СКАННИРОВАНИЕ...НАЙДЕНО 17 РАЗНЫХ АНТИВИРУСОВ ^n ^n\
                                Взлом антивируса:", Green, Black);

    Render.draw();

}

void CITY::hack(RENDER &Render) {

    unsigned short cells[4][4];
    unsigned short maxValue = 0;
    unsigned short input;
    unsigned short dropx, dropy;

    bool isEmpty = false;

    char buffer[4];

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cells[i][j] = 0;
        }
    }

    srand(time(0));

    do {

        isEmpty = false;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(cells[i][j] == 0) {
                    isEmpty = true;
                }
            }
        }

        if(isEmpty == false) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    cells[i][j] = 0;
                }
            }
        }

        do {
            dropx = rand() % 4;
            dropy = rand() % 4;
        }while(cells[dropy][dropx] != 0);

        cells[dropy][dropx] = 2;

        setlocale(LC_ALL, "C");

        Render.clearArea(3, 16, 30, 10, Black, Black);

        for(int i = 0; i < 28; i++) {
            if(i % 7 == 0 && i != 0) {
                Render.addSymbol(i + 3, 16, char(194), DarkGray, Black);
            }
            else {
                Render.addSymbol(i + 3, 16, char(196), DarkGray, Black);
            }
        }
        Render.addSymbol(3, 16, char(218), DarkGray, Black);
        Render.addSymbol(31, 16, char(191), DarkGray, Black);

        unsigned short offsety = 0;

        for(int i = 0; i < 4; i++) {

            for(int j = 0; j < 4; j++) {

                Render.addSymbol(j * 7 + 3, i + 17 + offsety, char(179) , DarkGray, Black);
                if(cells[i][j] == 0) {
                    Render.writeLine(j * 7 + 5, i + 17 + offsety, "    ", LightGray, Black);
                }
                else {
                    sprintf(buffer, "%hu", cells[i][j]);
                    Render.writeLine(j * 7 + 5, i + 17 + offsety, buffer, LightGray, Black);
                }
            }

            Render.addSymbol(31, i + 17 + offsety, char(179) , DarkGray, Black);
            Render.addSymbol(3, i + 18 + offsety, char(195) , DarkGray, Black);

            for(int j = 1; j < 28; j++) {
                if(j % 7 == 0 && j != 0) {
                    if(i != 3)
                        Render.addSymbol(j + 3, i + 18 + offsety, char(197) , DarkGray, Black);
                    else
                        Render.addSymbol(j + 3, i + 18 + offsety, char(193) , DarkGray, Black);
                }
                else {
                    Render.addSymbol(j + 3, i + 18 + offsety, char(196) , DarkGray, Black);
                }
            }
            Render.addSymbol(31, i + 18 + offsety, char(180) , DarkGray, Black);
            offsety++;
        }

        Render.draw();

        bool down = false;

        do {
            input = getch();

            if(input == 80) {
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 4; j++) {
                        if(cells[i][j] == cells[i + 1][j]) {
                            cells[i][j] = 0;
                            cells[i + 1][j] *= 2;
                        }
                        else if(cells[i + 1][j] == 0) {
                            cells[i + 1][j] = cells[i][j];
                            cells[i][j] = 0;
                        }
                    }
                }
                down = true;
            }
            else if(input == 72) {
                for(int i = 3; i > 0; i--) {
                    for(int j = 0; j < 4; j++) {
                        if(cells[i][j] == cells[i - 1][j]) {
                            cells[i][j] = 0;
                            cells[i - 1][j] *= 2;
                        }
                        else if(cells[i - 1][j] == 0) {
                            cells[i - 1][j] = cells[i][j];
                            cells[i][j] = 0;
                        }
                    }
                }
                down = true;
            }
            else if(input == 77) {
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(cells[i][j] == cells[i][j + 1]) {
                            cells[i][j] = 0;
                            cells[i][j + 1] *= 2;
                        }
                        else if(cells[i][j + 1] == 0) {
                            cells[i][j + 1] = cells[i][j];
                            cells[i][j] = 0;
                        }
                    }
                }
                down = true;
            }
            else if(input == 75) {
                for(int i = 0; i < 4; i++) {
                    for(int j = 3; j > 0; j--) {
                        if(cells[i][j] == cells[i][j - 1]) {
                            cells[i][j] = 0;
                            cells[i][j - 1] *= 2;
                        }
                        else if(cells[i][j - 1] == 0) {
                            cells[i][j - 1] = cells[i][j];
                            cells[i][j] = 0;
                        }
                    }
                }
                down = true;
            }
        }while(!down);

        for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    if(cells[i][j] < 0)
                        cells[i][j] = cells[i][j];
                }
        }

        for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    if(cells[i][j] > maxValue)
                        maxValue = cells[i][j];
                }
        }

    }while(maxValue < 256);

    setlocale(LC_ALL, "RUS");

    Render.writeLine(2, 28, (char*)"...ВЗЛОМАНО!", LightRed, Red);
    Render.draw();
    Sleep(3000);

}

void CITY::info(RENDER &Render, VIRUS &Virus) {
    unsigned short key;

        logo(Render);

        Render.writeLine(2, 8, (char*)"ПОИСК ЗАПИСЕЙ В СИСТЕМЕ...НАЙДЕНО:", Green, Black);

        Render.writeText(1, 10, 60, (char*)"1). Партия сложила свои права после кровавого бунта.\
                                    Настоящая сворачивает военную программу в пользу нейтралитета.\
                                    Ядерный потенциал снижается.", LightGray, Black);

        Render.writeText(1, 14, 60, (char*)"2). Введен безусловный основной доход для всех граждан! ^n \
                                    \"Долой безработицу и нищету\" - новый популярный слоган ^n \
                                    17-ого президента нашей державы.", LightGray, Black);

        Render.writeText(1, 18, 60, (char*)"3). На многих военных базах всё ещё стоит код ядерного ^n\
                                    удара, и при любой активности врага они будут запущены.", LightGray, Black);

        Render.writeLine(2, 22, (char*)"Какие записи отправить на базу: ", Brown, Black);
        Render.writeLine(34, 22, (char*)"[1]", LightRed, Red);
        Render.writeLine(38, 22, (char*)"[2]", LightRed, Red);
        Render.writeLine(42, 22, (char*)"[3]", LightRed, Red);
        Render.writeLine(46, 22, (char*)"[продолжить]", Black, Brown);

        Render.draw();

        Render.setColor(White, Black);

        do {
            key = getch();

            switch(key) {
                case 49: {
                    Render.writeLine(34, 22, (char*)"[1]", LightGreen, Green);
                    Virus.peace++;
                    Virus.sended++;
                    break;
                }
                case 50: {
                    Render.writeLine(38, 22, (char*)"[2]", LightGreen, Green);

                    Virus.sended++;
                    break;
                }
                case 51: {
                    Render.writeLine(42, 22, (char*)"[3]", LightGreen, Green);
                    Virus.sended++;
                    break;
                }
            }

            Render.draw();

        }while(key != 13);
}

void CITY::test() {
    printf("CITY\n");
}
