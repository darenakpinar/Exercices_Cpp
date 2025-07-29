#include <stdio.h>
#include <stdlib.h>
#include <bool.h>

typedef struct n{
    int data;
    struct n* next;
}node;

node *clone_even(node const* L){
    node *head = NULL;
    node *tail = NULL;
    while (L != NULL){\
        if (L->data % 2 == 0){
        node *newElement = (node*)malloc(sizeof(node));
           if (!newElement) exit(1);

            newElement->data = L->data;
            newElement->next = NULL;
              
            if (head == NULL){
                head =newElement;
                tail = newElement;
            }else{
                tail->next = newElement;
                tail = newElement;
            }
            
        }
        L = L->next;
    }
    return head;
}