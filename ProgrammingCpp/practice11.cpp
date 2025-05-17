#include <iostream>
#include <vector>

int binom(int n, int k){

	if (k == 0 || k == n){
		return 1;
	}else{
		return binom((n-1), k-1) + binom((n-1) , k);
	}
}



int main (){
	int a, b;

	std::cin>> a >> b;
	std::cout << binom(a, b);

	return 0;
}
