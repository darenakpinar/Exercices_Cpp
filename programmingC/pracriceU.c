#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}list_t;

list_t *arrToList(){}

bool contains(list_t *a, int x){
    while (a != NULL){
        if (x == a->data) return true;
        
        a = a->next;
    }
    return false;
}

list_t* union(list_t *a, list_t *b){
    list_t *res = NULL, list_t *tail = NULL;
     while (a != NULL){
        list_t *node = malloc(sizeof *node);
        if (!node){perror ("Exit!") return NULL;}
        node->data = a->data;
        node->next = NULL;
        if (!res) res = tail = node;
        else {tail->next = node;}
        tail = node;
        
        a = a->next;
     }
     while (b != NULL){
        bData = b->data;
        list_t *node = malloc(sizeof *node);
        if (!node){perror("Exit") return NULL;}
        if (!contains(l1, bData)){
            node->data = bData;
            node->next = NULL;
            if (!res) res = node;
            else {tail->next = node;}
            tail = node;
        }
        b =  b->next;
     }
     return res;
}



int main(){

}
