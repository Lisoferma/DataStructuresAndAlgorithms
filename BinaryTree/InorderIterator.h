#pragma once

#include "IIterator.h"
#include "BinaryNode.h"
#include <stack>

namespace DSAABinaryTree
{
    template<typename T>
    class InorderIterator : public IIterator<T>
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = T;
        using difference_type   = T;
        using pointer           = T*;
        using reference         = T&;


        InorderIterator(BinaryNode<T>* node, bool setToStart = true) : _current(node)
        {
            if (setToStart)
                MoveLeft(_current);
        }


        bool operator ==(const IIterator<T>& iter) const override
        {
            if (IsEnd() && iter.IsEnd())
                return true;
                
            return _current->Data == *iter;
        }


        bool operator !=(const IIterator<T>& iter) const override
        {
            if (IsEnd() && iter.IsEnd())
                return true;

            return _current->Data != *iter;
        }


        T& operator *() const override
        {
            return _current->Data;
        }


        InorderIterator<T>& operator++() override
        {
            Next();
            return *this;
        }


        InorderIterator<T>& operator++(int) override
        {
            InorderIterator<T> temp(_current, false);
            Next();
            return temp;
        }


        bool IsEnd() const override
        {
            return _current == nullptr;
        }


    private:
        // Указатель на текущий узел
        BinaryNode<T>* _current;

        // Стэк для хранения и извлечения узлов в упорядоченном (inorder) проходе
        std::stack< BinaryNode<T>* > _traversal;


        void MoveLeft(BinaryNode<T>* node)
        {
            while (node)
            {
                _traversal.push(node);
                node = node->Left;
            }

            _current = _traversal.top();
        }


        bool HasNext()
        {
            return !_traversal.empty();
        }


        void Next()
        {
            if (!HasNext())
                _current = nullptr;

            BinaryNode<T>* top = _traversal.top();
            _traversal.pop();

            if (top->Right)
                MoveLeft(top->Right);

            _current = top;
        }
    };
}