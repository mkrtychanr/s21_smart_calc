#ifndef SRC_HEADERS_DOUBLE_STACK_H_
#define SRC_HEADERS_DOUBLE_STACK_H_

typedef struct double_stack {
  double data;
  struct double_stack *next;
} double_stack;

double_stack *dsinit(double data);
double_stack *dspush(double_stack *head, double data);
double dspop(double_stack **head);
double dstop(double_stack *head);
void dsdestroy(double_stack *head);

#endif  // SRC_HEADERS_DOUBLE_STACK_H_
