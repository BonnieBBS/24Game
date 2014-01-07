#include "counter.h"
#include <iostream>

Counter::Counter(int n)
{
    count = n;
}

Counter::~Counter()
{
    delete(this);
}

void Counter::setBar(QProgressBar *barSource)
{
    bar = barSource;
}

void Counter::setBarLength()
{
    bar->setValue(count);
}

/*
int Counter::valueChanged()
{
    return count;
}
*/

void Counter::decrease()
{
    if(count>0)
    {
        count --;
        setBarLength();
        emit valueChanged();
    }
    else
    {
        emit timeout();
    }
    std::cout << "decreasing " << count << std::endl;
}

void Counter::setCount(int n)
{
    count = n;
}

int Counter::getCount()
{
    return count;
}
