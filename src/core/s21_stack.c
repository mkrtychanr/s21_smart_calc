#include "headers/s21_stack.h"
#include <stdlib.h>
#include <stdio.h>

stack *init(char c) {
  stack *new_head = malloc(sizeof(stack));
  new_head->data = c;
  return new_head;
}

stack *push(stack *head, char c) {
  stack *new_head = init(c);
  new_head->next = head;
  return new_head;
}

char top(stack *head) { return head->data; }

stack *pop(stack *head) {
  stack *new_head = NULL;
  if (head != NULL) {
    new_head = head->next;
    free(head);
  }
  return new_head;
}
