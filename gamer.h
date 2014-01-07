#ifndef Gamer_H
#define Gamer_H

#include <QObject>
#include <QMessageBox>
#include <string>
#include <vector>
#include <iostream>

class Gamer//: public QObject
{
     //Q_OBJECT

public:
    explicit Gamer(std::string s);
    explicit Gamer();
    ~Gamer();

public slots:
    void setPoint(int n);
    void setName(std::string s);
    int getPoint();
    void addPoint(int n);
    int getGameTimes();
    void addGameTimes();

signals:

public:
    std::string Gamername;
    int point;
    int gameTimes;

};

class GamersVector//: public QObject
{
     //Q_OBJECT

public:
    explicit GamersVector();
    ~GamersVector();

public slots:
    int searchGamerName(std::string name);
    void addGamer(Gamer *gamer);
    void printAllGamers();

signals:

public:
    std::vector<Gamer*> allGamers;

};


#endif // Gamer_H
