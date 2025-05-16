#include <iostream>
#include <vector>
using namespace std;

bool exists_negative(const std::vector<int> & v){
	bool flag = false;
	int i = 0;

	while (i < v.size() && !flag){

		if (v.at(i) < 0){
			flag = true;
		}
		i++;
	}
	return flag;
}

int main(){

	vector<int> v = {1,-1,2};

	if (!exists_negative(v)){
		cout << "No negative in vector" << endl;
	}else {
		cout << "Negative elements in vector" << endl;

	}
	return 0;
}
