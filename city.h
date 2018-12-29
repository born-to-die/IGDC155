#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include "render.h"
#include "virus.h"
#include "room.h"

class CITY : public ROOM {
public:

    CITY();

    void logo(RENDER &Render);

    void welcome(RENDER &Render);

    void hack(RENDER &Render);

    void info(RENDER &Render, VIRUS &Virus);

    void test();
};

#endif // CITY_H_INCLUDED
