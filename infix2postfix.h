#ifndef INFIX2POSTFIX_H
#define INFIX2POSTFIX_H

#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <string>

int priority(char a);

std::string infix2postfix(std::string infix);

#endif // INFIX2POSTFIX_H
