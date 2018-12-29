#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

#include "render.h"
#include "virus.h"
#include "room.h"

class TRUCK : public ROOM {
public:

    TRUCK();

    void logo(RENDER &Render);

    void welcome(RENDER &Render);

    void hack(RENDER &Render);

    void info(RENDER &Render, VIRUS &Virus);

    void test();
};

#endif // TRUCK_H_INCLUDED
