#ifndef ANSWERSDATABASE_H
#define ANSWERSDATABASE_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cstdio>
#include <QObject>

struct Solution
{
    std::string s;
    bool hasSolution;
};

typedef std::pair<std::multiset<int>, Solution> Answer;

void showAnswer(Answer a);

class AnswerDatabase : public QObject
{
    Q_OBJECT

public:
    explicit AnswerDatabase(std::string filename);
    ~AnswerDatabase();

    std::vector<Answer> answerVector;

    Solution getSolution(std::multiset<int> digits);
};

#endif // ANSWERSDATABASE_H
