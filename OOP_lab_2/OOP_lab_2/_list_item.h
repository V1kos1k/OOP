//
//  _list_item.h
//  OOP_lab_2
//
//  Created by Виктория on 11.04.2018.
//

#ifndef _list_item_h
#define _list_item_h

#include "_list.h"
#include "_list_iterator.h"
#include "errors.h"

//template <typename T> class List;

template <typename T>
class ListItem {
private:
    ListItem *next;
    T data;
public:
    ListItem();
    //ListItem(T data);
    
    ~ListItem();
    
//    T get_data() const;
//    void set_data(T data);
    
    friend class List<T>;
    friend class ListIterator<T>;
};

#endif /* _list_item_h */
