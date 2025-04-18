#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

class parser_error {
public:
    std::string msg;
    parser_error(std::string m) : msg(m) {}
};

// Forward declarations
double E();
double S(char op);
double parseNumber();

// Parses and evaluates an arithmetic expression
double E() {
    char c;
    std::cin >> c;
    if (c != '(') throw parser_error("Expected '('");

    char next = std::cin.peek();
    if (next == '+' || next == '*') {
        char op;
        std::cin >> op;
        double result = S(op);
        std::cin >> c;
        if (c != ')') throw parser_error("Expected ')'");
        return result;
    } else {
        double num = parseNumber();
        std::cin >> c;
        if (c != ')') throw parser_error("Expected ')'");
        return num;
    }
}

// Parses a sequence of expressions
double S(char op) {
    double result = (op == '*') ? 1 : 0;

    while (std::cin.peek() == '(') {
        double val = E();
        if (op == '+')
            result += val;
        else if (op == '*')
            result *= val;
    }

    return result;
}

// Parses a signed decimal number (e.g., -2.034)
double parseNumber() {
    std::string numStr;

    // Handle optional sign
    if (std::cin.peek() == '-') {
        numStr += '-';
        std::cin.get();
    }

    bool decimalPointSeen = false;

    while (std::isdigit(std::cin.peek()) || std::cin.peek() == '.') {
        char c = std::cin.get();
        if (c == '.') {
            if (decimalPointSeen) throw parser_error("Invalid number format");
            decimalPointSeen = true;
        }
        numStr += c;
    }

    if (numStr.empty() || numStr == "-") throw parser_error("Invalid number format");

    return std::stod(numStr);
}

int main() {
    try {
        std::cout << "Insert arithmetic expression: ";
        double result = E();
        std::cout << "Result: " << result << std::endl;
    } catch (parser_error &e) {
        std::cerr << "Error: " << e.msg << std::endl;
        return 1;
    }
    return 0;
}



