//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include "BinaryTreeService.h"
#include <vector>

namespace DSAABinaryTree
{
	template<typename T>
	class BinarySearchTree
	{
	public:
        BinarySearchTree() : root(nullptr)
        { }


        /// <summary>
        /// Инициализировать корень дерева.
        /// </summary>
        /// <param name="root">Корень дерева.</param>
        BinarySearchTree(BinaryNode<T>* root) : root(root)
        { }


        /// <summary>
        /// Инициализировать дерево вектором.
        /// </summary>
        /// <param name="dataVector">Вектор который хранит данные для узлов.</param>
        BinarySearchTree(const std::vector<T>& dataVector)
        {
            for (T data : dataVector)
                Insert(data);
        }
        

        /// <summary>
        /// Поиск узла по ключу.
        /// </summary>
        /// <param name="keyData">Ключ по которому производится поиск.</param>
        /// <returns>Указатель на найденный узел. Если не найден - nullptr.</returns>
        BinaryNode<T>* Search(const T& keyData)
        {
            BinaryNode<T>* current = root;

            while (current != nullptr)
                if (current->Data == keyData)
                    return current;
                else
                    current = keyData < current->Data ?
                    current->Left : current->Right;

            return nullptr;
        }


        /// <summary>
        /// Вставить данные в дерево.
        /// </summary>
        /// <param name="data">Данные для нового узла.</param>
        void Insert(const T& data)
        {
            if (IsEmpty())
                root = new BinaryNode<T>(data);

            BinaryNode<T>* current = root;

            while (current && current->Data != data)
            {
                if (current->Data > data && current->Left == NULL)
                {
                    current->Left = new BinaryNode<T>(data);
                    return;
                }
                if (current->Data < data && current->Right == NULL)
                {
                    current->Right = new BinaryNode<T>(data);
                    return;
                }
                if (current->Data > data)
                {
                    current = current->Left;
                }
                else
                {
                    current = current->Right;
                }                 
            }
        }

        
        /// <summary>
        /// Удалить узел по ключу.
        /// </summary>
        /// <param name="key">Данные узла который нужно удалить.</param>
        void Remove(const T& key)
        {
            BinaryTreeService::Remove(root, key);
        }

        
        bool IsEmpty()
        {
            if (root == nullptr)
                return true;
            else
                return false;
        }


        BinaryNode<T>* const GetRoot() const
        {
            return root;
        }


    private:
        // Корень двоичного дерева поиска
        BinaryNode<T>* root;
	};
}