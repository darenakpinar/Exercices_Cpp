#include <iostream>
#include <vector>

class mylist{
public:
	int mylist;
};

int mylist::sum()const{
	return sum_rec(head);
}
int mylist:: sum_rec(list l ) const {
	if (l == nullptr) return 0;
	
	else return l -> info + sum_rec(l -> next);


}
bool myclass :: operator == (const myclass & s) const{
	return equal_rec(head, s.head);

//private 
bool myclass :: equal_vec(list l1, list l2) const {
	if (l1 == nullbtr && l2 == nullbtr) return true;
	else{
		if (l1 == nullptr || l2 == nullptr) return false;
		
		else return (l1 -> info == l2->info) && equal_vec(l1->next, l2->next);	

	return (l1 -> info == l2 -> info) && equal_vec(l1->next, l2-> next);
}

