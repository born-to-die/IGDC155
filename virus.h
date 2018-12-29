#ifndef VIRUS_H_INCLUDED
#define VIRUS_H_INCLUDED

#include <conio.h>
#include "render.h"

class VIRUS {
public:

    unsigned short infected; // кол-во зараженных
    unsigned short signatures;
    unsigned short crypto;
    unsigned short detected;
    unsigned short sended;
    unsigned short strike;
    unsigned short peace;

    unsigned short needValue;
    unsigned short needCrypto;
    unsigned short needSignatures;

    unsigned short addToDetected;
    unsigned short addToCrypto;

    bool addIsActive;


    VIRUS();

    void upgrade(RENDER &Render);

    void detect(unsigned short countStation, unsigned short countMap);

    void theend(RENDER &Render);
};

#endif // VIRUS_H_INCLUDED
