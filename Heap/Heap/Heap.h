// @author Lisoferma

#pragma once

#include <vector>
#include <stdexcept>

/// <summary>
/// ������������ ���� ���������.
/// </summary>
/// <typeparam name="T">��� ������ ������� �������� ����.</typeparam>
template <typename T>
class Heap
{
public:
    /// <summary>
    /// ���������������� ������ ����.
    /// </summary>
    Heap()
    {
        // �������� ��� ������� ��������� � ������� 1.
        _heapArray.push_back(T());
    }


    /// <summary>
    /// ���������������� ���� ��������.
    /// </summary>
    /// <param name="vector">������ ������� �������� ������ ��� ����.</param>
    Heap(const std::vector<T>& vector) : Heap()
    {
        for (const T& item : vector)
            Insert(item);
    }


    /// <summary>
    /// �������� ������� � ����.
    /// </summary>
    /// <param name="value">������� ������� ����� ��������.</param>
    void Insert(const T& value)
    {
        _heapArray.push_back(value);
        HeapifyUp(_heapArray.size() - 1);
    }


    /// <summary>
    /// ������� �������� ������� �� ����.
    /// </summary>
    /// <param name="value">������� ������� ����� �������.</param>
    void Remove(const T& value)
    {
        auto it = std::find(_heapArray.begin() + 1, _heapArray.end(), value);

        if (it == _heapArray.end())
        {
            throw std::out_of_range("Element not found in the heap.");
        }

        size_t index = std::distance(_heapArray.begin(), it);

        _heapArray[index] = _heapArray.back();
        _heapArray.pop_back();

        if (index == _heapArray.size())
        {
            // ���� ������� ��������� �������
            // �������������� ������� ���� �� �����.
            return;
        }
        else if (index > 1 && _heapArray[index] < _heapArray[index / 2])
        {
            HeapifyUp(index);
        }
        else
        {
            HeapifyDown(index);
        }
    }


    /// <summary>
    /// ������� ����������� �������.
    /// </summary>
    /// <returns>����������� �������.</returns>
    void Pop()
    {
        if (IsEmpty())
        {
            throw std::out_of_range("Heap is empty.");
        }

        _heapArray[1] = _heapArray.back();
        _heapArray.pop_back();
        HeapifyDown(1);
    }


    /// <summary>
    /// �������� ����������� �������.
    /// </summary>
    /// <returns>����������� �������.</returns>
    const T& Top()
    {
        if (IsEmpty())
        {
            throw std::out_of_range("Heap is empty.");
        }

        return _heapArray[1];;
    }


    /// <summary>
    /// ����������� ���� � ������.
    /// </summary>
    /// <param name="copyVector">������ ������� ����� ��������� ������ ����.</param>
    void CopyToVector(std::vector<T>& copyVector)
    {
        copyVector.insert(copyVector.begin(), _heapArray.begin() + 1, _heapArray.end());
    }


    /// <summary>
    /// ������ �� ����.
    /// </summary>
    bool IsEmpty()
    {
        return _heapArray.size() == 1;
    }


private:
    /// <summary>
    /// ������ �������� ����.
    /// </summary>
    std::vector<T> _heapArray;


    /// <summary>
    /// ������������ �������� ���� ���������� ����� �� ������.
    /// </summary>
    /// <param name="index">������ � �������� ������ ��������������.</param>
    void HeapifyUp(size_t index)
    {
        if (IsOutOfRange(index))
        {
            throw std::out_of_range("Index outside the range of the heap.");
        }

        size_t parentIndex = index / 2;

        while (index > 1 && _heapArray[index] < _heapArray[parentIndex])
        {
            std::swap(_heapArray[index], _heapArray[parentIndex]);
            index = parentIndex;
            parentIndex = index / 2;
        }
    }


    /// <summary>
    /// ������������ �������� ���� ��������� ���� �� ���������.
    /// </summary>
    /// <param name="index">������ � �������� ������ ��������������.</param>
    void HeapifyDown(size_t index)
    {
        if (IsOutOfRange(index))
        {
            throw std::out_of_range("Index outside the range of the heap.");
        }

        size_t leftChildIndex = 2 * index;
        size_t rightChildIndex = 2 * index + 1;
        size_t smallestIndex = index;

        if (leftChildIndex < _heapArray.size() && _heapArray[leftChildIndex] < _heapArray[smallestIndex])
        {
            smallestIndex = leftChildIndex;
        }

        if (rightChildIndex < _heapArray.size() && _heapArray[rightChildIndex] < _heapArray[smallestIndex])
        {
            smallestIndex = rightChildIndex;
        }

        if (smallestIndex != index)
        {
            std::swap(_heapArray[index], _heapArray[smallestIndex]);
            HeapifyDown(smallestIndex);
        }
    }


    /// <summary>
    /// ��������� ������� �� ������ �� ������� ����. 
    /// </summary>
    /// <param name="index">������ �������� ���� ������� ����� ���������.</param>
    bool IsOutOfRange(size_t index)
    {
        return index >= _heapArray.size() || index < 1;
    }
};