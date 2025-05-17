#include <iostream>
#include <vector>

class PriorityQueue{
	private:
		struct Cell{
			int key;
			int val;
			Cell* next;
		};
		Cell *head;
	public:


}
// implement 
bool PriorityQueu::is_present(int k){
	Cell *pc = head;
	while (pc){
		if (pc->key == k){
			return true;
		}
	pc = pc->next;
	}
	return false;
}
void PriorityQueue::insert(int key, int val){
	vetcor<int> q= {};
	for (int i = 0; i < val; i++){

