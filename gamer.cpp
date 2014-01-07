#include "gamer.h"

    Gamer::Gamer(std::string s)
    {
        Gamername = s;
        point = 0;
        gameTimes = 0;
    }

    Gamer::Gamer()
    {
        Gamername = "";
        point = 0;
        gameTimes = 0;
    }

    Gamer::~Gamer()
    {
        delete(this);
    }

    void Gamer::setPoint(int n)
    {
        if(n<point) point = n;
    }

    void Gamer::setName(std::string s)
    {
        if(Gamername.size()<1)
        {
            Gamername = s;
            std::cout << "Set gamer name " << s << std::endl;
        }
    }

    int Gamer::getGameTimes()
    {
        return gameTimes;
    }

    void Gamer::addGameTimes()
    {
        gameTimes++;
    }

    int Gamer::getPoint()
    {
        return point;
    }

    void Gamer::addPoint(int n)
    {
        point += n;
    }

    GamersVector::GamersVector()
    {
        allGamers.clear();
    }

    GamersVector::~GamersVector()
    {
        delete(this);
    }

    int GamersVector::searchGamerName(std::string name)
    {
        for(unsigned int i=0; i<allGamers.size(); i++)
        {
            if(allGamers[i]->Gamername.compare(name) == 0)
            {
                //QMessageBox::information(NULL, QObject::tr("Add Gamer"), QObject::tr("The Gamer already exists, please log in."));
                return i;
            }
        }
        return -1;
    }

    void GamersVector::addGamer(Gamer *gamer)
    {
        if(searchGamerName(gamer->Gamername) == -1)
        allGamers.push_back(gamer);
        else
            QMessageBox::information(NULL, QObject::tr("Add Gamer"), QObject::tr("The Gamer already exists, please log in."));
    }

    void GamersVector::printAllGamers()
    {
        std::cout << "*********** ALL GamerS ************" << std::endl;
        for(unsigned int i=0; i<allGamers.size(); i++)
        {
            std::cout << allGamers[i]->Gamername << " " << allGamers[i]->point << std::endl;
        }
    }
