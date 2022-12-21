#include "headers/calculate.h"
#include "headers/double_stack.h"
#include "headers/parse.h"
#include "headers/stack.h"
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

// double calc(double x) {
//   FILE *output1 = fopen("output.txt", "r");
//   FILE *output2 = fopen("output.txt", "r");
//   double_stack *result;
//   double temp = 0;
//   char str[128];
//   while (!feof(output1)) {
//     if (fgets(str, 126, output1)) {
//       if (is_valid_for_digit(&str[0])) {
//         fscanf(output2, "%lf", &temp);
//         result = dspush(result, temp);
//       } else if (str[0] == 'x') {
//         result = dspush(result, x);
//         fscanf(output2, "%126s", str);
//       } else if (check(str[0]) < 4) {
//         temp = bi_op(dspop(&result), dspop(&result), str[0]);
//         result = dspush(result, temp);
//         fscanf(output2, "%126s", str);
//       } else {
//         temp = un_op(dspop(&result), str[0]);
//         result = dspush(result, temp);
//         fscanf(output2, "%126s", str);
//       }
//     }
//   }
//   temp = dspop(&result);
//   return temp;
// }

// double bi_op(double x, double y, char op) {
//   double res = 0;
//   if (op == '+')
//     res = x + y;
//   if (op == '-')
//     res = x - y;
//   if (op == '*')
//     res = x * y;
//   if (op == '/')
//     res = x / y;
//   if (op == '^')
//     res = mypow(x, y);
//   return res;
// }

// double un_op(double x, char op) {
//   double res = 0;
//   if (op == 'a')
//     res = sin(x);
//   if (op == 's')
//     res = cos(x);
//   if (op == 'd')
//     res = tan(x);
//   if (op == 'f')
//     res = 1 / tan(x);
//   if (op == 'g')
//     res = sqrt(x);
//   if (op == 'h')
//     res = log(x);
//   if (op == '~')
//     res = x * -1;
//   return res;
// }

// double mypow(double x, double y) {
//     int sign = 1;
//     if (x < 0) sign *= -1;
//     return sign * pow(sign * x, y);
// }

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
