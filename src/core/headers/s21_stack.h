/*!
\file
\brief Заголовочный файл с объявлениями функций для работы стека
*/

#ifndef SRC_HEADERS_S21_STACK_H_
#define SRC_HEADERS_S21_STACK_H_

/**
 * @brief Объявление структуры
 * 
 */
typedef struct stack {
  char data;
  struct stack *next;
} stack;


/**
 * @brief Инициализация стека
 * 
 * @param c – Первый элемент, который будет закинут в стек
 * @return stack* 
 */
stack *init(char c);

/**
 * @brief Добавление в стек нового значения
 * 
 * @param head – Указатель на голову стека
 * @param c – Новый элемент стека
 * @return stack* – Новая голова стека
 */
stack *push(stack *head, char c);

/**
 * @brief Возвращение верха стека
 * 
 * @param head – Указатель на голову стека
 * @return char 
 */
char top(stack *head);

/**
 * @brief Удаление элемента из стека
 * 
 * @param head – Указатель на голову стека
 * @return stack* – Новая голова стека
 */
stack *pop(stack *head);
#endif  // SRC_HEADERS_S21_STACK_H_
