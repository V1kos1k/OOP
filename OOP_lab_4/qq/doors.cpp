#include "doors.h"

doors::doors(QObject *parent) : QObject(parent)
{
    status = State::CLOSED;
    timer = NULL;
}

void doors::onOpening(){
    emit doOpening();
    timer = new QTimer;
    timer->setInterval(opening_interval);
    connect(timer, SIGNAL(timeout()), this, SLOT(onOpened()));
    timer->start();
    status = State::OPENING;
}

void doors::onOpened(){
    delete timer;
    emit doOpened();
    timer = new QTimer;
    timer->setInterval(staying_interval);
    connect(timer, SIGNAL(timeout()), this, SLOT(onClosing()));
    timer->start();
    status = State::OPENED;
}

void doors::onClosing(){
    delete timer;
    emit doClosing();
    timer = new QTimer;
    timer->setInterval(closing_interval);
    connect(timer, SIGNAL(timeout()), this, SLOT(onClosed()));
    timer->start();
    status = State::CLOSING;
}

void doors::onClosed(){
    delete timer;
    doClosed();
    status = State::CLOSED;
}
