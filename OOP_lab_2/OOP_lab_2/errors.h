//
//  errors.h
//  OOP_lab_2
//
//  Created by Виктория on 12.04.2018.
//

#ifndef errors_h
#define errors_h

#include <iostream>
#include <exception>


class Error : public std::exception {
public:
    virtual const char *what() const throw()
    {
        return "Ошибка";
    }
};

class MemoryError : public Error {
    const char *what() const throw() {
        return "Ошибка выделения памяти";
    }
};

class RangeError : public Error {
    const char *what() const throw() {
        return "Список вышел за допустимые границы";
    }
};

class EmptyError : public Error {
    const char *what() const throw() {
        return "Пустой список.";
    }
};

class CountError : public Error {
    const char *what() const throw() {
        return "Размер списка не может быть отрицательным";
    }
};

class FindError : public Error {
    const char *what() const throw() {
        return "Элемент не найдет";
    }
};

#endif /* errors_h */
