/*!
\file
\brief Заголовочный файл с объявлениями функций связанных с парсингом файлов для последующей компиляции
*/

#ifndef SRC_HEADERS_S21_PARSE_H_
#define SRC_HEADERS_S21_PARSE_H_

/**
 * @brief Проверка на открытую скобку
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_br_open(const char *ptr);

/**
 * @brief Проверка на закрытую скобку
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_br_close(const char *ptr);

/**
 * @brief Проверка на плюс
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_plus(const char *ptr);

/**
 * @brief Проверка на минус
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_minus(const char *ptr);

/**
 * @brief Проверка на умножение
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_multiply(const char *ptr);

/**
 * @brief Проверка на деление
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_divide(const char *ptr);

/**
 * @brief Проверка на возведение в степень
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_pow(const char *ptr);

/**
 * @brief Проверка на остаток от деления
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_mod(const char *ptr);

/**
 * @brief Проверка на синус
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_sin(char *ptr);

/**
 * @brief Проверка на арксинус
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_asin(char *ptr);

/**
 * @brief Проверка на косинус
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_cos(char *ptr);

/**
 * @brief Проверка на арккосинус
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_acos(char *ptr);

/**
 * @brief Проверка на тангенс
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_tan(char *ptr);

/**
 * @brief Проверка на арктангенс
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_atan(char *ptr);

/**
 * @brief Проверка на котангенс
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_ctg(char *ptr);

/**
 * @brief Проверка на квадратный корень
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_sqrt(char *ptr);

/**
 * @brief Проверка на натуральный логарифм
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_ln(char *ptr);

/**
 * @brief Проверка на десятичный логарифм
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_log(char *ptr);

/**
 * @brief Проверка на число
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_digit(const char *ptr);

/**
 * @brief Проверка на валидность числа
 * 
 * @param ptr Указатель на строку
 * @return int 1 если является, 0 если нет
 */
int is_valid_for_digit(char *ptr);

/**
 * @brief Запись в файл выражения в инфиксной нотации
 * 
 * @param s Строка с выражением
 */
void to_file(char *s);

#endif  // SRC_HEADERS_S21_PARSE_H_
