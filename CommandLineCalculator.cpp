#include <iostream>
#include <sstream>

int calculate(std::string equation);

int main() {
    bool exit = false;
    std::string equation;
    double result;
    do {
        std::cout << "Enter an equation using (+, -, *, /) then press enter";
        getline(std::cin, equation);
        result = calculate(equation);
        std::cout << "\n" << equation << " = " << result;
    } while (!exit);
    return 0;
}

