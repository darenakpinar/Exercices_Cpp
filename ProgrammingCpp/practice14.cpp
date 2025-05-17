#include <iostream>
#include <vector>
#include <string>

void remove_pairs(std::string &s){
if (s.length() == 0){
	return;
}
size_t i = 0;
while (i + 1 < s.size()){
	if (s.at(i) == s.at(i+1)){
		s.erase(i+1, 1);
	}else{
		i++;
	}
}
}
int main(){
	std::string s = "abbbccd";
	remove_pairs(s);

	std::cout << s << std::endl;
	return 0;
}
