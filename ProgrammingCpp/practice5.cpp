#include <iostream>
#include <vector>

bool is_prime(int n){
	if (n <= 1) return false;
	bool flag = true;
	int i = 0;
	if (n == 2) return true;
	while (i <n && !flag) {
		if (n % i == 0) flag =  false;
		i++;
	}
	return flag;
}

int main(){
	if(!is_prime(5)){
		std::cout << "Not prime" << std::endl;
	}else {
		std::cout << "Prime" << std::endl;
	}
	return 0;
}
