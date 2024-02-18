#include "pino.h"

void Pino::calculate(std::string expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1]))) {
            operandStack.push(std::stod(token));
        } else {
            double operand2, operand1;
            switch (token[0]) {
                case '+':
                    operand2 = operandStack.top();
                    operandStack.pop();
                    operand1 = operandStack.top();
                    operandStack.pop();
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operand2 = operandStack.top();
                    operandStack.pop();
                    operand1 = operandStack.top();
                    operandStack.pop();
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operand2 = operandStack.top();
                    operandStack.pop();
                    operand1 = operandStack.top();
                    operandStack.pop();
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operand2 = operandStack.top();
                    operandStack.pop();
                    operand1 = operandStack.top();
                    operandStack.pop();
                    operandStack.push(operand1 / operand2);
                    break;
                case '%':
                    operand2 = operandStack.top();
                    operandStack.pop();
                    operand1 = operandStack.top();
                    operandStack.pop();
                    operandStack.push(std::fmod(operand1, operand2));
                    break;
                case '^':
                    operand2 = operandStack.top();
                    operandStack.pop();
                    operand1 = operandStack.top();
                    operandStack.pop();
                    operandStack.push(std::pow(operand1, operand2));
                    break;
                case 'v':
                    if (!operandStack.empty()) {
                        operand1 = operandStack.top();
                        operandStack.pop();
                        operandStack.push(std::sqrt(operand1));
                    } else {
                        std::cerr << "Insufficient operands for square root." << std::endl;
                        return;
                    }
                    break;
                case 's':
                    calculateSum();
                    break;
                case 'a':
                    calculateAverage();
                    break;
                case 'x':
                    swapTopTwo();
                    break;
                default:
                    std::cerr << "Invalid operator: " << token << std::endl;
                    return;
            }
        }
    }

    if (!operandStack.empty()) {
        std::cout << "Result: " << operandStack.top() << std::endl;
        operandStack.pop();
    } else {
        std::cerr << "---------------" << std::endl;
    }
}

void Pino::swapTopTwo() {
    if (operandStack.size() < 2) {
        std::cerr << "Insufficient operands for swap." << std::endl;
        return;
    }

    double operand2 = operandStack.top();
    operandStack.pop();
    double operand1 = operandStack.top();
    operandStack.pop();

    operandStack.push(operand2);
    operandStack.push(operand1);
}

void Pino::calculateSum() {
    double sum = 0;

    while (!operandStack.empty()) {
        sum += operandStack.top();
        operandStack.pop();
    }

    std::cout << "Result: " << sum << std::endl;
}

void Pino::calculateAverage() {
    double sum = 0;
    int count = 0;

    while (!operandStack.empty()) {
        sum += operandStack.top();
        operandStack.pop();
        count++;
    }

    if (count > 0) {
        operandStack.push(sum / count);
    } else {
        std::cerr << "No operands for average." << std::endl;
    }
}
