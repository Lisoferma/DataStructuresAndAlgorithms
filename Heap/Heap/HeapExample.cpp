// @author Lisoferma

#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    // Создать кучу целых чисел
    Heap<int> integerHeap;

    // Вставка элементов
    integerHeap.Insert(10);
    integerHeap.Insert(5);
    integerHeap.Insert(7);
    integerHeap.Insert(15);
    integerHeap.Insert(4);
    integerHeap.Insert(200);
    integerHeap.Insert(1);

    // Инициализация кучи вектором
    //vector<int> integerVector{ 10, 5, 7, 15, 4, 200, 1 };
    //Heap<int> heapFromVector(integerVector);

    // Удаление элементов
    integerHeap.Remove(7);
    integerHeap.Remove(1);

    // Получить вектор из кучи
    vector<int> heapVector;
    integerHeap.CopyToVector(heapVector, 0);

    cout << "Heap: ";
    for (int item : heapVector)
        cout << item << " ";

    // Получить минимальный элемент
    cout << "\nTop element: " << integerHeap.Top() << endl;

    // Удалить минимальный элемент
    integerHeap.Pop();

    // Получить минимальный элемент после извлечения предыдущего
    cout << "Top element after Pop(): " << integerHeap.Top() << endl;

    // Проверка на пустую кучу
    if (integerHeap.IsEmpty())
    {
        cout << "Heap is empty" << endl;
    }
    else
    {
        cout << "Heap is not empty" << endl;
    }

    return 0;
}