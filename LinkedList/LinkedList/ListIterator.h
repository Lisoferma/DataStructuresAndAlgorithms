// @author Lisoferma

#pragma once

#include "IIterator.h"
#include "Node.h"
#include <iterator>

namespace DSAList
{
    /// <summary>
    /// �������� ��� ������������ ������ <see cref="List"/>.
    /// </summary>
    /// <typeparam name="T">��� ������ ����������� ���������.</typeparam>
    template<typename T>
    class ListIterator : public IIterator<T>
    {
    public:
        // �������� ��������� ��� STL
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = T;
        using pointer = T*;
        using reference = T&;


        /// <summary>
        /// ���������������� �������� ��� ������.
        /// </summary>
        /// <param name="node">���� �� ������� ��������� ��������.</param>
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
        /// �������� ������ �� ��������� �� �������� ��������� ���������.
        /// </summary>
        T& operator *() const override
        {
            return _current->Data;
        }


        /// <summary>
        /// ������� � ���������� �������� ���������.
        /// </summary>
        /// <returns>�������� ����� �������� � ���������� ��������.</returns>
        ListIterator<T>& operator++() override
        {
            Next();
            return *this;
        }


        /// <summary>
        /// ������� � ���������� �������� ���������.
        /// </summary>
        /// <returns>�������� ����� ��������� � ���������� ��������.</returns>
        ListIterator<T>& operator++(int) override
        {
            ListIterator<T> temp(_current);
            Next();
            return temp;
        }


        /// <summary>
        /// �������� ����� �� ����� ���������.
        /// </summary>
        bool IsEnd() const override
        {
            return _current == nullptr;
        }


    private:
        /// <summary>
        /// ��������� �� ������� ����
        /// </summary>
        Node<T>* _current;


        /// <summary>
        /// ��������� ��� �� ��������� ����� �� ����� ���������.
        /// </summary>
        bool BothIsEnd(const IIterator<T>& iter1, const IIterator<T>& iter2) const
        {
            return iter1.IsEnd() && iter2.IsEnd();
        }


        /// <summary>
        /// ���������� ��������� ��������� �� ��������� ������� � ������.
        /// </summary>
        void Next()
        {
            _current = _current->Next;
        }
    };
}