#include "run.h"

namespace run {

Run::Run(gameRender::GameRender *render) : render_(render) {
    menu = Menu(render_);
    //Sd.loadSoundOgg(QString("../data/sounds/menu.ogg"));
    //Sd.playThread();

}

Run::~Run() {
    //Sd.terminate();
}

void Run::loop() {
    render_->paintStatus(MENU);
    while(!render_->loop_paint()) {
        menu.run();
    }
}

}
