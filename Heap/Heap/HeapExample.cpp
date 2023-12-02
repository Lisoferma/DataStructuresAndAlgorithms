// @author Lisoferma

#include <iostream>
#include "Heap.h"

using namespace std;

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

    // ������������� ���� ��������
    //vector<int> integerVector{ 10, 5, 7, 15, 4, 200, 1 };
    //Heap<int> heapFromVector(integerVector);

    // �������� ���������
    integerHeap.Remove(7);
    integerHeap.Remove(1);

    // �������� ������ �� ����
    vector<int> heapVector;
    integerHeap.CopyToVector(heapVector);

    cout << "Heap: ";
    for (int item : heapVector)
        cout << item << " ";

    // �������� ����������� �������
    cout << "\nTop element: " << integerHeap.Top() << endl;

    // ������� ����������� �������
    integerHeap.Pop();

    // �������� ����������� ������� ����� ���������� �����������
    cout << "Top element after Pop(): " << integerHeap.Top() << endl;

    // �������� �� ������ ����
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