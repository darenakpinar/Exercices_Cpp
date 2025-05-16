#include <iostream>
#include <vector>
#include <string>

bool is_prime(int n){}


std::vector<int> fill_with_primes(int n){
	std::vector<int>v = {};
	int num = 2;
	while (v.size() < n){
		if (is_prime(num)){
			v.push_back(num);
		}
		num++;
	}
	return v;
}

int main(){}
