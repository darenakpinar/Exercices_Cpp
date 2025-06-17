#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct n{
    int data;
    struct n* next;
}node;

node *clone_even(node *l1){
    node *head = NULL;
    node *tail = NULL;

    while (l1){
        node *addEven = (node*)malloc(sizeof(node));
        if(!addEven)return NULL;

        if (l1->data % 2 == 0){
            addEven->data = l1->data;
            addEven->next = NULL;

            if (head == NULL){
                head = addEven;
                tail = addEven;
            }else{
                tail->next = addEven;
                tail = addEven;
            }

            l1 = l1->next;
        }
    }

    return head;
}

int main(){
    node *L = NULL;
    node *E = clone_even(L);

    return 0;
}