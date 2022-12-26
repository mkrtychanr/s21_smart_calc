/*!
\file
\brief Заголовочный файл с объявлениями функций связанных с компиляцией выржания из инфискной в постфиксную нотацию
*/

#ifndef SRC_HEADERS_S21_CALCULATE_H_
#define SRC_HEADERS_S21_CALCULATE_H_

/**
 * @brief Перевод строки из файла рядом в польскую нотацию
 * 
 */
void to_polish();

/**
 * @brief Функция определения статуса состояния выражения
 * 
 * @param c Последний принятый символ
 * @return int Статус состояния
 */
int check(char c);

#endif  // SRC_HEADERS_S21_CALCULATE_H_
