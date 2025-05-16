#include <iostream>
#include <vector>

int min_index(const std::vector<int>& v){
	int min = v.at(0);
	int index = 0;
	for (int i = 0; i < v.size(); i++){
		if (v.at(i) < min){
		 min = v.at(i);
		index = i;
		}
	}
	return index;
}
int main (){
	std::vector<int>v = {1,5,7,-1,3,2};
	std::cout << min_index(v) << std::endl;
	return 0;
}
