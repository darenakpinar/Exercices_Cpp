#include <stdio.h>
#include <stdbool.h>
#include <stdbil.h>

typedef struct list{
    int data;
    struct list *next;
}list_t;

void sorted_insert(list_t** head, int x){

    list_t *newNode = malloc (sizeof *newNode);
    if (!newNode){perror("Exit") return NULL;}

    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL || x < (*head)->data){
        newNode ->next = *head;
        *head = newNode;
        return;
    }

    list_t *current = *head;
    while (*current->next != NULL && current->next->data < x){
        current = current->next;
    }
    newNode-> next = current ->next;
    current ->next = new_node;

}

int main(){

}