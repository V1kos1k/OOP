#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QSet>
#include <math.h>
#include "doors.h"
#include "engine.h"
#include "infolog.h"

class Lift : public QObject
{
    Q_OBJECT
public:
    Lift(QObject *parent = NULL);

private:
    enum class State
    {
        BUTTON_PUSHED,
        MOVING_UP,
        MOVING_DOWN,
        IDLE,
        OPENING,
        OPENED,
        CLOSING
    };
    State status;
    engine* tool;
    doors* door;
    infolog info;
    QSet<int>* set;
    int Level;

    int getLevel();
    void call();
    bool max(int level, int near);

signals:
    void doMoveUp();
    void doMoveDown();
    void doOpen();
    void doStop();

public slots:
    void onPushButton(int level);
    void onMovingUp();
    void onMovingDown();
    void onIdle();
    void onOpening();
    void onClosing();
    void onOpened();
};

#endif // Lift_H
