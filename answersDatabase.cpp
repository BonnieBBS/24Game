/*struct Solution
{
    std::string s;
    bool hasSolution;
};

typedef std::pair<std::multiset<int>, Solution> Answer;

class AnswerDatabase : public QObject
{
    Q_OBJECT

public:
    explicit AnswerDatabase(std::string filename);
    ~AnswerDatabase();

    std::vector<Answer> answerVector;
};*/

#include "answersDatabase.h"

AnswerDatabase::AnswerDatabase(std::string filename)
{
    FILE * pFile;
    pFile = fopen(filename.c_str(), "r");
    if(pFile == NULL)
        perror ("Error opening the answer file.");
    else
    {
        while(true)
        {
            if(feof(pFile)) break;
            int a, b, c, d, x;
            char ss[20];
            fscanf(pFile, "%d %d %d %d %s %d", &a, &b, &c, &d, ss, &x);
            //std::cout << a  << " " << b << " " << c << " " << d  << " " << ss << " " << x << std::endl;
            std::multiset<int> ms;
            ms.insert(a);
            ms.insert(b);
            ms.insert(c);
            ms.insert(d);
            Solution solution;
            solution.s = ss;
            solution.hasSolution = x;
            Answer answer;
            answer.first = ms;
            answer.second = solution;
            answerVector.push_back(answer);
        }
    }
}

AnswerDatabase::~AnswerDatabase()
{
    delete(this);
}

void showAnswer(Answer a)
{
    for(auto it=a.first.begin(); it!=a.first.end(); it++)
    {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;
    std::cout << a.second.hasSolution << " " << a.second.s << std::endl;
}

Solution AnswerDatabase::getSolution(std::multiset<int> digits)
{
    for(unsigned int i=0; i<answerVector.size(); i++)
    {
        if(answerVector[i].first == digits)
        {
            std::cout << answerVector[i].second.hasSolution << " " << answerVector[i].second.s << std::endl;
            return answerVector[i].second;
        }
    }
    std::cout << "Solution AnswerDatabase::getSolution(std::multiset<int> digits) has ERROR" << std::endl;
    Solution err;
    return err;
}


