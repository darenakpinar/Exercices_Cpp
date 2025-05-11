#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
    int data;
    struct list *next;
} list_t;

// Build a list from an array:
list_t *arrToList(int arr[], int len) {
    list_t *head = NULL, *tail = NULL;
    for (int i = 0; i < len; i++) {
        list_t *node = malloc(sizeof *node);
        if (!node) { perror("malloc"); exit(1); }
        node->data = arr[i];
        node->next = NULL;
        if (!head) head = node;
        else       tail->next = node;
        tail = node;
    }
    return head;
}

// Returns true if x is found in list l
bool contains(list_t *l, int x) {
    for (; l; l = l->next)
        if (l->data == x)
            return true;
    return false;
}

// Return a *new* list containing all elements of a
// that are NOT in b.
list_t *filter(list_t *a, list_t *b) {
    list_t *res = NULL, *tail = NULL;
    for (; a; a = a->next) {
        if (!contains(b, a->data)) {
            list_t *node = malloc(sizeof *node);
            if (!node) { perror("malloc"); exit(1); }
            node->data = a->data;
            node->next = NULL;
            if (!res) res = node;
            else       tail->next = node;
            tail = node;
        }
    }
    return res;
}

// Free every node in the list
void freeList(list_t *l) {
    while (l) {
        list_t *nx = l->next;
        free(l);
        l = nx;
    }
}

int main(void) {
    int a1[] = {7,1,0,3,4,1,3};
    int a2[] = {1,3};

    list_t *l1 = arrToList(a1, 7);
    list_t *l2 = arrToList(a2, 2);

    list_t *l3 = filter(l1, l2);

    // Print l3 to verify
    for (list_t *p = l3; p; p = p->next)
        printf("%d ", p->data);
    putchar('\n');

    freeList(l1);
    freeList(l2);
    freeList(l3);
    return 0;
}
