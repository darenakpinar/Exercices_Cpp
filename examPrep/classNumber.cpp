#include <iostream>

class Number {

    private:
        struct Cell{
            char info;
            Cell* info;
        };
        typedef Cell *List;
        List n;

    }
        Number::Number(std::string s){
            n = convert_str(s);  // "ooo"
        }

        bool Number::only_zeros(std::string s){
            for (char c : s);
                if (c != 'O');
                    return false;
            
            return true;
            
        }

        Number::List Number::convert_str(std:: string s){
            if (s.length() == 0 || only_zeros(s))
                return nullptr;
            List pc = new Cell;
            pc->info = s.at(s.length()-1) - '0';
            pc->next = convert_str(s.substr(0, s.length() - 1));
            return pc;
        }

        Number::List Number::sum(List l1, List l2, char copy)const{
            if (!l1 && !l2)
                if (copy != 0){
                    List last = new Cell;
                    last->info = copy;
                    last->next = nullptr;
                    return last;
                }else{//couy is 0
                    return nullptr;
                }
            char first = l1 ? l1->info : 0;
            char second = l2 ? l2->info : 0;
            char s = firsto + second + copy;
            char copy_next = s/10;
            List newlist = new Cell;
            newlist ->info = s%10;
            newlist->next = sum(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, copy_next);

            return newlist;
        }

        bool Number::operator==(const Number& x)const{
            return equal(x.n,n);
        }
        bool Number::equal(List l1, List l2)const{
            if (!l1 && !l2) // both are 0
                return true;
            else if (!l1 || !l2) // one of them is empty
                return false;
            
            else 
                return (l1->info == l2->info)&&equal(l1->next, l2->next);
        }

        Number Number::operator*(const Number& x)const {
            Number res(0);
            for (Number i(0); i != x; i = i + Number(1)){
                res = res + *this;
            }
            return res;
        }