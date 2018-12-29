#include <windows.h>
#include <clocale>

#include "room.h"
#include "truck.h"
#include "post.h"
#include "city.h"
#include "defend.h"
#include "sub.h"

void logoby(RENDER &Render) {
    Render.clear('.', Green, Black);
    Render.writeLine(53, 29, (char*)"—ѕ≈÷»јЋ№Ќќ ƒЋя IGDC 155", Black, Green);
    Render.writeLine(55, 24, (char*)" Playing Crab & Tem", Black, Green);
    Render.draw();
    getch();
    Render.clear(Black);
    Render.draw();
}

int main()
{

    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxWindow = GetLargestConsoleWindowSize(out_handle); // размер самого большого возможного консольного окна
    maxWindow.X = 128;
    maxWindow.Y = 45;
    SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
    SMALL_RECT minWindow = { 0, 0, maxWindow.X , maxWindow.Y};
    SetConsoleWindowInfo(out_handle, true, &minWindow);
    SetConsoleScreenBufferSize(out_handle, maxWindow);
    SetConsoleWindowInfo(out_handle, true, &srctWindow);

    setlocale(LC_ALL, "RUS");
    system("title The history of one virus");

    RENDER Render(true);
    Render.setCursor(false);

    logoby(Render);

    ROOM *currentroom;

    TRUCK Truck;
    POST Post;
    CITY City;
    DEFEND Defend;

    Truck.setNext(Post);
    Post.setNext(City);
    City.setNext(Defend);

    unsigned short countMap = 1;

    VIRUS Virus;

    bool run = true;

    currentroom = &Truck;

    do{

        drawGUI(Render, Virus, currentroom);

        currentroom->welcome(Render);

        currentroom->hack(Render);

        Render.clearArea(2, 8, 65, 30, Black, Black);
        Render.setColor(Black, Black);
        Render.clearAreaOnScreen(2, 8, 65, 36, Black, Black);
        Render.draw();

        currentroom->info(Render, Virus);

        Render.clearArea(2, 8, 65, 30, Black, Black);
        Render.setColor(Black, Black);
        Render.clearAreaOnScreen(2, 8, 65, 30, Black, Black);
        Render.draw();

        if(countMap != 1)
            Virus.detect(currentroom->countStation, countMap);

        if(countMap == 4 && Virus.detected < Virus.infected) {
            run = false;
        }
        else if(Virus.detected > Virus.infected) {
            run = false;
        }
        else if(Virus.signatures < Virus.needSignatures) {
            run = false;
        }
        else {
            drawGUI(Render, Virus, currentroom);

            currentroom->logo(Render);

            Virus.upgrade(Render);

            currentroom = currentroom->nextroom;

            countMap++;
        }

        Render.setColor(Black, Black);
        system("cls");

    }while(run);

    Virus.theend(Render);

    //if(theEnd) {
        //if(Virus.)
    //}

    return 0;
}
