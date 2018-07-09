#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QTimer>


class engine : public QObject
{
    Q_OBJECT
public:
    //engine();//{
//        status = State::IDLE;
//        timer = NULL;
//    };
    engine(QObject *parent = NULL);

private:
    enum class State
    {
        IDLE,
        MOVING_UP,
        MOVING_DOWN,
    };

    State status;
    QTimer* timer;

    static const size_t moving_interval = 1200;

signals:
    void doStart();
    void doMoveUp();
    void doMoveDown();
    void doStop();

public slots:
    void onMoveUp();
    void onMoveDown();
    void onStop();
    void MoveUpEmitter() {emit doMoveUp();}
    void MoveDownEmitter() {emit doMoveDown();}
};

#endif // ENGINE_H
