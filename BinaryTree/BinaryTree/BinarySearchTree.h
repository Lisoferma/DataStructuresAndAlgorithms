//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include "BinaryTreeService.h"
#include "IIterated.h"
#include "InorderIterator.h"
#include <vector>

namespace DSAABinaryTree
{
	/// <summary>
	/// Бинарное дерево поиска.
	/// </summary>
	/// <typeparam name="T">Тип данных который хранит дерево.</typeparam>
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
        BinarySearchTree(const std::vector<T>& dataVector) : root(nullptr)
        {
            for (auto data : dataVector)
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
            if (IsEmpty())
                throw std::out_of_range("Tree is empty.");

            return BinaryTreeService::GetMaximumNode(root)->Data;
        }


        /// <summary>
        /// Минимум в дереве.
        /// </summary>
        /// <returns>Минимальные данные в дереве.</returns>
        T MinItem() const
        {
            if (IsEmpty())
                throw std::out_of_range("Tree is empty.");

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
            return *new InorderIterator<T>(root);
        }


        /// <summary>
        /// Получить итератор в конце коллекции.
        /// </summary>
        InorderIterator<T>& end() override
        {
            return *new InorderIterator<T>(nullptr, false);
        }


        /// <summary>
        /// Получить вектор содержищий данные дерева (Inorder Treversal).
        /// </summary>
        /// <param name="vector">Вектор в который будут записываться данные.</param>
        void ToVector(std::vector<T>& vector) const
        {
            BinaryTreeService::InorderTraversal<T>(root, [&vector](BinaryNode<T>& node) {
                vector.push_back(node.Data); });
        }


        private:
            // Корень двоичного дерева поиска
            BinaryNode<T>* root;
	};
}