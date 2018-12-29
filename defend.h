#ifndef DEFEND_H_INCLUDED
#define DEFEND_H_INCLUDED

#include "render.h"
#include "virus.h"
#include "room.h"

class DEFEND : public ROOM {
public:

    DEFEND();

    void logo(RENDER &Render);

    void welcome(RENDER &Render);

    void hack(RENDER &Render);

    void info(RENDER &Render, VIRUS &Virus);

    void test();
};

#endif // DEFEND_H_INCLUDED
