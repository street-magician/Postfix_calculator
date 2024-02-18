#ifndef PINO_H
#define PINO_H

#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>

class Pino {
private:
    std::stack<double> operandStack;

public:
    void calculate(std::string expression);
    void swapTopTwo();
    void calculateSum();
    void calculateAverage();
};

#endif
