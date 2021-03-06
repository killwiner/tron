#ifndef INTRO_H
#define INTRO_H

#include "../gameRender/gameRender.h"
#include "../rendering/loadimgs.h"

namespace intro {

class Intro
{
public:
    Intro(gameRender::GameRender *render);
    void video();

private:
    QSPVImage images;
    gameRender::GameRender *render_;
    void loadVideo();
    quint32 videoSize;
};
}

#endif // INTRO_H
