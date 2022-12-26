/*!
\file
\brief Заголовочный файл с объявлениям класса снимков состояний
*/


#ifndef MOMENT_H
#define MOMENT_H

struct Moment {

    /**
     * @brief Счетчик открытых скобок
     * 
     */
    int bracketCounter = 0;

    /**
     * @brief Статус снимка
     * 
     */
    int status = 0;

    /**
     * @brief Сколько символов данный снимок занимает
     * 
     */
    int characters = 0;

    /**
     * @brief Конструктор снимка
     * 
     * @param bracketCounter – Новое количество открытых скобок
     * @param status – Новое состояние снимка
     * @param characters – Новая длинна снимка
     */
    Moment(int bracketCounter, int status, int characters) {
        this -> bracketCounter = bracketCounter;
        this -> status = status;
        this -> characters = characters;
    }
};


#endif // MOMENT_H