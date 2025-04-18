#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

class parser_error{
public:
    std::string msg;
    parser_error(std::string m) : msg(m) {}
};

double E();  // sums and subtractions
double P();  // multiplications and divisions
double T();  // terms: numbers, parantheses, negatives

double T(){
    char c;
    std::cin >> c;

    if (c == '('){
        double val = E();
        std::cin >> c;
        if (c != ')') throw parser_error("Expected ')'");
        return val;
    }
    else if (c == '-'){
        return -T();
    }
    else if (std::isdigit(c) || c == '.') {
        std::cin.putback(c);
        double val;
        std::cin >> val;
        return val;
    }
    else {
        throw parser_error(std::string("Unexpected character  '") + c + "'");
    }
    
}
double P(){
    double val = T();
    char c;

    while (std::cin.peek() == '*' || std::cin.peek() == '/'){
        std::cin >> c;
        if (c == '*') val *= T();
        else if (c == '/') val /= T();
    }
    return val;
}
double E(){
    double val = p();
    char c;
    
    while (std::cin.peek() == '+' || std::cin.peek() == '-') {
        std::cin >> c;
        if (c == '+') val += P();
        else if (c == '-') val -= P();
    }
    return val;
}

int main(){

    try{
        std::cout << "Insert expression: " ;
        double result = E();
        char c;
        std::cin>> c;
        if (c != '=') throw parser_error("Expected '=' at the end");
        std::cout << "Result: " << result << std::endl;
    }catch (parser_error &e){
        std::cerr << "Error: " << e.msg << std::endl;
        return 1;
    }

    return 0;
}
