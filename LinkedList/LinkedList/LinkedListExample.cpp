// @author Lisoferma

#include "List.h"
#include <iostream>

using namespace std;
using namespace DSAList;


template <typename T>
void PrintList(List<T>& list)
{
    for (auto item : list)
        cout << item << " ";
}


int main()
{
    vector<int> initData{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    List<int> list(initData);

    cout << "List: ";
    PrintList(list);

    list.Remove(1);
    list.Remove(2);
    list.Remove(6);
    list.Remove(10);

    cout << "\nList after remove: ";
    PrintList(list);
    
    cout << "\n4 is in the list: ";

    list.IsInList(4) 
        ? cout << "true"
        : cout << "false";

    cout << "\n1 is in the list: ";

    list.IsInList(1)
        ? cout << "true"
        : cout << "false";
}