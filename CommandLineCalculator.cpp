#include <iostream>
#include <sstream>
#include <limits>
#include <string>

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

    int startNum1 = 0;
    int endNum1 = 0;
    int startNum2 = 0;
    int endNum2 = 0;
    double num1;
    double num2;
    int startParenthesis = 0;
    int endParenthesis = 0;
    double combined;

    for (int i = 0; i < length; i++) {
        current = equation[i];
        //Operations within parentheses need to be evaluated first recursively
        if (current == '(') {
            startParenthesis = current;
            int parenthesisCounter = 0;
            std::string subEquation;

            for (int j = startParenthesis + 1; j < length; j++) {
                if (equation[j] == ')' && parenthesisCounter == 0) {
                    endParenthesis = j;
                    //recursively call calculate on the sub-equation within the parentheses
                    subEquation = equation.substr(startParenthesis+1, endParenthesis-1);
                    combined = calculate(subEquation);
                    equation = equation.substr(0, startParenthesis+1) + std::to_string(combined) + equation.substr(endParenthesis-1, length-1);                }

                else if (equation[j] == '(') {
                    parenthesisCounter++;
                }
            }

        }
        //evaluate division and multiplication
        else if (current == '*' || current == '/') {
            endNum1 = i - 1;
            num1 = std::stod(equation.substr(startNum1, endNum1));
            startNum2 = i + 1;
            for (int j = startNum2; j < length; j++) {
                if (equation[j] == '+' || equation[j] == '-' || equation[j] == '*' || equation[j] == '/' || (j + 1) == length) {
                    endNum2 = j - 1;
                }
            }
            num2 = std::stod(equation.substr(startNum2, endNum2));
            if (current == '*') {
                combined = num1*num2;
            } else {
                combined = num1/num2;
            }
            equation = equation.substr(0, startNum1-1) + std::to_string(combined) + equation.substr(endNum2+1, length-1);
        }
    }
    startNum1 = 0;
    endNum1 = 0;
    startNum2 = 0;
    endNum2 = 0;
    //add or subtract all liked terms
    for (int i = 0; i < length; i++) {
        current = equation[i];
        if (current == '+' || current == '-') {
            endNum1 = i - 1;
            std::cout << equation.substr(0, length);
            num1 = std::stod(equation.substr(startNum1, endNum1+1));
            startNum2 = i;
            for (int j = startNum2; j < length; j++) {
                if (equation[j] == '+' || equation[j] == '-' || (j + 1) == length) {
                    endNum2 = j - 1;
                }
            }
            num2 = std::stod(equation.substr(startNum2, endNum2+2));
            if (current == '+') {
                combined = num1+num2;
            } else {
                combined = num1-num2;
            }
            equation.replace(startNum1, endNum2, std::to_string(combined));
            std::cout << equation << std::endl;
            i = endNum1;
            startNum1 = startNum2;
        }

    }
    int count = 0;
    //see if all terms are combined
    for (int i = 0; i < length; i++) {
        if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '(' || equation[i] == ')') {
            count++;
        }
    }
    //if all terms are combined, return the total
    if(count == 0) {
        total = std::stod(equation);
        return total;
    } else return -1;
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
    int length = equation.size();
    for (int i = 0; i < length; i++) {
        //to be implemented eventually
    }
    return true;
}