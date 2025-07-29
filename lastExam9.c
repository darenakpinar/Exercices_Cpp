#include <stdio.h>

typedef struct n{
    char letter;
    int freq;
    struct n* next;
}node;

void sorted_add(node** head, char l, int f){
    node *n = (node*)malloc(sizeof(node));
    n->letter = l;
    n->freq = f;
    n->next = NULL;

    node *ptr = *head; // Pointer to current node 
    node *prev = NULL; // pointer to previous node 
    while (ptr != NULL && (ptr -> letter < l || (ptr->letter == l && ptr->freq < f))){
        prev = ptr; 
        ptr = ptr->next;
    }
    if (prev == NULL){
        n->next = *head;
        *head = n;
    }else {
        prev->next = n;
        n->next = ptr;
    }
}

int main(){
 node* head = NULL;
 sorted_add(&head, 'n', 3);
 sorted_add(&head, 'd', 3);
 sorted_add(&head, 'd', 8);
 sorted_add(&head, 'm', 0);
 sorted_add(&head, 'i', -2);

 // so now the list is:
 (d,3) -> (d,8) -> (i,-2) -> (m,0) -> (n,3) -> NULL

 // after
 sorted_add(&head, 'l', 11);
 sorted_add(&head, 'd', -2);

 // the list will be
(d,-2) -> (d,3) -> (d,8) -> (i,-2) -> (l,11) -> (m,0) -> (n,3) -> NULL
}