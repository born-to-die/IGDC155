#include "POST.h"

void POST::logo(RENDER &Render) {
    Render.writeLine(70, 11, (char*)"                _______________________    __", DarkGray, Black);
    Render.writeLine(70, 12, (char*)"                \\_____________________/   |__|", DarkGray, Black);
    Render.writeLine(70, 13, (char*)"                 |___Security_post___|     ||", DarkGray, Black);
    Render.writeLine(70, 14, (char*)"_________________|    ___________    |_____||", DarkGray, Black);
    Render.writeLine(70, 15, (char*)"|   _____\\* * * *|    |  |      |    |* * *||", DarkGray, Black);
    Render.writeLine(70, 16, (char*)"|   \\     \\* * * |    |  |      |    | * * ||", DarkGray, Black);
    Render.writeLine(70, 17, (char*)"|    \\_____\\* * *|    |  |      |    |* * *||", DarkGray, Black);
    Render.writeLine(70, 18, (char*)"|   _______ \\* * |    |__|______|    | * * ||", DarkGray, Black);
    Render.writeLine(70, 19, (char*)" \\         \\ |* *|                   |* * *||", DarkGray, Black);
    Render.writeLine(70, 20, (char*)"________(_) /* * |___________________| * * ||", DarkGray, Black);
}

POST::POST() {
    name = "сеть \"SECURITYNETWORK\"";
    countStation = 34;
}

void POST::welcome(RENDER &Render) {
    logo(Render);

    Render.writeText(1, 8, 50, (char*)"ОБНАРУЖЕНЫ НОВЫЕ УСТРОЙСТВА [34]! ^n\
                                В СЕТИ \"SECURITYNETWORK\ ^n\
                                ... ^n\
                                СКАННИРОВАНИЕ...НАЙДЕН АНТИВИРУС \"Каспийский\" ^n ^n\
                                Взлом антивируса:", Green, Black);
}

void POST::hack(RENDER &Render) {

    unsigned short digit;
    unsigned short offsety = 0;
    unsigned short guess;
    unsigned short content;
    unsigned short attempts;
    char digits[5];
    char answer[5];

    Render.writeText(1, 15, 65, (char*)"ДАННЫЕ ИЗ КРИПТО-МОДУЛЯ: ^n\
                                длина пароля = 4, список символов = [1, 2, 3], допустимы другие символы для проверки, \
                                пароль длиннее 4 символов приведет к ФАТАЛЬНОЙ ОШИБКИ (Серьезно, не нужно этого делать)", DarkGray, Black);

    Render.draw();

    Render.setCursor(true);
    srand(time(0));

    Render.setColor(White, Black);
    Render.gotoXY(2, 15);

    digits[4] = '\0';

    do {

        attempts = 6;

        for(int i = 0; i < 4; i++) {
            digits[i] = (1 + rand() % 3)+'0';
        }

        do {
            Render.gotoXY(2, 22 + offsety);
            printf("> ");
            scanf("%s", answer);
            Render.gotoXY(2, 23 + offsety);

            guess = 0;

            for(int i = 0; i < 4; i++) {
                if(answer[i] == digits[i])
                    guess++;
            }

            printf("%hu%s", guess, " угадано");

            offsety += 3;
            attempts--;
        }while(strcmp(answer, digits) != 0 && attempts !=0);

        if(strcmp(answer, digits) != 0) {
            Render.clearAreaOnScreen(2, 22, 65, 21, Black, Black);
            Render.writeLine(2, 20, (char*)"!!!СИСТЕМА СГЕНЕРИРОВАЛА НОВЫЙ ПАРОЛЬ!!!", Black, Red);
            Render.draw();
            Render.setColor(White, Black);
            offsety = 0;
        }

    } while(strcmp(answer, digits) != 0);

    Render.writeLine(2, 22 + offsety, (char*)"...ВЗЛОМАНО!", LightRed, Red);
    Render.draw();
    Sleep(3000);

}

void POST::info(RENDER &Render, VIRUS &Virus) {
    unsigned short key;

        logo(Render);

        Render.writeLine(2, 8, (char*)"ПОИСК ЗАПИСЕЙ В СИСТЕМЕ...НАЙДЕНО:", Green, Black);

        Render.writeText(1, 10, 60, (char*)"1). Получено сообщение, что через пост будут проходить фуры\
                                    с военным грузом. Пропускать всех, после идентификации. ^n\
                                    P.S. Похоже конфликт обостряется, всем прочесть \"ЯДЕРНЫЙ УДАР И ВЫ\"", LightGray, Black);

        Render.writeText(1, 15, 60, (char*)"2). Отныне для военного груза пост работает в только режиме въезда.\
                                    По приезду оных отметить их количество. В конце месяца предоставить отчет.", LightGray, Black);

        Render.writeText(1, 19, 60, (char*)"3). Недавнейший инцидент с ложным шпионом не должен выйти за границы поста.\
                                    Начальство тоже не должно знать. Убитого вывезти за границу и как полагается похоронить.\
                                    Боже, ты видешь, что мы натворили, да смилуется сердце твое. Храни нашу страну.", LightGray, Black);

        Render.writeLine(2, 25, (char*)"Какие записи отправить на базу: ", Brown, Black);
        Render.writeLine(34, 25, (char*)"[1]", LightRed, Red);
        Render.writeLine(38, 25, (char*)"[2]", LightRed, Red);
        Render.writeLine(42, 25, (char*)"[3]", LightRed, Red);
        Render.writeLine(46, 25, (char*)"[продолжить]", Black, Brown);

        Render.draw();

        Render.setColor(White, Black);

        do {
            key = getch();

            switch(key) {
                case 49: {
                    Render.writeLine(34, 25, (char*)"[1]", LightGreen, Green);
                    Virus.sended++;
                    break;
                }
                case 50: {
                    Render.writeLine(38, 25, (char*)"[2]", LightGreen, Green);
                    Virus.peace++;
                    Virus.sended++;
                    break;
                }
                case 51: {
                    Render.writeLine(42, 25, (char*)"[3]", LightGreen, Green);
                    Virus.sended++;
                    break;
                }
            }

            Render.draw();

        }while(key != 13);
}

void POST::test() {
    printf("POST\n");
}
