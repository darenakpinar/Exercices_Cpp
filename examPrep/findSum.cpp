#include <iostream>
#include <vector>

struct Cell {
    int info;
    Cell *next;
};
typedef Cell * List;

bool findsum(List l, int sum, int add ){

    if (sum == 0 && add == 0)return true;

    if (l == nullptr) return false;

    int val = l->info;
    bool res1 = findsum(l->next, sum -val, add -1);
    bool res2 = findsum(l->next, sum, add);

    return res1 || res2;
}