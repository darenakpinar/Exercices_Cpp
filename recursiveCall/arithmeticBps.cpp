#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

class parser_error {
public:
    std::string msg;
    parser_error(std::string m) : msg(m) {}
};

double E(); // Expression 
double S(char op); //Sequence 

// Parse and evaluate an expression 
double E() {
    char c;
    std::cin >> c;

    if (c != '(') throw parser_error("Expected '('");

    if (std::isdigit(std::cin.peek())){
        double num;
        std::cin >> num;
        
        std::cin >> c;
        if (c != ')') throw parser_error("Expected ')'");

        return num;

    }else {
        char op;
        std::cin >> op; // read operator (+ or *)
        if(op != '+' && op != '*') throw parser_error("Unknown operator ");

        double result = S(op);

        std::cin >> c;
        if (c != ')') throw parser_error ("Expected ')'");

        return result;
    }
}

    double S(char op ){
        double result = (op == '*') ? 1 : 0;

        while (std::cin.peek()== '('){
            double val = E();
            if (op == '+')
                result += val;
            else if (op == '*')
                result *= val;
        }
        return result;
    }


int main(){
    try {
        std::cout << "Insert arithmetic exoression: ";
        double result = E();
        std::cout << "Result: " << result << std::endl;

    }catch (parser_error &e){
        std::cerr << "Error: " << e.msg << std::endl;
        return 1;
    }
    return 0;
}
