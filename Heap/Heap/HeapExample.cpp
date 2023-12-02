#include <iostream>
#include "Heap.h"

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

    // Удаление элементов
    integerHeap.Remove(7);
    integerHeap.Remove(1);

    // Получить минимальный элемент
    std::cout << "Top element: " << integerHeap.Top() << std::endl;

    // Удалить минимальный элемент
    integerHeap.Pop();

    // Получить минимальный элемент после извлечения предыдущего
    std::cout << "Top element after Pop(): " << integerHeap.Top() << std::endl;

    // Проверка на пустую кучу
    if (integerHeap.IsEmpty())
    {
        std::cout << "Heap is empty" << std::endl;
    }
    else
    {
        std::cout << "Heap is not empty" << std::endl;
    }

    return 0;
}