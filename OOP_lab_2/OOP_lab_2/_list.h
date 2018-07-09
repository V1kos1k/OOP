//
//  _list.h
//  OOP_lab_2
//
//  Created by Виктория on 11.04.2018.
//

#ifndef _list_h
#define _list_h

#include <iostream>
#include "list.h"
#include "_list_item.h"
#include "_list_iterator.h"
#include "errors.h"


template <typename T> class ListItem;

template <typename T>
class List {
private:
    ListItem<T> *head;
    ListItem<T> *tail;
public:
    List();
    List(T data, int n = 1);
    List(T *arr, int n = 1);
    explicit List(const List<T> &list);  // конструктор копирования
    List(List<T> &&list);  // конструктор перемещения
    List(ListIterator<T> first, ListIterator<T> last);
    
    ~List();
    
    List<T> &operator=(const List<T> &list);
    List<T> &operator=(List<T> &&list);
    
    bool operator ==(const List<T> &list) const;
    bool operator !=(const List<T> &list) const;
    
    ListIterator<T> begin();
    ListIterator<T> end();
    
    
    List<T>& Insert_after(ListIterator<T> iter, const T &value);
    
    void Push_front(const T &data);
    void Push_back(const T &data);
    void Pop_front();
    void Pop_back();
    void Remove(const T &data);
    void Reverse();
    
    
    
    ListItem<T> *Delete(const ListItem<T> &elem);
    ListItem<T> *Find(const ListItem<T> &elem) const;
    
    int size() const;
    void clear();
    bool empty() const;
    
    
    friend class ListIterator<T>;
};

#endif /* _list_h */
