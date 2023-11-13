//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include "BinaryTreeService.h"
#include "IIterated.h"
#include "InorderIterator.h"
#include <vector>

namespace DSAABinaryTree
{
	template<typename T>
	class BinarySearchTree : public IIterated<T>
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
        BinaryNode<T>* Search(const T& keyData) const
        {
            return BinaryTreeService::Search(root, keyData);
        }


        /// <summary>
        /// Вставить данные в дерево.
        /// </summary>
        /// <param name="data">Данные для нового узла.</param>
        void Insert(const T& data)
        {
            BinaryTreeService::Insert(root, data);
        }

        
        /// <summary>
        /// Удалить узел по ключу.
        /// </summary>
        /// <param name="key">Данные узла который нужно удалить.</param>
        void Remove(const T& key)
        {
            BinaryTreeService::Remove(root, key);
        }


        /// <summary>
        /// Максимум в дереве.
        /// </summary>
        /// <returns>Максимальные данные в дереве.</returns>
        T MaxItem() const
        {
            return BinaryTreeService::GetMaximumNode(root)->Data;
        }


        /// <summary>
        /// Минимум в дереве.
        /// </summary>
        /// <returns>Минимальные данные в дереве.</returns>
        T MinItem() const
        {
            return BinaryTreeService::GetMinimumNode(root)->Data;
        }


        /// <summary>
        /// Пустое ли дерево.
        /// </summary>
        /// <returns>True - пустое, false - не пустое.</returns>
        bool IsEmpty() const
        {
            return root == nullptr;
        }


        /// <summary>
        /// Удалить дерево.
        /// </summary>
        void Delete()
        {
            BinaryTreeService::Delete(root);
        }


        /// <summary>
        /// Получить указатель на корень дерева.
        /// </summary>
        /// <returns>Указатель на корень дерева.</returns>
        BinaryNode<T>* const GetRoot() const
        {
            return root;
        }


        /// <summary>
        /// Получить итератор в начале коллекции.
        /// </summary>
        InorderIterator<T>& begin() override
        {
            return *new InorderIterator<T>(root, true);
        }


        /// <summary>
        /// Получить итератор в конце коллекции.
        /// </summary>
        InorderIterator<T>& end() override
        {
            return *new InorderIterator<T>(nullptr, false);
        }


        private:
            // Корень двоичного дерева поиска
            BinaryNode<T>* root;
	};
}