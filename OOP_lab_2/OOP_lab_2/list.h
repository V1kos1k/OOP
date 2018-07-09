//
//  list.h
//  OOP_lab_2
//
//  Created by Виктория on 11.04.2018.
//

#ifndef list_h
#define list_h

#include <iostream>
#include "_list.h"

//using namespace std;

template <typename T>
List<T>::List() {
    this->head = nullptr;
    this->tail = nullptr;
};

template <typename T>
List<T>::~List() {
    //std::cout << "List" << std::endl;
    if(this->head)
    {
        ListItem<T>* next;
        for(; this->head; this->head = next)
        {
            next = this->head->next;
            delete this->head;
            
        }
    }
    this->head = nullptr;
    this->tail = nullptr;
};

// (2.5)
template <typename T>
List<T>::List(T data, int n) {
    //std::cout << "(2.5)" << std::endl;
    //std::cout << "\n" << n << std::endl;
    if (n < 0) {
        //std::cout << "((()))";
        throw CountError();
    }
    else if (n == 0) {
        this->head = nullptr;
        this->tail = nullptr;                 /////////////////////////////////////////////////////////////////////////////////////////////
    }
    else {
        ListItem<T> *head = new ListItem<T>;
        if (!head)
            throw MemoryError();
        head->data = data;  //head->set(data);
        this->head = head;
        ListItem<T> *c = head;
        for (size_t i = 0; i < n-1; i++) {
            //std::cout << "+";
            ListItem<T> *item = new ListItem<T>;
            if (!item)
                throw MemoryError();
            item->data = data;
            c->next = item;
            c = item;
        }
        this->tail = c;
    }
};

// (2.4)
template <typename T>
List<T>::List(T *arr, int n) {
    //std::cout << "(2.4)" << std::endl;
    if (arr == nullptr || n == 0) {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        ListItem<T> *head = new ListItem<T>;
        if (!head)
            throw MemoryError();
        this->head = head;
        this->head->data = arr[0];
        ListItem<T> *c = head;
        
        for (size_t i = 1; i < n; i++) {
            ListItem<T> *item = new ListItem<T>;
            if (!item)
                throw MemoryError();
            item->data = arr[i];
            c->next = item;
            c = item;
        }
        this->tail = c;
    }
};

