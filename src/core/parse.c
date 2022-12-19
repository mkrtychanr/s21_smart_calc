#include "headers/parse.h"
#include <stdio.h>
#include <string.h>

void to_file(char *s) {
  int status = 0;
  FILE *f = fopen("1.txt", "w");
  char *ptr = s;
  while (*ptr != '\0') {
    if (status == 0 && is_minus(ptr)) {
      fprintf(f, "~\n");
      ptr++;
      status = 1;
    } else if (is_valid_for_digit(ptr)) {
      while (*ptr != '\0' && is_valid_for_digit(ptr)) {
        fprintf(f, "%c", *ptr);
        ptr++;
      }
      fprintf(f, "\n");
      status = 2;
    } else if (is_plus(ptr)) {
      fprintf(f, "+\n");
      ptr++;
    } else if (is_minus(ptr)) {
      fprintf(f, "-\n");
      ptr++;
    } else if (is_multiply(ptr)) {
      fprintf(f, "*\n");
      ptr++;
    } else if (is_divide(ptr)) {
      fprintf(f, "/\n");
      ptr++;
    } else if (is_pow(ptr)) {
      fprintf(f, "^\n");
      ptr++;
    } else if (is_mod(ptr)) {
      fprintf(f, "%%\n");
      ptr++;
    } else if (is_br_close(ptr)) {
      fprintf(f, ")\n");
      status = 0;
      ptr++;
    } else if (is_br_open(ptr)) {
      fprintf(f, "(\n");
      status = 0;
      ptr++;
    } else if (is_sin(ptr)) {
      fprintf(f, "a\n");
      ptr += 3;
    } else if (is_cos(ptr)) {
      fprintf(f, "s\n");
      ptr += 3;
    } else if (is_tan(ptr)) {
      fprintf(f, "d\n");
      ptr += 3;
    } else if (is_ctg(ptr)) {
      fprintf(f, "f\n");
      ptr += 3;
    } else if (is_sqrt(ptr)) {
      fprintf(f, "g\n");
      ptr += 4;
    } else if (is_ln(ptr)) {
      fprintf(f, "h\n");
      ptr += 2;
    } else if (is_log(ptr)) {
      fprintf(f, "z\n");
      ptr += 3;
    } else if (is_asin(ptr)) {
      fprintf(f, "j\n");
      ptr += 4;
    } else if (is_acos(ptr)) {
      fprintf(f, "k\n");
      ptr += 4;
    } else if (is_atan(ptr)) {
      fprintf(f, "l\n");
      ptr += 4;
    } else if (*ptr == 'x') {
      fprintf(f, "x\n");
      ptr++;
    } else {
      ptr++;
    }
  }
  fclose(f);
}

int is_br_open(const char *ptr) { return *ptr == '('; }
int is_br_close(const char *ptr) { return *ptr == ')'; }
int is_plus(const char *ptr) { return *ptr == '+'; }
int is_minus(const char *ptr) { return *ptr == '-'; }
int is_multiply(const char *ptr) { return *ptr == '*'; }
int is_divide(const char *ptr) { return *ptr == '/'; }
int is_pow(const char *ptr) { return *ptr == '^'; }
int is_mod(const char *ptr) { return *ptr == '%'; }
int is_sin(char *ptr) {
  return *ptr == 's' && *(ptr + 1) == 'i' && *(ptr + 2) == 'n';
}
int is_asin(char *ptr) {
  return *ptr == 'a' && *(ptr + 1) == 's' && *(ptr + 2) == 'i' && *(ptr + 3) == 'n';
}
int is_cos(char *ptr) {
  return *ptr == 'c' && *(ptr + 1) == 'o' && *(ptr + 2) == 's';
}
int is_acos(char *ptr) {
  return *ptr == 'a' && *(ptr + 1) == 'c' && *(ptr + 2) == 'o' && *(ptr + 3) == 's';
}
int is_tan(char *ptr) {
  return *ptr == 't' && *(ptr + 1) == 'a' && *(ptr + 2) == 'n';
}
int is_atan(char *ptr) {
  return *ptr == 'a' && *(ptr + 1) == 't' && *(ptr + 2) == 'a' && *(ptr + 3) == 'n';
}
int is_ctg(char *ptr) {
  return *ptr == 'c' && *(ptr + 1) == 't' && *(ptr + 2) == 'g';
}
int is_sqrt(char *ptr) {
  return *ptr == 's' && *(ptr + 1) == 'q' && *(ptr + 2) == 'r' &&
         *(ptr + 3) == 't';
}
int is_ln(char *ptr) { return *ptr == 'l' && *(ptr + 1) == 'n'; }
int is_log(char *ptr) { return *ptr == 'l' && *(ptr + 1) == 'o' && *(ptr + 2) == 'g'; }
int is_digit(const char *ptr) {
  return 48 <= *ptr && *ptr <= 57 && *ptr != '\0';
}
int is_valid_for_digit(char *ptr) {
  return is_digit(ptr) || (*ptr == 46 && is_digit(ptr + 1));
}

int find_eq(char *ptr) {
  int len = strlen(ptr);
  int result = -1;
  for (int i = 0; i < len; i++) {
    if (ptr[i] == '=') {
      result = i;
      break;
    }
  }
  return result;
}