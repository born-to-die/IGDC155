#include "virus.h"

#include <ctime>

VIRUS::VIRUS() {
    infected = 1;
    signatures = 3;
    crypto = 1;
    detected = 0;
    sended = 0;
    strike = 0;
    peace = 0;
    addToCrypto = 0;
    addToDetected = 0;
    needCrypto = 0;
    needSignatures = 0;
    addIsActive = false;
}


void VIRUS::upgrade(RENDER &Render) {

    unsigned short sum = 10;
    unsigned short key;
    char buffer[2];

    Render.writeLine(2, 10, (char*)"���������� � �����...���������", Green, Black);
    Render.writeLine(2, 11, (char*)"����� ����������.....�������", Green, Black);
    Render.writeLine(5, 16, (char*)"���������    <    >    ����������", Yellow, Black);

    Render.writeText(2, 22, 80, (char*)"/* ��������� � ���������� ���������� ��� ����������� �������� ������.\
                                    ��������� - ���, ����� ������, �������� ������, � ��� ���������� ����\
                                     ��� ������ �����. � ������������ � ����������� ���������� ���������� �� ������.\
                                    �� ���� ���������, ���������� ����������� ������� ����� �������������.\
                                    �� ���� ����������� ����������� ����� �������, � �� ���� ���������� �����������\
                                    �������� ������� ����������, ��������� ���������� ������� �� ���������.\
                                    ^n ^n ^s9 ^s9 ^s9 ^s9 ^s8 ������� ����������� �.�.��������.*/\
                                    ", DarkGray, Black);
    do {

        sprintf(buffer, "%d", signatures);
        Render.writeLine(15, 16, buffer, Green, Black);
        sprintf(buffer, "%d", crypto);
        Render.writeLine(25, 16, buffer, Green, Black);

        sprintf(buffer, "%d", sum);

        if(sum > 9) {
            Render.writeLine(20, 16, buffer, Yellow, Black);
        }
        else {
            Render.writeLine(20, 16, (char*)" ", Yellow, Black);
            Render.writeLine(21, 16, buffer, Yellow, Black);
        }

        Render.draw();

        key = getch();

        switch(key) {
            case 75: {
                if(sum > 0) {
                    sum--;
                    signatures++;
                }
                break;
            }
            case 77: {
                if(sum > 0) {
                    sum--;
                    crypto++;
                }
                break;
            }
        }
    }while(key != 13 || sum != 0);

}

void VIRUS::detect(unsigned short countStation, unsigned short countMap) {

    if(countMap > 1 && addIsActive == false) {
        addIsActive = true;
        needValue = 1 + rand() % 10;
        needCrypto += needValue;
        needSignatures += 10 - needValue;
    }
    else {
        needCrypto += needValue;
        needSignatures += 10 - needValue;
        addIsActive = false;
    }

    infected += signatures * countStation / (countMap * 10);
    float x = countMap + sended;
    x /= crypto;
    detected += infected / (1 / x) + needCrypto;

}

void VIRUS::theend(RENDER &Render) {
    Render.clear();

    Render.writeLine(60, 19, "THE END", White, Black);

    if(infected < detected) {
        Render.writeText(35, 25, 65, (char*)"���� ��������� ��� �������������� �������, � � ����� ������ �� ����� ������� ������� ������. �� ������������ ������� ���� � ���������! ^n (������ �������� #1)", Black, Red);
    }
    else if(peace > 3) {
        Render.writeText(35, 25, 65, (char*)"��������� ������, �� ������, ��� ����-�� �������� �� ������. � ��������� � ��� ���� � �� ���������. ������ ���� �� ������ ����. ^n (������� ��������)", Black, Green);
    }
    else if(signatures < needSignatures) {
        Render.writeText(35, 25, 65, (char*)"����� �������� �� ��������� � �������, ��� ���������� �� ������� �� ������. ^n (����������� ��������)", Black, LightGray);
    }
    else {
        Render.writeText(35, 25, 65, (char*)"���� ������� �� ��������. ����� ������� ���� �������, �� ������� � ����� �� ������ ����. ^n (������ �������� #2)", Black, Red);
    }

    Render.draw();
    getch();
}
