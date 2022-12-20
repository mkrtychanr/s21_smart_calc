#include "headers/double_stack.h"
#include "headers/stack.h"
#include "headers/parse.h"
#include "headers/calculate.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  argc = argc + 1 - 1;
  to_file(argv[1]);
  to_polish();
  return 0;
}
