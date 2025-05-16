#include <iostream>
#include <vector>
#include <string>
std::string decompress(const std::string& s){
	std::string res = " ";
	for (int i = 0; i <s.length(); i = i+2){
		int n = s.at(i+1)-'0';

	for (int j = 0; j<n; j++){
		res = res + s.at(i);
		// res.push_back(s.at(i)); 
	}
	return res;
}

