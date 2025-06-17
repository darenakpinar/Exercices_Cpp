#include <stdio.h>
#include <stdlib.h>


bool isContainedInResult(int dataEl, list_t * result) {

  list_t * tmp = result;
  while(tmp != NULL) {
    int dataRes = tmp->data;
    if(dataEl == dataRes)
      return true;

    tmp = tmp->next;
  }
  return false;
}

bool occursAtLeastAnotherTime(int dataEl, list_t *l) {

  list_t * tmp = l;
  while(tmp != NULL) {
    int data = tmp->data;
    if(dataEl == data)
      return true;

		tmp = tmp->next;
  }

  return false;
}

list_t * dups(list_t *l) {

  list_t * result = NULL;

  list_t * el = l;
  while(el != NULL) {
    int dataEl = el->data;
    if(!isContainedInResult(dataEl, result)) {
      if(occursAtLeastAnotherTime(dataEl, el->next)) {
        list_t * newElement = malloc(sizeof(list_t));
				newElement -> data = dataEl;
				newElement -> next = NULL;
        if(result == NULL) {
          result = newElement;
        } else {
          result->next = newElement;
        }
      }
    }
    el = el->next;
  }

  return result;

}
