#include "Lift.h"

Lift::Lift(QObject *parent) : QObject(parent)
{
    status = State::IDLE;
    tool = new engine(NULL);
    door = new doors(NULL);
    Level = 1;
    set = new QSet<int>;

    connect(this, SIGNAL(doMoveUp()), tool, SLOT(onMoveUp()));
    connect(this, SIGNAL(doMoveDown()), tool, SLOT(onMoveDown()));
    connect(this, SIGNAL(doStop()), tool, SLOT(onStop()));
    connect(this, SIGNAL(doOpen()), door, SLOT(onOpening()));

    connect(tool, SIGNAL(doMoveUp()), this, SLOT(onMovingUp()));
    connect(tool, SIGNAL(doMoveDown()), this, SLOT(onMovingDown()));
    connect(tool, SIGNAL(doStop()), this, SLOT(onIdle()));

    connect(door, SIGNAL(doOpening()), this, SLOT(onOpening()));
    connect(door, SIGNAL(doOpened()), this, SLOT(onOpened()));
    connect(door, SIGNAL(doClosing()), this, SLOT(onClosing()));
    connect(door, SIGNAL(doClosed()), this, SLOT(onIdle()));
}

void Lift::onPushButton(int level){
    info.printLevelCall(level);
    set->insert(level);
    if (status == State::IDLE){
//        int near = getLevel();
//        if (near != 0){
//            if (near > Level){
//                emit doMoveUp();
//            } else if (near < Level) {
//                emit doMoveDown();
//            } else {
//                emit doOpen();
//            }
//        }
        call();
    }
    status = State::BUTTON_PUSHED;
}

void Lift::onMovingUp(){
    ++Level;
    info.printLevelMoveUp(Level);
    if (set->contains(Level)){
        emit doStop();
    }
    status = State::MOVING_UP;
}

void Lift::onMovingDown(){
    --Level;
    info.printLevelMoveDown(Level);
    if (set->contains(Level)){
        emit doStop();
    }
    status = State::MOVING_DOWN;
}

void Lift::onIdle(){
    if (status == State::CLOSING){
        info.printString("Двери лифта закрыты");
    } else if (status == State::MOVING_UP || status == State::MOVING_DOWN){
        info.printLevelStop(Level);
    }
//    int near = getLevel();
//    if (near != 0){
//        if (near > Level){
//            emit doMoveUp();
//        } else if (near < Level){
//            emit doMoveDown();
//        }
//        else{
//            emit doOpen();
//        }
//    }
    call();
    status = State::IDLE;
}

void Lift::call() {
    int near = getLevel();
    if (near != 0){
        if (near > Level){
            emit doMoveUp();
        } else if (near < Level){
            emit doMoveDown();
        }
        else{
            emit doOpen();
        }
    }
}

void Lift::onOpening(){
    info.printString("Двери лифта открываются");
    status = State::OPENING;
}

void Lift::onOpened(){
    info.printString("Двери лифта открыты");
    set->remove(Level);
    status = State::OPENED;
}

void Lift::onClosing(){
    info.printString("Двери лифта закрываются");
    status = State::CLOSING;
}

bool Lift::max(int level, int near) {
    return (abs(Level - (level)) < abs(Level - near));
}


int Lift::getLevel(){
    int near = 0;
    for (auto level = set->begin(); level != set->end(); level++){
        int lev = *level;
        if ((near == 0) || max(lev, near)){
            near = *level;
        }
    }
    return near;
}
