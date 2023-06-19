#include <iostream>
#include <sstream>
#include <limits>

int calculate(std::string equation);

int main() {
    char exit = 'n';
    std::string equation;
    double result;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        std::cout << "Enter an equation using (+, -, *, /) then press enter\nEquation: ";
        getline(std::cin, equation);
        result = calculate(equation);

        std::cout << "\n" << equation << " = " << result;
        std::cout << "Continue?('y' or 'n'): ";
        std::cin >> exit;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (exit != 'y' && exit != 'n') {
            do {
                std::cout << "Invalid input, please enter 'y' or 'n'. ";
                std::cout << "Continue?('y' or 'n'): ";
                std::cin >> exit;
            } while (exit != 'y' || exit != 'n');
        }
        
    } while (exit == 'n');

    return 0;
}

