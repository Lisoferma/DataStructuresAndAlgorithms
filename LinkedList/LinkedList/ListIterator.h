// @author Lisoferma

#pragma once

#include "IIterator.h"
#include "Node.h"
#include <iterator>

namespace DSAList
{
    /// <summary>
    /// Итератор для односвязного списка <see cref="List"/>.
    /// </summary>
    /// <typeparam name="T">Тип данных итерируемой коллекции.</typeparam>
    template<typename T>
    class ListIterator : public IIterator<T>
    {
    public:
        // Свойства итератора для STL
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = T;
        using pointer = T*;
        using reference = T&;


        /// <summary>
        /// Инициализировать итератор для списка.
        /// </summary>
        /// <param name="node">Узел на который указывает итератор.</param>
        ListIterator(Node<T>* node) : _current(node)
        { }


        bool operator ==(const IIterator<T>& iter) const override
        {
            if (BothIsEnd(*this, iter))
                return true;

            return _current->Data == *iter;
        }


        bool operator !=(const IIterator<T>& iter) const override
        {
            if (BothIsEnd(*this, iter))
                return false;
            else
                return true;

            return _current->Data != *iter;
        }


        /// <summary>
        /// Получить данные из коллекции по текущему указателю итератора.
        /// </summary>
        T& operator *() const override
        {
            return _current->Data;
        }


        /// <summary>
        /// Перейти к следующему элементу коллекции.
        /// </summary>
        /// <returns>Итератор после перехода к следующему элементу.</returns>
        ListIterator<T>& operator++() override
        {
            Next();
            return *this;
        }


        /// <summary>
        /// Перейти к следующему элементу коллекции.
        /// </summary>
        /// <returns>Итератор перед переходом к следующему элементу.</returns>
        ListIterator<T>& operator++(int) override
        {
            ListIterator<T> temp(_current);
            Next();
            return temp;
        }


        /// <summary>
        /// Итератор дошёл до конца коллекции.
        /// </summary>
        bool IsEnd() const override
        {
            return _current == nullptr;
        }


    private:
        /// <summary>
        /// Указатель на текущий узел
        /// </summary>
        Node<T>* _current;


        /// <summary>
        /// Проверить оба ли итератора дошли до конца коллекции.
        /// </summary>
        bool BothIsEnd(const IIterator<T>& iter1, const IIterator<T>& iter2) const
        {
            return iter1.IsEnd() && iter2.IsEnd();
        }


        /// <summary>
        /// Установить указатель итератора на следующий элемент в дереве.
        /// </summary>
        void Next()
        {
            _current = _current->Next;
        }
    };
}