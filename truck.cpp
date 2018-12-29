#include "truck.h"

void TRUCK::logo(RENDER &Render) {
    Render.drawSymbolsOnScreen(70, 11, (char*)" _________________________________", DarkGray, Black);
    Render.drawSymbolsOnScreen(70, 12, (char*)"|                        |   _____\\", DarkGray, Black);
    Render.drawSymbolsOnScreen(70, 13, (char*)"|                        |   \\     \\", DarkGray, Black);
    Render.drawSymbolsOnScreen(70, 14, (char*)"|                        |    \\_____\\", DarkGray, Black);
    Render.drawSymbolsOnScreen(70, 15, (char*)"|                        |   _______ \\", DarkGray, Black);
    Render.drawSymbolsOnScreen(70, 16, (char*)"|________________________|\\         \\ |", DarkGray, Black);
    Render.drawSymbolsOnScreen(70, 17, (char*)"  (_) (_)  *******  |____________(_) /", DarkGray, Black);
}

TRUCK::TRUCK() {
    name = (char*)"юникс-совместимая система ТракОС";
    countStation = 1;

}

void TRUCK::welcome(RENDER &Render) {
    logo(Render);

    Render.writeLine(2, 8, (char*)"Агент нашего государства передал накопитель с 'музыкой' водителю", LightGray, Black);
    Render.writeLine(2, 9, (char*)"фуры.", LightGray, Black);

    Render.writeLine(2, 11, (char*)"...ЗАГРУЗКА НА УСТРОЙСТВО ЗАВЕРШЕНА", Green, Black);
    Render.writeLine(2, 12, (char*)"ИНИЦИАЛИЗАЦИЯ...НАЙДЕН АНТИВИРУС 'Тесла-АВ'", Green, Black);
    Render.writeLine(2, 14, (char*)"Взлом антивируса:", Green, Black);
}

void TRUCK::hack(RENDER &Render) {
    short answer;
    bool hacked = false;

    Render.writeLine(2, 16, (char*)"x * x + 6 * x + 9 = 0", Red, Black);

    Render.writeLine(2, 18, (char*)"ЗНЧ x = ", Red, Black);

    Render.draw();

    Render.setCursor(true);

    do{
        Render.drawSymbolsOnScreen(10, 18, (char*)"                 ", LightGray, Black);

        Render.gotoXY(10, 18);

        scanf("%hu", &answer);

        if(answer == -3) {
            hacked = true;
        }
        else {
            Render.drawSymbolsOnScreen(10, 18, (char*)"ОШИБКА           ", LightGray, Black);
            Sleep(1000);
        }
    }while(!hacked);

    hacked = false;

    Render.writeLine(2, 20, (char*)"x * x - 2 * x - 3 = 0", Red, Black);

    Render.writeLine(2, 22, (char*)"ЗНЧ x = ", Red, Black);

    Render.draw();

    do{
        Render.drawSymbolsOnScreen(10, 22, (char*)"                 ", LightGray, Black);

        Render.gotoXY(10, 22);

        scanf("%hu", &answer);

        if(answer == 3 || answer == -1) {
            hacked = true;
        }
        else {
            Render.drawSymbolsOnScreen(10, 22, (char*)"ОШИБКА           ", LightGray, Black);
            Sleep(1000);
        }
    }while(!hacked);

    hacked = false;

    Render.writeLine(2, 24, (char*)"x * x + 2 * x - 48 = 0", Red, Black);

    Render.writeLine(2, 26, (char*)"ЗНЧ x = ", Red, Black);

    Render.draw();

    do{
        Render.drawSymbolsOnScreen(10, 26, (char*)"                 ", LightGray, Black);

        Render.gotoXY(10, 26);

        scanf("%hu", &answer);

        if(answer == -8 || answer == 6) {
            hacked = true;
        }
        else {
            Render.drawSymbolsOnScreen(10, 26, (char*)"ОШИБКА         ", LightGray, Black);
            Sleep(1000);
        }
    }while(!hacked);

    Render.setCursor(false);
    Render.writeLine(2, 28, (char*)"...ВЗЛОМАНО!", LightRed, Red);
    Render.draw();
    Sleep(3000);
}

void TRUCK::info(RENDER &Render, VIRUS &Virus) {
    unsigned short key;

    logo(Render);

    Render.writeLine(2, 8, (char*)"ПОИСК ЗАПИСЕЙ В СИСТЕМЕ...НАЙДЕНО:", Green, Black);

    Render.writeLine(2, 10, (char*)"1). Груз юнита: модули военной базы, зенитные орудия, боеголовки.", LightGray, Black);
    Render.writeLine(2, 11, (char*)"Место назначения груза: военный пункт юго-восточной базы ?$%@#$%", LightGray, Black);
    Render.writeLine(2, 12, (char*)"на границе вражеского государства.", LightGray, Black);

    Render.writeLine(2, 14, (char*)"2). Текущий статус груза: отменен. В связи с новым планом", LightGray, Black);
    Render.writeLine(2, 15, (char*)"внешней политики.", LightGray, Black);

    Render.writeLine(2, 17, (char*)"3). <ЭТА ЗАПИСЬ ПРЕДНАЗНАЧЕНА ДЛЯ АВТОМАТИЧЕСКОЙ ОТПРАВКИ>", LightGray, Black);
    Render.writeLine(2, 18, (char*)"Боже, Марта, только наша страна может доверить мне возить", LightGray, Black);
    Render.writeLine(2, 19, (char*)"такой груз. И если, что случится, то деньги в банке в погребе.", LightGray, Black);
    Render.writeLine(2, 20, (char*)"Я люблю тебя, и наших детей.", LightGray, Black);
    Render.writeLine(2, 21, (char*)"                                          твой Джимми.", LightGray, Black);

    Render.writeLine(2, 23, (char*)"Какие записи отправить на базу: ", Brown, Black);
    Render.writeLine(34, 23, (char*)"[1]", LightRed, Red);
    Render.writeLine(38, 23, (char*)"[2]", LightRed, Red);
    Render.writeLine(42, 23, (char*)"[3]", LightRed, Red);
    Render.writeLine(46, 23, (char*)"[продолжить]", Black, Brown);

    Render.draw();

    Render.setColor(White, Black);

    do {
        key = getch();

        switch(key) {
            case 49: {
                Render.writeLine(34, 23, (char*)"[1]", LightGreen, Green);
                Virus.sended++;
                break;
            }
            case 50: {
                Render.writeLine(38, 23, (char*)"[2]", LightGreen, Green);
                Virus.peace++;
                Virus.sended++;
                break;
            }
            case 51: {
                Render.writeLine(42, 23, (char*)"[3]", LightGreen, Green);
                Virus.sended++;
                break;
            }
        }

        Render.draw();

    }while(key != 13);
}

void TRUCK::test() {
    printf("TRUCK\n");
}
