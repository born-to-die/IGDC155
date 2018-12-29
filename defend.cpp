#include "DEFEND.h"
#include <ctime>
#include <locale>

void DEFEND::logo(RENDER &Render) {
    Render.drawSymbolsOnScreen(80, 11, (char*)"             |", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 12, (char*)"            /|\\", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 13, (char*)"           |_|_| ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 14, (char*)"          /|_|_|\\", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 15, (char*)"         | |_|_| | ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 16, (char*)"         | |_|_| | ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 17, (char*)"        /| |_|_| |\\", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 18, (char*)"        || /_|_\\ ||", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 19, (char*)"        |||__|__||| ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 20, (char*)"        |||__|__||| ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 21, (char*)"       /|||__|__|||\\ ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 22, (char*)"       |||/__|__\\|||  ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 23, (char*)"       |||___|___||| ", DarkGray, Black);
    Render.drawSymbolsOnScreen(80, 24, (char*)"    |__|||___|___|||__|  ", DarkGray, Black);
}

DEFEND::DEFEND() {
    name = (char*)"сеть обороны (Министерство Обороны)";
    countStation = 145;
}
void DEFEND::welcome(RENDER &Render) {
    logo(Render);

    Render.writeText(1, 8, 50, (char*)"ОБНАРУЖЕНЫ НОВЫЕ УСТРОЙСТВА [145]! ^n\
                                В СЕТИ \"ARPJET\" ^n\
                                ... ^n\
                                СКАННИРОВАНИЕ...НАЙДЕНЫ НЕИЗВЕСТНЫЕ АНТИВИРУСЫ ^n ^n\
                                Взлом антивируса:", Green, Black);

    Render.draw();

}

void DEFEND::hack(RENDER &Render) {

    unsigned short enter[] = {0, 0, 0, 0};
    unsigned short answer[4];
    unsigned short current = 0;
    bool equaled = false;

    srand(time(0));

    for(int i = 0; i < 4; i++) {
        answer[i] = rand() % 5;
    }

    Render.writeText(2, 22, 60, (char*)"РАСШИФРОВКА МЕТАДАННЫХ ПРОТОКОЛА ЗАЩИТЫ... ^n Черт, чел, я придумал шикарный алгоритм шифровки!\
                                Смотри, нужно левое число сделать равным правому. Каждую цифру в этом числе можно уменьшать и увеличивать.\
                                При этом единица отнимается/прибавляется от цифры, стоящей на месте, обозначаемом той цифрой, от/к которой\
                                уменьшается/прибавляется единица. Звучит сложно, но ты просто попробуй!", DarkGray, Black);


    while(!equaled) {

        Render.clearArea(2, 16, 4, 3, Black, Black);
        Render.writeLine(6, 17, (char*)" -> ", LightGray, Black);
        Render.draw();
        Render.setColor(LightGray, Black);

        for(int i = 0; i < 4; i++) {
            Render.gotoXY(2 + i, 17);
            printf("%hu", enter[i]);
            Render.gotoXY(10 + i, 17);
            printf("%hu", answer[i]);

        }

        Render.addSymbol(2 + current, 16, '^', LightGray, Black);
        Render.addSymbol(2 + current, 18, 'V', LightGray, Black);
        Render.draw();

        switch(getch()) {
            case 77: {
                if(current != 3)
                    current++;
                break;
            }
            case 75: {
                if(current != 0)
                    current--;
                break;
            }
            case 72: {
                if(enter[current] != 0) {

                    if(enter[enter[current] - 1] == 0)
                        enter[enter[current] - 1] = 4;
                    else
                        enter[enter[current] - 1]--;

                    if(enter[current] == 4)
                        enter[current] = 0;
                    else
                        enter[current]++;
                }
                else {
                    enter[current] = 1;
                }
                    break;

            }
            case 80: {
                if(enter[current] != 0) {

                    if(enter[enter[current] - 1] == 4)
                        enter[enter[current] - 1] = 0;
                    else
                        enter[enter[current] - 1]++;

                    if(enter[current] == 0)
                        enter[current] = 4;
                    else
                        enter[current]--;
                }
                else {
                    enter[current] = 4;
                }
                    break;

            }
            case 13: {

                current = 0;

                for(int i = 0; i < 4; i++) {
                    answer[i] = rand() % 5;
                    enter[i] = 0;
                }

                break;
            }
        }

        equaled = true;

        for(int i = 0; i < 4; i++) {
            if(enter[i] != answer[i])
                equaled = false;
        }
    }

    Render.clearArea(2, 16, 4, 3, Black, Black);
    Render.writeLine(6, 17, " -> ", LightGray, Black);
    Render.draw();
    Render.setColor(LightGray, Black);

    for(int i = 0; i < 4; i++) {
        Render.gotoXY(2 + i, 17);
        printf("%hu", enter[i]);
        Render.gotoXY(10 + i, 17);
        printf("%hu", answer[i]);
    }

    Render.writeLine(2, 19, (char*)"...ВЗЛОМАНО!", LightRed, Red);
    Render.draw();
    Sleep(3000);

}

void DEFEND::info(RENDER &Render, VIRUS &Virus) {
    unsigned short key;

        logo(Render);

        Render.writeLine(2, 8, (char*)"ПОИСК ЗАПИСЕЙ В СИСТЕМЕ...НАЙДЕНО:", Green, Black);

        Render.writeText(1, 10, 60, (char*)"1). По результату 49 собрания военно-политической сферы\
                                    на следующую агрессию со стороны врага активирить программу\
                                    \"ЯДЕРНЫЕ КАНИКУЛЫ\"!", LightGray, Black);

        Render.writeText(1, 14, 60, (char*)"2). Свернуть военную программу! Полный нейтралитет. ^n \
                                    Приказ от новой партии!", LightGray, Black);

        Render.writeText(1, 17, 60, (char*)"3). Весь ядерный потенциал снять и захоронить!", LightGray, Black);

        Render.writeLine(2, 20, (char*)"Какие записи отправить на базу: ", Brown, Black);
        Render.writeLine(34, 20, (char*)"[1]", LightRed, Red);
        Render.writeLine(38, 20, (char*)"[2]", LightRed, Red);
        Render.writeLine(42, 20, (char*)"[3]", LightRed, Red);
        Render.writeLine(46, 20, (char*)"[продолжить]", Black, Brown);

        Render.draw();

        Render.setColor(White, Black);

        do {
            key = getch();

            switch(key) {
                case 49: {
                    Render.writeLine(34, 20, (char*)"[1]", LightGreen, Green);
                    Virus.sended++;
                    break;
                }
                case 50: {
                    Render.writeLine(38, 20, (char*)"[2]", LightGreen, Green);
                    Virus.peace++;
                    Virus.sended++;
                    break;
                }
                case 51: {
                    Render.writeLine(42, 20, (char*)"[3]", LightGreen, Green);
                    Virus.peace++;
                    Virus.sended++;
                    break;
                }
            }

            Render.draw();

        }while(key != 13);
}

void DEFEND::test() {
    printf("DEFEND\n");
}
