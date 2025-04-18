#include <iostream>
#include <string>
#include <algorithm> // for std::min

int edit_distance(std::string x, std::string y){

    if (x.empty()) return y.length();
    if (y.empty()) return x.length();

    if (x[0] == y[0])return edit_distance(x.substr(1), y.substr(1));

    return 1 + std::min({
        edit_distance(x, y.substr(1)), // Insert
        edit_distance(x.substr(1), y), // Delete
        edit_distance(x.substr(1), y.substr(1))  // Substitute
    });
}

 int main(){
    std::cout << "Edit Distance between 'sunday' and 'saturday' : "
    << edit_distance("sunday", "saturday") << std::endl;
    
    std::cout<< "Edit Distance between 'abc' and 'ac': "
    << edit_distance("abc", "ac") << std::endl;

    return 0;

}




