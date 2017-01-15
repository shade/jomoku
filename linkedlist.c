#include "linkedlist.h"




void push_move(LinkedList* list, int thing, int value) {
  LinkedList current = list->next;

  while (current != NULL) {
    if (current->next->value < value) {
      LinkedList new = NULL;
      new = malloc(sizeof(new));
      
      new->move = move;
      new->value = value;
      new->next = current->next;
      current->next = &new;
    }
  }
}






