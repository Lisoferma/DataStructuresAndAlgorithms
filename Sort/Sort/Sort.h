// @author Lisoferma

#pragma once

#include <vector>

/// <summary>
/// ������������� � �������� ���� ������ ���������� ��������� � ��������� �������� �����.
/// </summary>
/// <typeparam name="T">��� ������ ������� �������� ������.</typeparam>
/// <param name="vector">������ � ������� ������������� ���������� ���������.</param>
/// <param name="index">������ ��������� ���� ��������� � �������� ������ ����������.</param>
/// <param name="size">������ ��������� ��� ����������.</param>
template <typename T>
void Heapify(std::vector<T>& vector, size_t index, size_t size)
{
    size_t largest;
    size_t l = 2 * index;
    size_t r = (2 * index) + 1;

    // ���� ����� �������� ������� ������ �����
    if (l <= size && vector[l - 1] > vector[index - 1])
        largest = l;
    else
        largest = index;
    
    // ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
    if (r <= size && vector[r - 1] > vector[largest - 1])
        largest = r;

    // ���� ����� ������� ������� �� ������
    if (largest != index)
    {
        std::swap(vector[index - 1], vector[largest - 1]);

        // ���������� ����������� � �������� ���� ���������� ���������
        Heapify(vector, largest, size);
    }
}


/// <summary>
/// ������������� ���������� ��� �������.
/// </summary>
/// <typeparam name="T">��� ������ ������� �������� ������.</typeparam>
/// <param name="vector">������ ������� ����� �������������.</param>
template <typename T>
void HeapSort(std::vector<T>& vector)
{
    size_t size = vector.size() - 1;

    // ���������� ����
    for (size_t i = size / 2; i >= 1; i--)
        Heapify(vector, i, size);

    // ���� �� ������ ��������� �������� �� ����
    for (size_t i = size; i >= 1; i--)
    {
        // ���������� ������� ������ � �����
        std::swap(vector[0], vector[i]);
        Heapify(vector, 1, i);
    }
}


//template <typename T>
//void TournamentSort(std::vector<T>& vector)
//{
//    size_t size = vector.size();
//
//    std::vector<T> tree(2 * size - 1);
//
//    // ���������� �������
//    for (size_t i = 0; i < size; ++i)
//    {
//        tree[size - 1 + i] = vector[i];
//    }
//
//    // �������� ������
//    for (size_t i = size - 2; i >= 0; --i)
//    {
//        size_t left = 2 * i + 1;
//        size_t right = 2 * i + 2;
//
//        tree[i] = std::min(tree[left], tree[right]);
//    }
//
//    std::vector<T> result(size);
//
//    // ����������
//    for (size_t i = 0; i < size; ++i)
//    {
//        size_t j = size + i - 1;
//
//        while (j >= 0 && tree[j] != INT_MAX)
//        {
//            // INT_MAX - ����� ��� ���� �����
//            tree[j] = INT_MAX;
//            j = (j - 1) / 2;
//        }
//
//        result[i] = tree[j + 1 - size];
//    }
//
//    vector = result;
//}