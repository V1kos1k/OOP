//
//  list_iterator.h
//  OOP_lab_2
//
//  Created by Виктория on 11.04.2018.
//

#ifndef list_iterator_h
#define list_iterator_h

#include <iostream>
#include "_list_iterator.h"


template <typename T>
ListIterator<T>::ListIterator(const List<T> &l) {
    //std::cout << "(0.0)";
    this->list = &l;
    this->current = l.head; // текущий указывает на голову
};

template <typename T>
ListIterator<T>::~ListIterator() {
    this->list = nullptr;
    this->current = nullptr;
    //std::cout << "ListIterator" << std::endl;
};

template <typename T>
void ListIterator<T>::first() {
    this->current = this->list->head;
    // return this->list->head;
}

template <typename T>
void ListIterator<T>::next() {
    if (!this->range()) {
        std::cout << "Список вышел за допустимые границы (LI next)";
        throw RangeError();
    }
    //std::cout << "+";
    this->current = this->current->next;
}

template <typename T>
void ListIterator<T>::last() {
    this->current = this->list->tail->next;
    // return this->list->tail;
}

template <typename T>
bool ListIterator<T>::range() {
    //std::cout << "(0.7)";
    return !(this->current == nullptr);
};


template <typename T>
const T ListIterator<T>::Current() {
    if (!this->range())
    {
        std::cout << "Список вышел за допустимые границы (LI Current)";
        throw EmptyError();
    }
    return this->current->data;
};

////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
ListIterator<T> ListIterator<T>::operator ++(int) {
    if (!this->range()) {
        std::cout << "Список вышел за допустимые границы (LI ++)";
        throw RangeError();
    }
    ListIterator<T> substitute(*this);
    this->next();
    //std::cout << "(0.9)";
    return substitute;
}

template <typename T>
bool ListIterator<T>::operator !=(ListIterator<T> &rhs) {
    //std::cout << "(0.15)" << std::endl;
    return this->current != rhs.current;
};

#endif /* list_iterator_h */
