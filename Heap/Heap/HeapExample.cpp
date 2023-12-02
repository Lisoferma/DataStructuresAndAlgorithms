#include <iostream>
#include "Heap.h"

int main()
{
    // ������� ���� ����� �����
    Heap<int> integerHeap;

    // ������� ���������
    integerHeap.Insert(10);
    integerHeap.Insert(5);
    integerHeap.Insert(7);
    integerHeap.Insert(15);
    integerHeap.Insert(4);
    integerHeap.Insert(200);
    integerHeap.Insert(1);

    // �������� ���������
    integerHeap.Remove(7);
    integerHeap.Remove(1);

    // �������� ����������� �������
    std::cout << "Top element: " << integerHeap.Top() << std::endl;

    // ������� ����������� �������
    integerHeap.Pop();

    // �������� ����������� ������� ����� ���������� �����������
    std::cout << "Top element after Pop(): " << integerHeap.Top() << std::endl;

    // �������� �� ������ ����
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