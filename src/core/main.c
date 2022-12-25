#include "headers/s21_parse.h"
#include "headers/s21_calculate.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *expression_file = fopen(".expression", "r");
  char expression[1024];
  fgets(expression, 1024, expression_file);
  to_file(expression);
  to_polish();
  return 0;
}
