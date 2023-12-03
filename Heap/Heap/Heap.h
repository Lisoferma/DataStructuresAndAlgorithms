// @author Lisoferma

#pragma once

#include <vector>
#include <stdexcept>

/// <summary>
/// Динамическая куча минимумов.
/// </summary>
/// <typeparam name="T">Тип данных который содержит куча.</typeparam>
template <typename T>
class Heap
{
public:
    /// <summary>
    /// Инициализировать пустую кучу.
    /// </summary>
    Heap()
    {
        // Заглушка для отсчёта элементов с индекса 1.
        _heapArray.push_back(T());
    }


    /// <summary>
    /// Инициализировать кучу вектором.
    /// </summary>
    /// <param name="vector">Вектор который содержит данные для кучи.</param>
    Heap(const std::vector<T>& vector) : Heap()
    {
        for (const T& item : vector)
            Insert(item);
    }


    /// <summary>
    /// Конструктор копирования.
    /// </summary>
    /// <param name="heap">Куча которую нужно скопировать в текущую.</param>
    Heap(const Heap& heap) : Heap()
    {
        heap.CopyToVector(_heapArray, 1);
    }


    /// <summary>
    /// Конструктор перемещения.
    /// </summary>
    /// <param name="heap">Куча которую нужно переместить в текущую.</param>
    Heap(Heap&& heap)
    {
        _heapArray = heap._heapArray;
        heap._heapArray = nullptr;
    }


    /// <summary>
    /// Вставить элемент в кучу.
    /// </summary>
    /// <param name="value">Элемент который нужно вставить.</param>
    void Insert(const T& value)
    {
        _heapArray.push_back(value);
        HeapifyUp(_heapArray.size() - 1);
    }


    /// <summary>
    /// Удалить заданный элемент из кучи.
    /// </summary>
    /// <param name="value">Элемент который нужно удалить.</param>
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
            // Если удаляем последний элемент
            // восстановление свойств кучи не нужно.
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
    /// Получить минимальный элемент.
    /// </summary>
    /// <returns>Минимальный элемент.</returns>
    const T& Top() const
    {
        if (IsEmpty())
        {
            throw std::out_of_range("Heap is empty.");
        }

        return _heapArray[1];;
    }


    /// <summary>
    /// Удалить минимальный элемент.
    /// </summary>
    /// <returns>Минимальный элемент.</returns>
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
    /// Скопировать кучу в вектор.
    /// </summary>
    /// <param name="copyVector">Вектор который будет принимать данные кучи.</param>
    /// <param name="index">Индекс с которого записывать копируемые данные в заданный вектор.</param>
    void CopyToVector(std::vector<T>& copyVector, size_t index) const
    {
        copyVector.insert(copyVector.begin() + index,
            _heapArray.begin() + 1,
            _heapArray.end());
    }


    /// <summary>
    /// Пустая ли куча.
    /// </summary>
    bool IsEmpty() const
    {
        return _heapArray.size() == 1;
    }


private:
    /// <summary>
    /// Хранит элементы кучи.
    /// </summary>
    std::vector<T> _heapArray;


    /// <summary>
    /// Восстановить свойства кучи поднимаясь вверх по дереву.
    /// </summary>
    /// <param name="index">Индекс с которого начать восстановление.</param>
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
    /// Восстановить свойства кучи спускаясь вниз по поддереву.
    /// </summary>
    /// <param name="index">Индекс с которого начать восстановление.</param>
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
    /// Проверить выходит ли индекс за пределы кучи. 
    /// </summary>
    /// <param name="index">Индекс элемента кучи который нужно проверить.</param>
    bool IsOutOfRange(size_t index) const
    {
        return index >= _heapArray.size() || index < 1;
    }
};