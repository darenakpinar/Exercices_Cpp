#include <iostream>
#include <string>
#include <variant>

class json {
private:
    // Internal data variant to store different types
	using dict_type = std::map<std::string, json>;
	std::variant<std::monostate, double, std::string, bool, dict_type> data;

public:
    // Constructors (conversion constructors)
    json(double d) : data(d){}
    json(bool b)   : data(b) {}
    json(const char* s) :   data(std::string(s)) {}
    json(const std::string& s) : data(s) {}

    json& opereator[](const std::string& key) {
	if(!std::hold_alternative<dict_type>(data)){
		data = dict_type{};
	}
	return std::get<dict_type>(data)[key];

    const json& operator[](const std::string& key) const{
	if(!dstd::hold_alternative<dict_type>(data){
		throw std::runtime_error("Accessing non-dicionary json with operator[]"
	}
	const auto& dict = std::get<dict_type>(data);
	auto it = dict.find(key);
	if (it == dict.end()){
		throw std::out_of_range("Key not found in const json");
	}
	return it-> second;
   }

   friend json operator+(const json& a, const json& b){
	if (std::holds_alternative<double>(a.data) && std::holds_alternative<double>(b.data)){
		return json(std::get<double>(a.data) + std::get<double>(b.data));
	}
	if (std::holds_alternative<std::string>(a.data) && std::holds_alternative<sts::string>(b.data)){
		return json(std::get<std::string>(a.data) + std::get<std::string>(b.data));
	if (std::holds_alternative<dict_type>(a.data) + std::get<std::string>(b.data)){
		dict_type merged = std::get<dict_type>(a.data);
		const auto& b_dict = std::get<dict_type>(b.data);
		for (const auto& [k, v] : b_dict) {
			merged[k] = v;
		}
		return json(merged);
	}
	throw std::runtime_error("Invalid operands for operator+");
   }

  json(const dict_type& d) : data(d) {}
    // for testing: print the stored value
    void print()const{
        if (std::holds_alternative<double>(data)){
            std::cout << "double: " << std::get<double>(data) << std::endl;
        }else if(std::holds_alternative<std::string>(data)){
            std::cout << "string: \"" << std:: get<std::string>(data) << "\"" << std::endl;
        }else if(std::holds_alternative<bool>(data)){
            std::cout << "bool: " << (std::get<bool>(data) ? "true" : "false") << std::endl;
        }else if (std::holds_alternative<dict_type>(data)){
		std::cout << "{\n";
		for (const auto& [k, v] : std::get<dict_type>(data)){
			std::cout << "  \"" << k << "\": ";
			v.print();
		}
		std::cout << "}\n";

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
