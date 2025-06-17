#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;

}node;

int sumList(node *head){

    if (head == NULL) return 1;

    return head->data + sumList(head -> next);
}