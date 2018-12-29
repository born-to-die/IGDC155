#include "sub.h"

void drawGUI(RENDER &Render, VIRUS virus, ROOM *currentroom) {
    char buffer[4];

    Render.drawSymbolsOnScreen(0, 0, (char*)"Сигнатуры:   ", Black, Green);
    sprintf(buffer, "%d", virus.signatures);
    Render.drawSymbolsOnScreen(11, 0, buffer, Black, Green);
    Render.drawSymbolsOnScreen(13, 0, (char*)" | Заражено:    ", Black, Green);
    sprintf(buffer, "%d", virus.infected);
    Render.drawSymbolsOnScreen(26, 0, buffer, Black, Green);
    Render.drawSymbolsOnScreen(29, 0, (char*)" | Шифрование: ", Black, Green);
    sprintf(buffer, "%d", virus.crypto);
    Render.drawSymbolsOnScreen(44, 0, buffer, Black, Green);
    Render.drawSymbolsOnScreen(0, 3, (char*)"Текущая система: ", Black, Brown);
    Render.drawSymbolsOnScreen(17, 3, currentroom->name, LightGray, Brown);
    Render.drawSymbolsOnScreen(112, 0, (char*)"Обнаружено:    ", Black, Red);
    sprintf(buffer, "%d", virus.detected);
    Render.drawSymbolsOnScreen(124, 0, buffer, Black, Red);
    Render.drawSymbolsOnScreen(80, 0, (char*)"Отправлено:  ", Black, Brown);
    sprintf(buffer, "%d", virus.sended);
    Render.drawSymbolsOnScreen(92, 0, buffer, Black, Brown);
}
