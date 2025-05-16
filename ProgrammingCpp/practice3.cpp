#include <iostream>
#include <vector>

int max(const std::vector<int>& v){
	int max = v.at(0);
	for (int i = 0; i < v.size(); i++){
		if (v.at(i) > max) max = v.at(i);
	}
	return max;
}
int main(){
	std::vector<int>v = {1,4,5,7,2,1};
	std::cout << max(v) << std::endl;
	return 0;
}
