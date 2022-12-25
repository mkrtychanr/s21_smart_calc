#include "headers/s21_calculate.h"
#include "headers/s21_parse.h"
#include "headers/s21_stack.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void to_polish() {
  FILE *input = fopen("1.txt", "r");
  FILE *output = fopen("output.txt", "w");
  stack *temp = NULL;
  char str[128];
  while (!feof(input)) {
    if (fgets(str, 126, input)) {
      if (is_valid_for_digit(str)) {
        fprintf(output, "%s", str);
      } else if (str[0] == '(') {
        temp = push(temp, '(');
      } else if (str[0] == ')') {
        while (temp != NULL && top(temp) != '(') {
          fprintf(output, "%c\n", top(temp));
          temp = pop(temp);
        }
        temp = pop(temp);
      } else if (check(str[0]) != -1) {
        while (temp != NULL && check(str[0]) <= check(top(temp))) {
          fprintf(output, "%c\n", top(temp));
          temp = pop(temp);
        }
        temp = push(temp, str[0]);
      } else if (str[0] == 'x') {
        fprintf(output, "%c\n", 'x');
      }
    }
  }
  while (temp != NULL) {
    fprintf(output, "%c\n", top(temp));
    temp = pop(temp);
  }
  free(temp);
  fclose(input);
  fclose(output);
  system("rm -rf 1.txt");
}

int check(char c) {
  int result = -1;
  if (c == '(')
    result = 0;
  if (c == '+')
    result = 1;
  if (c == '-')
    result = 1;
  if (c == '*')
    result = 2;
  if (c == '/')
    result = 2;
  if (c == '%')
    result = 3;
  if (c == '^')
    result = 3;
  if (c == '~')
    result = 4;
  if (c == 'a')
    result = 5;
  if (c == 's')
    result = 5;
  if (c == 'd')
    result = 5;
  if (c == 'f')
    result = 5;
  if (c == 'g')
    result = 5;
  if (c == 'h')
    result = 5;
  if (c == 'j')
    result = 5;
  if (c == 'k')
    result = 5;
  if (c == 'l')
    result = 5;
  if (c == 'z')
    result = 5;
  return result;
}
