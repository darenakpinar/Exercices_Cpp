#include <iostream>
#include <vector>

class Polynomial {

    public:
        Polynomial (const Polynomial& p);
        void set (int exponent, int coeff);
        int at(int exponent)const;
        int evaluate (int x)const;
        Polynomial differentiate(int order)const;
        int degree()const;
        void need();
        void print();

    private:
        int intpow(int base, int exponent)const;
        struct Term{
            int coeff;
            int exp;
        };
        std::vector<Term> P;
};

Polynomial::Polynomial(){

}

Polynomial::Polynomial(const Polynomial& p){
    P = p. P;
}

int Polynomial::at(int exponent)const{

    int out_coeff = 0;
    bool found = false;
    int i = 0;
    while (i < P.length()&& !found){
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
            found true;
        }
        i++;
    }
    if (!found){
        Term += {coeff, exponent};
        P.push_back(t);
    }
    return;
}

int Polynomial::evaluate(int x)const{
    int res= 0;
    for (auto el : P){
        res = res + el.coeff * intpow(x, el.exp);

    }
    return res;
}

int Poltnomial::degree()const{

    int deg = 0;
    for (auto el : P){
        if (el.exp > deg && el.coeff != 0){
            deg = el.exp;
        }
    }
    return deg;
}

Polynomial Polynomial::differentiate(int order)const{
    if (order == 0){
        return *this;
    }else{
        Polynomial res;
        for (auto el : P){
            if (el.exp != 0){
                int new_exp = el.exp - 1;
                int new_coeff = el.exp * el.coeff;
                res.set(new_exp, new_coeff);
            }
        }
        return res.differentiate(order -1 );
    }
}