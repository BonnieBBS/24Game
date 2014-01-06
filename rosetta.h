#ifndef ROSETTA_H
#define ROSETTA_H

#include <random>
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <functional>

using namespace std;

void showMultisetInt(multiset<int> m);

class RPNParse;

multiset<int> rosetta();

string judgeAns(string input, multiset<int> digits0);

#endif // ROSETTA_H
