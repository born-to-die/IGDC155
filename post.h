#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

#include <ctime>

#include "render.h"
#include "virus.h"
#include "room.h"

class POST : public ROOM {
public:

    POST();

    void info(RENDER &Render, VIRUS &Virus);

    void welcome(RENDER &Render);

    void hack(RENDER &Render);

    void logo(RENDER &Render);

    void test();
};

#endif // POST_H_INCLUDED
