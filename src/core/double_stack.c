#include "headers/double_stack.h"
#include <stdlib.h>

double_stack *dsinit(double data) {
  double_stack *new_head = malloc(sizeof(double_stack));
  new_head->data = data;
  new_head->next = NULL;
  return new_head;
}

double_stack *dspush(double_stack *head, double data) {
  double_stack *new_head = dsinit(data);
  new_head->next = head;
  return new_head;
}

double dspop(double_stack **head) {
  double result = (*head)->data;
  double_stack *ptr = *head;
  *head = (*head)->next;
  free(ptr);
  return result;
}

void dsdestroy(double_stack *head) {
  if (head->next != NULL) {
    dsdestroy(head->next);
  }
  free(head);
}
