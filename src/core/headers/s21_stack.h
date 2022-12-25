#ifndef SRC_HEADERS_S21_STACK_H_
#define SRC_HEADERS_S21_STACK_H_

typedef struct stack {
  char data;
  struct stack *next;
} stack;

stack *init(char c);
stack *push(stack *head, char c);
char top(stack *head);
stack *pop(stack *head);
#endif  // SRC_HEADERS_S21_STACK_H_
