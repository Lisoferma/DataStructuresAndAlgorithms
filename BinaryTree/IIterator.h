//@author Lisoferma

#pragma once

namespace DSAABinaryTree
{
    /// <summary>
    /// Предоставляет методы для взаимодействия с итератором.
    /// </summary>
    /// <typeparam name="T">Тип данных итерируемой коллекции.</typeparam>
    template <typename T>
    class IIterator
    {
    public:
        virtual bool operator ==(const IIterator<T>& iter) const = 0;

        virtual bool operator !=(const IIterator<T>& iter) const  = 0;

        /// <summary>
        /// Получить данные из коллекции по текущему указателю итератора.
        /// </summary>
        virtual T& operator *() const = 0;

        /// <summary>
        /// Перейти к следующему элементу коллекции.
        /// </summary>
        /// <returns>Итератор после перехода к следующему элементу.</returns>
        virtual IIterator<T>& operator ++() = 0;

        /// <summary>
        /// Перейти к следующему элементу коллекции.
        /// </summary>
        /// <returns>Итератор перед переходом к следующему элементу.</returns>
        virtual IIterator<T>& operator ++(int) = 0;

        /// <summary>
        /// Итератор дошёл до конца коллекции.
        /// </summary>
        virtual bool IsEnd() const = 0;
    };
}