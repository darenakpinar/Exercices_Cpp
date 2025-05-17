#include <iostream>
#include <vector>
using namespace std;
int minimumDivisor( vector<int> arr, int thresh){

	int min_div = 1;
	int max_div = 0;

	for (int v: arr){
		if(v > max_div){
			max_div = v;
		}
	}

	while (min_div < max_div){
		int m_div = (max_div + min_div)/2;
		int sum = 0;
		for (int v: arr){
			int d = (v % m_div == 0)? v/m_div: v/m_div + 1;
			sum = sum+d;
		}
	if (sum > thresh){
		min_div = m_div + 1;
	}else{
		max_div = m_div;
	}
}
	return max_div;
}

int main (){
	std::vector<int> arr = {1, 5, 7};
	int th = 8;

	std::cout << minimumDivisor(arr, th) << std::endl;

	return 0;
}
