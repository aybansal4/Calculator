#include <iostream>
#include <ncurses.h>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include "exprtk.hpp"
int main() {
    exprtk::parser<double> parser;
    while (true) {
        std::cout << "mode> ";
        std::string mode = getch();
        if (mode == "s") {
            std::string problem;
            std::cout << "problem> ";
            std::cin >> problem;
            try {
                for (int i = 0; i <= problem.size(); i++) {
                    if (isalpha(problem[i])) {
                        throw std::runtime_error("No variables or spaces in problems");
                    }
                }
                exprtk::expression<double> expression;
                parser.compile(problem, expression);
                std::cout << "answer> " << expression.value() << "\n";
            }
            catch (const std::runtime_error& e) {
                std::cout << "error> " << e.what();
            }
        } else if (mode == "q") {
            std::cout << std::endl;
            return 0;
        }
        else {
            std::cout << "error> Unknown mode: " << mode;
        }
    }
}