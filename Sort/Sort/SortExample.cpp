// @author Lisoferma

#include <iostream>
#include "Sort.h"

using namespace std;


int main()
{
    vector<int> v1{ 12, 11, 13, 5, 6, 7, 20, -5, -6, 0 };

    HeapSort(v1);

    cout << "Vector after heap sort: ";
    for (int item : v1)
        cout << item << " ";

    vector<int> v2{ 12, 11, 13, 5, 6, 7, 20, -5, -6, 0 };

    TournamentSort(v2);

    cout << "\nVector after tournament sort: ";
    for (int item : v2)
        cout << item << " ";
}