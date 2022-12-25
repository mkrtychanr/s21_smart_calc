#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/s21_stack.h"
#include "headers/s21_parse.h"
#include "headers/s21_calculate.h"

int fill_str(char *out, char *src) {
  int i = 0;
  int n = strlen(src) - 1;
  for (; i < n; i++) {
    if (src[i] != '\n') {
      out[i] = src[i];
    }
  }
  return i;
}

void from_file_to_str(char *out) {

  FILE* expression = fopen("output.txt", "r");
  char buffer[32];
  int i = 0;
  while (fgets(buffer, 32, expression)) {
    i += fill_str(out + i, buffer);
  }
  out[i] = '\0';
}

START_TEST(test_to_polish) {
    pop(NULL);
    char* str = "sin(cos(tan(ctg(asin(acos(atan(ln(log(sqrt(-(x+123*4.5o6-0.56/789*0^0%1)))))))))))";
    to_file(str);
    to_polish();
    char res[1024];
    from_file_to_str(res);
    ck_assert_str_eq(res, "x1234.56*+0.56789/00^1%*-~gzhlkjfdsa");

}
END_TEST

Suite *to_polish_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("polish check");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_polish);
  suite_add_tcase(s, tc_core);

  return s;
}

int to_polish_test_func() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = to_polish_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}

int main() {
  int no_failed = 0;

  no_failed |= to_polish_test_func();

  // return 0;
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}