#include <iostream>
#include <vector>
#include <string>

class Polynomial{
	public:
		Polynomial();
		Polynomil (const Polynomial & p);
		void set(int exponent, int coeff);
		int et(int exponent) const;
		int evoluate(int x) const;
		Polynomial differentiate(int order)const;
		int degree()const;
		void read();
		void print();
	private:
		int intpow(int base, int exponent)const;
		struct Term{
			int coeff;
			int exp;
		};
		std::vector<Term> P;
};

Polynomial::Polynomial(){}

Polynomial::Polynomial(const Polynomial &p){
	P = p.P;
}

// return  the coefficient of the term x^ exonent

int Polynomial::at(int exponent)const{
	int out_coeff = 0;
	bool found = false;
	int i = 0;
	while (i < P.length() && !found)P
		Term el = P.at(i);
		if (el.exp == exponent){
			out_coeff = el.coeff;
			found = true;
		}
		i++;
	}
	return out_coeff;
}

void Polynomial::set(int exponent, int coeff){
	bool found = false;
	int i = 0;
	while (i < P.length() && !found){
		Term el = P.at(i);
		if (el.exp == exponent){
			el.coeff = coeff;
			found = true;
		}
	i++
	}
	if (!found){
		Term += {coeff, exponent};
		P.push_back(t);
	}
	return;
	}

Polynomial Polynomial:diggerentiate (int order) const{
	if (order == 0){
		return *this;
	}else{
		Polynomial res;
		for (auto el: P){
			int new_exp = el.exp - 1;
			int new_coeff = el.exp * el.coeff;
			res.set (new_exp, new_coef);
		}
	}
	return res.differentiate(order -1 );
	}
}


int main(){

