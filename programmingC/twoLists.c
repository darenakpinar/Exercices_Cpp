#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list{
	int data;
	struct list *next;
}list_t;

int compare(list_t  *a, list_t *b_original){

	int flag = 1;
	bool found;
while (a != NULL && found != false){

	list_t *b = b_original;
	while (b != NULL){
		found = false;
		
		if (a->data == b->data){
			found = true;
			break;
		}
		b = b->next;
	}
	if (!found) flag = 0;
	a->next;
}
return flag;
}

