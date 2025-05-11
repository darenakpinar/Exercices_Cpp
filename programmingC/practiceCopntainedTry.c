#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}list_t;

list_t *arrayToList(int a[], int len){
    
    list_t *list = NULL;
    list_t *tmp;
    for (int i = 0; i < len; i++){
        list_t * newElement = (list_t*)malloc(sizeof(list_t));
        if (!newElement){
            perror("Exit");
            return NULL;
        }
        newElement -> data = arr[i];
        newElement -> next = NULL;   
        
        if (list == NULL){
            list = newElement;
        }else {
            tmp->next = newElement;
        }
        tmp = newElement;
    }
    return list;
}
bool isContainedL2(int el1, list *l2){

    list *el2 = l2;
    while (el2 != NULL){
        int dataEl2 = el2->data;
        if (el1 = dataEl2)
            return true;
        el2 = el2->next;
    }

    return false;
}
bool contained(list_t *l1, list_t *l2){
    list_t *el1 = l1;

    while (el1 != NULL){
        int dataEl1 = el1 -> data;
        if (!isContainedL2(dataEl1, l2))
            return false;

        el1 = el1->next;
    }

    return true;
}

int main(){

  int a1[] = {1,2};
  list_t * l1 = arrayToList(a1, 2);

	int a2[] = {1,7,9,2};
  list_t * l2 = arrayToList(a2,4);
  printf("%d\n", contained(l1, l2)); // 1

	int a3[] = {2,3};
  list_t * l3 = arrayToList(a3,2);
  printf("%d\n",contained(l1, l3)); // 0

  return 0;
}