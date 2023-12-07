// @author Lisoferma

#pragma once

#include <vector>

/// <summary>
/// Преобразовать в двоичную кучу вектор содержащий поддерево с указанным корневым узлом.
/// </summary>
/// <typeparam name="T">Тип данных который содержит вектор.</typeparam>
/// <param name="vector">Вектор в котором произовадится сортировка поддерева.</param>
/// <param name="index">Индекс корневого узла поддерева с которого начать сортировку.</param>
/// <param name="size">Размер поддерева для сортировки.</param>
template <typename T>
void Heapify(std::vector<T>& vector, size_t index, size_t size)
{
    size_t largest;
    size_t l = 2 * index;
    size_t r = (2 * index) + 1;

    // Если левый дочерний элемент больше корня
    if (l <= size && vector[l - 1] > vector[index - 1])
        largest = l;
    else
        largest = index;
    
    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r <= size && vector[r - 1] > vector[largest - 1])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != index)
    {
        std::swap(vector[index - 1], vector[largest - 1]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        Heapify(vector, largest, size);
    }
}


/// <summary>
/// Пирамидальная сортировка для вектора.
/// </summary>
/// <typeparam name="T">Тип данных который содержит вектор.</typeparam>
/// <param name="vector">Вектор который нужно отсортировать.</param>
template <typename T>
void HeapSort(std::vector<T>& vector)
{
    size_t size = vector.size() - 1;

    // Построение кучи
    for (size_t i = size / 2; i >= 1; i--)
        Heapify(vector, i, size);

    // Один за другим извлекаем элементы из кучи
    for (size_t i = size; i >= 1; i--)
    {
        // Перемещаем текущий корень в конец
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
//    // Заполнение листьев
//    for (size_t i = 0; i < size; ++i)
//    {
//        tree[size - 1 + i] = vector[i];
//    }
//
//    // Создание дерева
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
//    // Сортировка
//    for (size_t i = 0; i < size; ++i)
//    {
//        size_t j = size + i - 1;
//
//        while (j >= 0 && tree[j] != INT_MAX)
//        {
//            // INT_MAX - метка что лист удалён
//            tree[j] = INT_MAX;
//            j = (j - 1) / 2;
//        }
//
//        result[i] = tree[j + 1 - size];
//    }
//
//    vector = result;
//}