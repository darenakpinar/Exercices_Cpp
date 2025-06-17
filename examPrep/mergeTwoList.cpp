#include <iostream>
#include <vector>

struct Cell{
    int info;
    Cell *next;
};
typedef Cell * List;

List merge(List l1, list l2){
    if (l1 == nullptr && l2 == nullptr){
        return nullptr;
    }else {
        List l_m = new Cell;
        if (l1 -> info < l2 -> info){
            l_m -> info = l1 -> info;
            l_m -> next = merge(l1->next, l2);
        }else{
            l_m -> info = l2->info;
            l_m->next = merge(l1, l2->next); 
        }
        if (l2 == nullptr){ // l2 is empty
            l_m->info = l1->info;
            l_m->next = merge(l1 ->next, l2);
        }
        if (l1 == nullptr){ // l1 is empty

            l_m->info = l2->info;
            l_m->next = merge(l1, l2->next);
        }

    }
    return l_m;
}
 /* In my opinion we should change the order of the if - else branches and put the nullptr possibilities to above */