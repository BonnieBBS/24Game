#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QProgressBar>

class Counter : public QObject
{
    Q_OBJECT

public:
    explicit Counter(int n);
    ~Counter();

    QProgressBar *bar;
    void setBar(QProgressBar *barSource);
    void setBarLength();

public slots:
    void decrease();
    //void decrease();
    void setCount(int n);
    int getCount();

signals:
    int valueChanged();
    void timeout();

private:
    int count;

};

#endif // COUNTER_H
