#include "engine.h"

engine::engine(QObject *parent) : QObject(parent)
{
    status = State::IDLE;
    timer = NULL;
}

void engine::onMoveUp(){
    emit doStart();
    timer = new QTimer;
    timer->setInterval(moving_interval);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveUpEmitter()));
    timer->start();
    status = State::MOVING_UP;
}

void engine::onMoveDown(){
    emit doStart();
    timer = new QTimer;
    timer->setInterval(moving_interval);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveDownEmitter()));
    timer->start();
    status = State::MOVING_DOWN;
}

void engine::onStop(){
    delete timer;
    emit doStop();
    status = State::IDLE;
}
