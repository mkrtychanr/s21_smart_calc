#include "headers/double_stack.h"
#include "headers/stack.h"
#include "headers/parse.h"
#include "headers/calculate.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char str[1024];
  fgets(str, 1024, stdin);
  to_file(str);
  to_polish();
  return 0;
}
