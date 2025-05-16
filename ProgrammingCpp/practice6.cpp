#include <iostream>
#include <vector>

int find_max_sum(const std::vector<int> &v){

	int max1 = v.at(0) > v.at(1) ? v.at(0) : v.at(1);
	int max2 = v.at(0) < v.at(0) ? v.at(0) : v.at(0);

	for (int i = 2; i < v.size(); i++){
		if (v.at(i) > max1){
			max2 = max1;
			max1 = v.at(i);
		}
		else if (v.at(i) > max2 && v.at(i) <= max1){
			max2 = v.at(i);
		}
	}
	return max1 + max2;
}

int main(){
	std::vector<int> v = {1,2,3,7,5,4};

	std::cout << find_max_sum(v) << std::endl;
	return 0;
}
