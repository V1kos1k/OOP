//
//  list_item.h
//  OOP_lab_2
//
//  Created by Виктория on 11.04.2018.
//

#ifndef list_item_h
#define list_item_h

#include <iostream>
#include "_list_item.h"

template <typename T>
ListItem<T>::ListItem() {
    this->next = nullptr;
    //std::cout << "(1.1)";
};

template <typename T>
ListItem<T>::~ListItem() {
    this->next = nullptr;;
    //std::cout << "ListItem" << std::endl;
};


#endif /* list_item_h */
