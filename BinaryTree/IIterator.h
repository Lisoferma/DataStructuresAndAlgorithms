//@author Lisoferma

#pragma once

namespace DSAABinaryTree
{
    /// <summary>
    /// ������������� ������ ��� �������������� � ����������.
    /// </summary>
    /// <typeparam name="T">��� ������ ����������� ���������.</typeparam>
    template <typename T>
    class IIterator
    {
    public:
        virtual bool operator ==(const IIterator<T>& iter) const = 0;

        virtual bool operator !=(const IIterator<T>& iter) const  = 0;

        /// <summary>
        /// �������� ������ �� ��������� �� �������� ��������� ���������.
        /// </summary>
        virtual T& operator *() const = 0;

        /// <summary>
        /// ������� � ���������� �������� ���������.
        /// </summary>
        /// <returns>�������� ����� �������� � ���������� ��������.</returns>
        virtual IIterator<T>& operator ++() = 0;

        /// <summary>
        /// ������� � ���������� �������� ���������.
        /// </summary>
        /// <returns>�������� ����� ��������� � ���������� ��������.</returns>
        virtual IIterator<T>& operator ++(int) = 0;

        /// <summary>
        /// �������� ����� �� ����� ���������.
        /// </summary>
        virtual bool IsEnd() const = 0;
    };
}