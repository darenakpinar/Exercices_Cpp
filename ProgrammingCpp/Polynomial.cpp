#include <iostream>
#include <vector>

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
