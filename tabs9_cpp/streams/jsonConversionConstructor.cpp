#include <iostream>
#include <string>
#include <variant>

class json {
private: 
    // Internal data variant to store different types
    std::variant<std::monostate, double, std::string, bool> data;

public:
    // Constructors (conversion constructors)
    json(double d) : data(d){}
    json(bool b)   : data(b) {}
    json(const char* s) :   data(std::string(s)) {}
    json(const std::string& s) : data(s) {}

    // for testing: print the stored value
    void print()const{
        if (std::holds_alternative<double>(data)){
            std::cout << "double: " << std::get<double>(data) << std::endl;
        }else if(std::holds_alternative<std::string>(data)){
            std::cout << "string: \"" << std:: get<std::string>(data) << "\"" << std::endl;
        }else if(std::holds_alternative<bool>(data)){
            std::cout << "bool: " << (std::get<bool>(data) ? "true" : "false") << std::endl;
        }else{
            std::cout << "null" << std::endl;
        }
    }
};

int main(){
    json j1 = 42.0;
    json j2 = true;
    json j3 = "hello";
    json j4 = nullptr;

    j1.print();
    j2.print();
    j3.print();
    j4.print();
}