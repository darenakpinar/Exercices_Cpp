#include <iostream>
#include <string>
#include <vector>

bool is_prime(int n){
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i < n; i ++){
		if (n % i == 0){
			return false;
		}
	}
	return true;
}

int main (){
	int n = 7;
	if (!is_prime(n)){
		std::cout << "Is not  prime " << std::endl;
	}else {
		std::cout << "is prime" << std::endl;
	}
	return 0;
}
