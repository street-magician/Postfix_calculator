#include "pino.h"

int main(int argc, char* argv[]) {
    Pino calculator;

    if (argc > 1 && std::string(argv[1]) == "-p") {
        std::cout << "Postfix Calculator - Enter expressions directly:" << std::endl;

        while (true) {
            std::string expression;
            std::getline(std::cin, expression);

            if (expression.empty()) {
                break;
            }
            calculator.calculate(expression);
        }
    } else {
        std::cerr << "Usage: " << argv[0] << " -p" << std::endl;
    }

    return 0;
}
