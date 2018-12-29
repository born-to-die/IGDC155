#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "render.h"
#include "virus.h"

class ROOM {
public:

    unsigned short countStation;
    char *name;
    ROOM *nextroom;

    void setNext(ROOM &Room);

    virtual void info(RENDER &Render, VIRUS &Virus) {

    }

    virtual void welcome(RENDER &Render) {

    }

    virtual void hack(RENDER &Render) {

    }

    virtual void logo(RENDER &Render) {

    }

    virtual void test() {
        printf("ROOM");
    }
};

#endif // ROOM_H_INCLUDED
