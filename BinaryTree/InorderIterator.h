//@author Lisoferma

#pragma once

#include "IIterator.h"
#include "BinaryNode.h"
#include <stack>

namespace DSAABinaryTree
{
    /// <summary>
    /// Итератор для упорядоченого (в порядке LNR) прохода по дереву.
    /// </summary>
    /// <typeparam name="T">Тип данных итерируемой коллекции.</typeparam>
    template<typename T>
    class InorderIterator : public IIterator<T>
    {
    public:
        // Свойства итератора для STL
        using iterator_category = std::forward_iterator_tag;
        using value_type        = T;
        using difference_type   = T;
        using pointer           = T*;
        using reference         = T&;


        /// <summary>
        /// Инициализировать итератор для дерева.
        /// </summary>
        /// <param name="node">Узел на который указывает итератор.</param>
        /// <param name="setToStart">Установить на начальное (begin) положение итератора.</param>
        InorderIterator(BinaryNode<T>* node, bool setToStart = true) : _current(node)
        {
            if (setToStart)
                MoveLeft(_current);
        }


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
        InorderIterator<T>& operator++() override
        {
            Next();
            return *this;
        }


        /// <summary>
        /// Перейти к следующему элементу коллекции.
        /// </summary>
        /// <returns>Итератор перед переходом к следующему элементу.</returns>
        InorderIterator<T>& operator++(int) override
        {
            InorderIterator<T> temp(_current, false);
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
        // Указатель на текущий узел
        BinaryNode<T>* _current;

        // Стэк для хранения и извлечения узлов в упорядоченном (inorder) проходе
        std::stack< BinaryNode<T>* > _traversal;


        /// <summary>
        /// Проверить оба ли итератора дошли до конца коллекции.
        /// </summary>
        bool BothIsEnd(const IIterator<T>& iter1, const IIterator<T>& iter2) const
        {
            return iter1.IsEnd() && iter2.IsEnd();
        }


        /// <summary>
        /// Установить указател итератора на крайний левый узел от указанного.
        /// </summary>
        /// <param name="node">Узел от которого идти влево.</param>
        void MoveLeft(BinaryNode<T>* node)
        {
            while (node)
            {
                _traversal.push(node);
                node = node->Left;
            }

            _current = _traversal.top();
        }


        /// <summary>
        /// Есть следующие элементы в коллекции.
        /// </summary>
        bool HasNext() const
        {
            return !_traversal.empty();
        }


        /// <summary>
        /// Установить указатель итератора на следующий элемент в дереве.
        /// </summary>
        void Next()
        {
            if (!HasNext())
            {
                _current = nullptr;
                return;
            }
                
            BinaryNode<T>* top = _traversal.top();
            _traversal.pop();

            if (top->Right)
                MoveLeft(top->Right);

            _current = top;
        }
    };
}