#include <iostream>
#include <vector>
using namespace std;
bool all_even(const std::vector<int>& v){

	int i = 0;
	bool flag = true;
	while (i < v.size() && flag){
		if(v.at(i) % 2 != 0){
			flag = false;
			i++;
		}
	}
	return flag;
}
int main(){
	vector<int>v = { 1, 3,5,6,7};

	if (!all_even(v)){
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
return 0;
}
