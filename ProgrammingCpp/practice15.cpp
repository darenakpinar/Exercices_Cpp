#include <iostream>
#include <vector>

vector<double>moving_avarage(const vector<double>v, int k){
	vector <double> out_v(v.size());
	for (int i=0; i <v.size(); i++){
	double s = 0;
	double count = 0;
	for (int j = i-k; j<=i+k; j++){
		if (j >= 0 && j < v.size()){
			s = s+v.at(j);
			count ++;
		}
	out_v.at(i) = s/count;
	}
}
	return out_v;
}