template <typename T>
List<T>::List(const List<T> &list) {
    //std::cout << "(2.2)" << std::endl;
    if (list.head == nullptr) {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else {
        ListItem<T> *c;
        ListItem<T> *head = new ListItem<T>;
        if (!head)
            throw MemoryError();
        head->data = list.head->data;
        this->head = head;
        ListItem<T> *tmp = head;
        c = list.head->next;
        
        for (; c; c = c->next) {
            ListItem<T> *item = new ListItem<T>;
            if (!item)
                throw MemoryError();
            tmp->next = item;
            item->data = c->data;
            this->tail = item;
            tmp = tmp->next;
        }
    }
};


template <typename T>
List<T>::List(List<T> &&list) {
    //std::cout << "(2.3)" << std::endl;
    this->head = list.head;
    this->tail = list.tail;
    list.head = nullptr;
    list.tail = nullptr;
};

template <typename T>
List<T>::List(ListIterator<T> first, ListIterator<T> last) {
    //std::cout << "(2.6)" << std::endl;
    if (!first.range())  //  || !last.range()
        throw RangeError();
    
    ListIterator<T> ft(first);
    ListItem<T> *head = new ListItem<T>;
    if (!head)
        throw MemoryError();
    head->data = ft.Current();
    this->head = head;
    ft++;
    ListItem<T> *c = head;
    for (; ft != last; ft++) {
        ListItem<T> *item = new ListItem<T>;
        if (!item) {
            this->head = nullptr;                 /////////////////////////////////////////////////////////////////////////////////////////////
            this->tail = nullptr;                 ///////////////////////////////////////////////////////////////////////////////////////////// или = с
            throw MemoryError();
        }
        item->data = ft.Current();
        c->next = item;
        c = item;
    }
    this->tail = c;
};

////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
ListIterator<T> List<T>::begin() {
    //std::cout << "(2.7)" << std::endl;
    ListIterator<T> iter(*this);
    iter.first();
    
    return iter;
};

template <typename T>
ListIterator<T> List<T>::end() {
    //std::cout << "(2.8)" << std::endl;
    ListIterator<T> iter(*this);
    iter.last();
    
    return iter;
};

////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
List<T> &List<T>::Insert_after(ListIterator<T> iter, const T &value) {  // const
    //std::cout << "(3.2)";
    ListItem<T> *find = this->Find(*iter.current);
    ListItem<T> *item = new ListItem<T>;
    if (!item)
        throw MemoryError();
    //item->data = value;

    item->data = value;
    item->next = find->next;
    find->next = item;

    if (find->next == this->tail)
        this->tail = item;

    return (*this);
};

template <typename T>
void List<T>::Push_front(const T &data) {
    ListItem<T> *item = new ListItem<T>;
    if (!item)
        throw MemoryError();
    item->data = data;
    item->next = this->head;
    this->head = item;
};

template <typename T>
void List<T>::Push_back(const T &data) {
    ListItem<T> *item = new ListItem<T>;
    if (!item)
        throw MemoryError();
    item->data = data;
    this->tail->next = item;
    this->tail = item;
};

template <typename T>
void List<T>::Pop_front() {
    if (empty())
        throw EmptyError();
    ListItem<T> *tmp = this->head;
    this->head = this->head->next;
    delete tmp;
};

// попробовать полностью опустошить список
template <typename T>
void List<T>::Pop_back() {
    if (empty())
        throw EmptyError();
    if (size() == 1) {
        ListItem<T> *tmp = this->tail;
        this->head = nullptr;
        this->tail = nullptr;
        delete tmp;
        std::cout << "(STOP)";
    } else {
        ListItem<T> *tmp = this->tail;  // if tail == null ??? // как  tail может указывать на null если
        ListItem<T> *c = this->head;
        for (; c->next != tmp; c = c->next);
        this->tail = c;
        this->tail->next = nullptr;
        delete tmp;
    }
};

template <typename T>
void List<T>::Remove(const T &data) {
    if (empty())
        throw EmptyError();
    ListItem<T> *c = this->head;
    ListItem<T> *tmp;
    if (size() == 1) {
        ListItem<T> *tmp = this->tail;
        this->head = nullptr;
        this->tail = nullptr;
        delete tmp;
        //std::cout << "(STOP)";
    } else {
        while (c->next != this->tail) {
            if (c->next->data == data) {
                tmp = c->next;
                c->next = c->next->next;
                delete tmp;
            } else
                c = c->next;
        }
        if (this->head->data == data)
            Pop_front();
        else if (this->tail->data == data) {
            //std::cout << "(+)";
            tmp = this->tail;
            this->tail = c;
            this->tail->next = nullptr;
            delete tmp;
        }
    }
};

// size == 1 работает
template <typename T>
void List<T>::Reverse() {
    if (empty())
        throw EmptyError();
    if (size() != 1) {
        ListItem<T> *prev = this->head;
        ListItem<T> *c = prev->next;
        ListItem<T> *next;
        prev->next = nullptr;
        do {
            next = c->next;
            c->next = prev;
            prev = c;
            c = next;
        } while (c);
        this->head = prev;
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////
// 1 return
template <typename T>
ListItem<T> *List<T>::Delete(const ListItem<T> &elem) {
    //std::cout << "(2.11)";
    if (!this->head)
        throw EmptyError();
    ListItem<T> *find = this->Find(elem);
    ListItem<T> *c = this->head;
    if (c->data == elem.data) {
        this->head = this->head->next;
        //return c;
    } else {
        for (; c && c->next != find; c = c->next);
        if (c != nullptr) {
            // return nullptr;
            c->next = find->next;
            
            if (find == this->tail) {
                ListItem<T> *tmp = this->head;
                for (; tmp->next; tmp = tmp->next);
                this->tail = tmp;
            }
        }
    }
    c = find;
    return c;//find;
};

template <typename T>
ListItem<T> *List<T>::Find(const ListItem<T> &elem) const {
    //std::cout << "(3.4)";
    if (!this->head)
        throw EmptyError();
    ListItem<T> *c = this->head;
    while(c && c->data != elem.data)
        c = c->next;
    if (!c)
        throw FindError();
    return c;
};

////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
int List<T>::size() const {
    //std::cout << "(size)";
    ListItem<T> *c = this->head;
    int count = 0;
    for (; c; c = c->next)
        count++;
    return count;
};

template <typename T>
void List<T>::clear() {
    ListItem<T> *c = this->head;
    ListItem<T> *tmp = this->head;
    while(c)
    {
        tmp = c->next;
        delete c;
        c = tmp;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
bool List<T>::empty() const {
    return (this->head == nullptr);
};

////////////////////////////////////////////////////////////////////////////////////////////////

// копирование
// ??? this < list ???
template <typename T>
List<T> &List<T>::operator=(const List<T> &list) {
    //std::cout << "(2.9)";
    if (this->size() <= list.size()) {
        //std::cout << "(+)";
        ListItem<T> *clist = list.head;
        ListItem<T> *cthis = this->head;
        for (; cthis; cthis = cthis->next) {
            cthis->data = clist->data;
            clist = clist->next;
        }
        int count = list.size() - this->size();
        //std::cout << count << std::endl;
        while(count) {
            ListItem<T> *tmp = new ListItem<T>;
            if (!tmp)
                throw MemoryError();
            tmp->data = clist->data;
            this->tail->next = tmp;
            this->tail = tmp;
            cthis = tmp;
            cthis = cthis->next;
            clist = clist->next;
            count--;
        }
        
    } else {
        //std::cout << "(-)";
        ListItem<T> *clist = list.head;
        ListItem<T> *cthis = this->head;
        for (;cthis; cthis = cthis->next) {
            if (clist) {
                cthis->data = clist->data;
                this->tail = clist;
                clist = clist->next;
            } else
                this->Delete(*cthis);
        }
    }
    return (*this);
};
//item->data = value;
//item->next = find->next;
//find->next = item;
//
//if (find->next == this->tail)
//this->tail = item;

template <typename T>
List<T> &List<T>::operator=(List<T> &&list) {
    this->head = list.head;
    this->tail = list.tail;
    
    list.head = nullptr;
    list,tail = nullptr;
    return (*this);
}

template <typename T>
bool List<T>::operator==(const List<T> &list) const {
    ListItem<T> *cthis = this->head;
    ListItem<T> *clist = list.head;
    while(cthis && clist && cthis->data == clist->data) {
        cthis = cthis->next;
        clist = clist->next;
    }
//    if (cthis == nullptr && clist == nullptr)
//        return true;
//    else
//        return false;
    return (cthis == nullptr && clist == nullptr);
};

template <typename T>
bool List<T>::operator!=(const List<T> &list) const {
    return !(*this == list);
};

////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
std::ostream &operator << (std::ostream &st, List<T> &l) {
    st << "List: ";
    ListIterator<T> iter(l);
    if (!iter.range())
        st << "Пустой";
    else {
        for (iter.first(); iter.range(); iter++)
            st << iter.Current() << " ";
    }
    return st;
};





#endif /* list_h */
