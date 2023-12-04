// @author Lisoferma

#include <iostream>
#include <algorithm>
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
    
    // Инициализация с помощью котнструктора перемещения и вектора
    // Heap<int> heap(Heap<int>(vector<int>{5, 2, 3, 1, 10}));

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
    integerHeap.IsEmpty()
        ? cout << "Heap is empty" << endl
        : cout << "Heap is not empty" << endl;


    // Куча в STL
    vector<int> v1 = { 10, 5, 7, 15, 4, 200, 1 };

    // Конвертировать контейнер в кучу на выбранном отрезке
    make_heap(v1.begin(), v1.end());

    cout << "\nHeap STL: ";
    for (int item : v1)
        cout << item << " ";

    // Проверка на кучу
    is_heap(v1.begin(), v1.end())
        ? cout << "\nThe container is max-heap "
        : cout << "\nThe container is not max-heap";

    // push_heap используется только после добавления элемента в конец
    v1.push_back(50);
    push_heap(v1.begin(), v1.end());

    cout << "\nHeap after push_heap(): ";
    for (int item : v1)
        cout << item << " ";

    // Перемещает наибольший элемент в конец
    pop_heap(v1.begin(), v1.end());

    // Теперь можно удалить наибольший элемент
    v1.pop_back();

    cout << "\nHeap after pop_heap(): ";
    for (int item : v1)
        cout << item << " ";

    return 0;
}