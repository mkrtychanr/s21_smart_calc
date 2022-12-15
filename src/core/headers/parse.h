#ifndef SRC_HEADERS_PARSE_H_
#define SRC_HEADERS_PARSE_H_

int is_br_open(const char *ptr);
int is_br_close(const char *ptr);
int is_plus(const char *ptr);
int is_minus(const char *ptr);
int is_multiply(const char *ptr);
int is_divide(const char *ptr);
int is_pow(const char *ptr);
int is_sin(char *ptr);
int is_cos(char *ptr);
int is_tan(char *ptr);
int is_ctg(char *ptr);
int is_sqrt(char *ptr);
int is_ln(char *ptr);
int is_digit(const char *ptr);
int is_valid_for_digit(char *ptr);
void to_file(char *s);

#endif  // SRC_HEADERS_PARSE_H_
