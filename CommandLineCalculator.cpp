#include <iostream>
#include <sstream>
#include <limits>

double calculate(std::string equation);
std::string combineTerms(int a, int b, char sign);
bool isWhitespace(unsigned char c);
bool validateEquation(std::string equation);

int main() {
    std::string equation;
    double result;
    char Continue; 
    bool isValid = false;
    do {
        do {
            std::cout << "Enter an equation using (+, -, *, /) then press enter\n\nEquation: ";
            getline(std::cin, equation);
            equation.erase(std::remove_if(equation.begin(), equation.end(), isWhitespace), equation.end());
            if(validateEquation(equation)) {
                isValid = true;
            } else {
                isValid = false;
            }
        } while(!isValid);
        result = calculate(equation);

        std::cout << "\n" << equation << " = " << result << "\n";
        do {
            std::cout << "\nContinue?('y' or 'n'): ";
            std::cin >> Continue;
            if (Continue == 'y' || Continue == 'n') {
                break;
            } else {
                std::cout << "\nInvalid input\n";
                Continue = 'z';
            }
        } while (Continue == 'z');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (Continue == 'y');

    return 0;
}

double calculate(std::string equation) {
    char current;
    double total = 0;
    int length = equation.size();
    for (int i = 0; i < length; i++) {
        current = equation[i];
    }
    return total;
}

bool isWhitespace(unsigned char c) {
    if (c == ' ' || c == '\t' || c == '\n' ||
        c == '\r' || c == '\f' || c == '\v') {
        return true;
    } else {
        return false;
    }
}

bool validateEquation(std::string equation) {
    return true;
}