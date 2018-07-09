//
//  _list_iterator.h
//  OOP_lab_2
//
//  Created by Виктория on 11.04.2018.
//

#ifndef _list_iterator_h
#define _list_iterator_h

#include "_list.h"
#include "_list_item.h"
#include "errors.h"

template <typename T> class List;
template <typename T> class ListItem;

template <typename T>
class IteratorBase {
    
public:
    T *current;
    virtual void first() = 0;
    virtual void last() = 0;
    virtual void next() = 0;
    virtual bool range() = 0;
};

template <typename T>
class ListIterator : public IteratorBase<ListItem<T>> {
private:
    const List<T> *list;
public:
    ListIterator(const List<T> &l);
    
    ~ListIterator(); // деструктор
    
    void first();  // T*
    void last();
    void next();
    bool range();
    const T Current();
    
    ListIterator<T> operator ++(int);
    
    bool operator !=(ListIterator<T> &rhs);
    
    
};

#endif /* _list_iterator_h */
