#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list{
    int data;
    struct list *next;
}list_t;

list_t *arrToList(int a[], int len){
    list_t *list = NULL;
    list_t *tmp;

    for (int i = 0; i < len; i++){
        list_t *newNumber = (list_t*)malloc(sizeof(list_t));
        if (!newNumber){
            perror("exit");
            return NULL;
        }
        newNumber->data = a[i];
        newNumber->next = NULL;

        if (list == NULL){
            list = newNumber;
        }else{
            tmp->next = newNumber;
        }
        tmp = newNumber;
    }
    return list;
}
int elementFreq(list_t l1, int x){
    list_t *el1 = l1;
    int freq = 0;
    while (el1 != NULL){
        if (x == el1->data){
            freq++;
        }
        el1 = el1->next;
    }
    return freq;
}
bool alreadyIn(list_t *l, int x){
    list_t *el = l;
    while(el != NULL){
        if(el->data == x){
            return true;
        }
        el = el->next;
    }
    return false;

}

list_t *dups(list_t *l1){
    list_t *el1 = l1;
    list_t *result = NULL;
    list_t *tmp;
    while (el1 != NULL){
        list_t *newElement = (list_t*)malloc(sizeof(el1));
        int dataEl1 = el1->data;
        if (elementFreq(el1, dataEl1) >= 2 && !alreadyIn(result, dataEl1)){
            newElement->data = dataEl1;
            newElement->next = NULL;
            if (result == NULL){
                result = newElement;
            }else{
                tmp->next = newElement;
            }
            tmp = newElement;
    }
    return result;
}
void freeList(list_t *head) {
    list_t *p = head;
    while (p) {
        list_t *next = p->next;
        free(p);
        p = next;
    }
}


int main(){
    int a1[] = {1,1,2,3,1,2,4};
    list_t *l1 = arrToList(a1, 7);
    
    list_t *l2 = dups(l1);

    freeList(l1);
    freeList(l2);
    
    return 0;
}