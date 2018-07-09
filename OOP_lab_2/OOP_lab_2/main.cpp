//
//  main.cpp
//  OOP_lab_2
//
//  Created by Виктория on 11.04.2018.
//

#include <iostream>
#include <stdlib.h>
#include "list.h"
#include "list_item.h"
#include "list_iterator.h"
#include "errors.h"

using namespace std;

int main(int argc, const char * argv[]) {
    try {
        cout << "Тестирование конструкторов\n";
        cout << "--------------------------\n";
    
        cout << "пустой список" << endl;
        List<int> test1;
        cout << "\n1) " <<test1 << endl;
    
        cout << "\nс параметрами" << endl;
    
        List<double> test2((size_t) 16);
        cout << "\n2) " << test2 << endl;
        
        cout << "\n\n";
        cout << "(значение, количество)" << endl;
        List<int> test3(16, 3);
        cout << "\n3) " << test3 << endl;
        
        cout << "массив [6]" << endl;
        float mass[6] = {0, 1.4, 2.2, 1, 2.2, 3};
        List<float> test4(mass, 6);
        cout << "\n\n4) " << test4 << endl;
        
        List<float> test40(mass, 2);
        
        cout << "массив [5]" << endl;
        List<float> test5(mass, 5);
        cout << "\n\n5) " << test5 << endl;
        
        cout << endl << endl << "КОПИРОВАНИЕ" << endl << "-----------" << endl << endl;
        List<float> test6(test5);
        cout << "\n6) " << test6 << endl;
        
        
        //cout << test4 << " = " << test5 << endl;
        test4 = test5;  // {0, 1.4, 1, 2.2, 3, 5} = {0, 1.4, 1, 2.2}
        cout << "\n\n7) " << test4 << endl;
        
        cout << endl << endl << "ДИАПАЗОН" << endl << "-----------" << endl << endl;
        List<int> test8(test3.begin(), test3.end());
        cout << "\n8) " << test8 << endl;
        
        
    
        cout << endl << endl << "INSERT_AFTER" << endl << "-----------" << endl << endl;
        cout << "В test5 вставим 55 после 2го" << endl << endl;
        ListIterator<float> iter(test5);
        iter++;
        //iter++;
        //iter++;
        float c = 16.6;
        cout << test5 << endl << endl;
        test5.Insert_after(iter, c);
        cout << test5 << endl << endl;
        
        cout << endl << endl << "PUSH_FRONT" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Добавим эл-т 16.6" << endl;
        test5.Push_front(16.6);
        cout << test5 << endl << endl;
        
        cout << endl << endl << "PUSH_BACK" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Добавим эл-т 2.2" << endl;
        test5.Push_back(2.2);
        cout << test5 << endl << endl;
        
        cout << endl << endl << "POP_FRONT" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Удалим эл-т" << endl;
        test5.Pop_front();
        //test5.Pop_front();
        //test5.Pop_front();
        //test5.Pop_front();
        //test5.Pop_front();
        //test5.Pop_front();
        //test5.Pop_front();
        //test5.Pop_front();
        cout << test5 << endl << endl;
        
        cout << endl << endl << "POP_BACK" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Удалим эл-т" << endl;
        test5.Pop_back();
        //test5.Pop_back();
        test5.Pop_back();
        test5.Pop_back();
        test5.Pop_back();
        test5.Pop_back();
        test5.Pop_back();
        cout << test5 << endl << endl;
        
        test5.Push_front(2.2);
        cout << endl << endl << "REMOVE" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Удалим эл-т 2.2" << endl;
        test5.Remove(2.2);
        //test5.Remove(1.4);
        //test5.Remove(0);
        cout << test5 << endl << endl;
        
        cout << endl << endl << "REVERSE" << endl << "-----------" << endl << endl;
        cout << test5 << endl << endl;
        cout << "Развернем список" << endl;
        test5.Reverse();
        cout << test5 << endl << endl;
        
        //test5.clear();
        
//        cout << endl << endl << "ITERATOR" << endl << "-----------" << endl << endl;
//        ListIterator<float> iter1(test5);
//        for (iter1.first(); iter1.range(); iter1++)
//            cout << "iter ";
//
//        ListIterator<float> iter2(test5);
//        for (auto iter3 = iter2.first(); iter3 != iter2.last(); iter3++)
//        {
//            cout << "+ ";
//        }
        
        cout << endl << endl;
        
    }
    catch(Error &err) {
        cout << "\n\n" << err.what() << endl;
    }
    return 0;
}
