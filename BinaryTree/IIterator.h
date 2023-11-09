#pragma once

namespace DSAABinaryTree
{
    template <typename T>
    class IIterator
    {
    public:
        virtual bool operator ==(const IIterator<T>& iter) const = 0;

        virtual bool operator !=(const IIterator<T>& iter) const  = 0;

        virtual T& operator *() const = 0;

        virtual IIterator<T>& operator ++() = 0;

        virtual IIterator<T>& operator ++(int) = 0;

        virtual bool IsEnd() const = 0;
    };
}