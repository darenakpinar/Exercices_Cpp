#include <iostream>

class PriorityQueue{
    private:
        strtuct Cell{
            int key; 
            int val;
            Cell *next;
        };
        Cell *head;
}
// Ex1. implement insert method

bool PriorityQueue::is_present(int k){
    Cell *pc = head;
    while (pc){
        if (pc->key == k)
            return true;
        pc = pc->next;
    }
    return false;
}
void PriorityQueue::insert(int key, int val){
    bool present = is_present(key);

    if(present){
        if (val > 0)
            Cell *curr = head;
            Cell *prev = nullptr;
            bool found = false;
            while (curr && !found) {
            if (curr->key == key){
                if (prev)prev->next = curr->next;
                else head= curr->next;
                delete curr;
                found = true;
            }
        }
            else {
                prev = curr;
                curr = curr->next;
            }
    }
    Cell* new_cell = new Cell{key, val, nullptr};
    if (!head || val > head->val){
        new_cell->next = head; 
        head = new_cell;
    }
    else{
        curr = head;
        while (curr->next && curr->next->val >= val){
            curr = curr->next;
        new_cell->next = curr->next;
        curr->next = new_cell;
        }
        else {
            Cell *curr = head;
            Cell *prev = nullptr;
            while (curr){
                if (curr->key == key){
                    if(prev)prev->next = curr->next;
                    else head = curr->next;
                    delete curr;
                }
                else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
        else{
            if (val> 0){
                Cell *new_cell = new Cell {key, val, nullptr}
                if (!head || val > head->val){
                    new_cell->next = head;
                    head = new_cell;
                }
                else{
                    Cell * curr = head;
                    while(curr -> next && curr->next->val>=val){
                        curr =curr->next;
                        new_cell->next - curr->next;
                        curr->next = new_cell;
                    }
                }
                return;
            }
        }
    }
}