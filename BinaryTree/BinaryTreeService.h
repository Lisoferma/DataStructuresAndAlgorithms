//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include <iostream>
#include <functional>

namespace DSAABinaryTree
{
	namespace BinaryTreeService
	{
		/// <summary>
		/// Синоним для указателя на функцию, которая обрабатывает данные узла.
		/// Применяется в функциях обхода.
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		template <typename T>
		using NodeProcessing = std::function<void(BinaryNode<T>&)>;


		/// <summary>
		/// Создать бинарное дерево из пяти узлов.
		/// </summary>
		/// <returns>Указатель на корень.</returns>
		BinaryNode<int>* CreateBinaryTree()
		{
			BinaryNode<int>* root = new BinaryNode<int>(1);

			root->Left = new BinaryNode<int>(2);
			root->Left->Parent = root;

			root->Right = new BinaryNode<int>(3);
			root->Right->Parent = root;

			root->Left->Left = new BinaryNode<int>(4);
			root->Left->Left->Parent = root->Left;

			root->Left->Right = new BinaryNode<int>(5);
			root->Left->Right->Parent = root->Left;

			return root;
		}


		/// <summary>
		/// Создать бинарное дерево поиска из пяти узлов.
		/// </summary>
		/// <returns>Указатель на корень.</returns>
		BinaryNode<int>* CreateBinarySearchTree()
		{
			BinaryNode<int>* root = new BinaryNode<int>(6);

			root->Left = new BinaryNode<int>(4);
			root->Left->Parent = root;

			root->Right = new BinaryNode<int>(7);
			root->Right->Parent = root;

			root->Left->Left = new BinaryNode<int>(3);
			root->Left->Left->Parent = root->Left;

			root->Left->Right = new BinaryNode<int>(5);
			root->Left->Right->Parent = root->Left;

			return root;
		}


		/// <summary>
		/// Обойти дерево в порядке NLR.
		/// Является топологически отсортированным.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="node">Узел с которого начинать обход.</param>
		/// <param name="nodeProcessing">Функция которая будет обрабатывать узлы.</param>
		template<typename T>
		void PreorderTraversal(BinaryNode<T>* node, NodeProcessing<T> nodeProcessing)
		{
			if (node == nullptr) return;

			nodeProcessing(*node);
			PreorderTraversal(node->Left, nodeProcessing);
			PreorderTraversal(node->Right, nodeProcessing);
		}


		/// <summary>
		/// Обойти дерево в порядке LNR.
		/// В бинарном дереве поиска ключи извлекаются в порядке возрастания.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="node">Узел с которого начинать обход.</param>
		/// <param name="nodeProcessing">Функция которая будет обрабатывать узлы.</param>
		template<typename T>
		void InorderTraversal(BinaryNode<T>* node, NodeProcessing<T> nodeProcessing)
		{
			if (node == nullptr) return;

			InorderTraversal(node->Left, nodeProcessing);
			nodeProcessing(*node);
			InorderTraversal(node->Right, nodeProcessing);
		}


		/// <summary>
		/// Обойти дерево в порядке LRN.
		/// Может быть полезно для получения постфиксного выражения дерева двоичных выражений.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="node">Узел с которого начинать обход.</param>
		/// <param name="nodeProcessing">Функция которая будет обрабатывать узлы.</param>
		template<typename T>
		void PostorderTraversal(BinaryNode<T>* node, NodeProcessing<T> nodeProcessing)
		{
			if (node == nullptr) return;

			PostorderTraversal(node->Left, nodeProcessing);
			PostorderTraversal(node->Right, nodeProcessing);
			nodeProcessing(*node);
		}


		/// <summary>
		/// Количество узлов в бинарном дереве.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="node">Узел с которого начинать отсчёт.</param>
		/// <returns>Количество узлов.</returns>
		template<typename T>
		size_t NodeCount(BinaryNode<T>* node)
		{	
			if (node == nullptr) return 0;

			size_t leftCount = NodeCount(node->Left);
			size_t rightCount = NodeCount(node->Right);

			return 1 + leftCount + rightCount;
		}


		/// <summary>
		/// Высота бинарного дерева.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="node">Узел с которого начинать отсчёт.</param>
		/// <returns>Высота дерева.</returns>
		template<typename T>
		size_t TreeHeight(BinaryNode<T>* node)
		{
			if (node == nullptr) return 0;

			size_t leftCount = TreeHeight(node->Left);
			size_t rightCount = TreeHeight(node->Right);

			return 1 + (leftCount > rightCount ? leftCount : rightCount);
		}

	
		/// <summary>
		/// Поиск узла по ключу.
		/// </summary>
		/// <typeparam name="T">Тип данных который хранит узел.</typeparam>
		/// <param name="node">Узел с которого начинать поиск.</param>
		/// <param name="keyData">Ключ по которому производится поиск.</param>
		/// <returns>Указатель на найденный узел.</returns>
		template<typename T>
		BinaryNode<T>* Search(BinaryNode<T>* node, const T& keyData)
		{
			BinaryNode<T>* current = node;

			while (current != nullptr)
				if (current->Data == keyData)
					return current;
				else
					current = keyData < current->Data ?
					current->Left : current->Right;

			return nullptr;
		}


		/// <summary>
		/// Получить родительский узел для узла - при котором он будет левым потомком. 
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		/// <param name="node">Узел для которого нужно получить родителя.</param>
		/// <returns>Указатель на найденного родителя. nullptr - если не нашлось</returns>
		template<typename T>
		BinaryNode<T>* GetParent(BinaryNode<T>* node)
		{
			if (node->Parent == nullptr)
				return nullptr;

			if (node->Parent->Left == node)
				return node->Parent;
			else
				return GetParent(node->Parent);
		}


		/// <summary>
		/// Получить максимальный узел.
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		/// <param name="root">Узел с которого начинать поиск максимального.</param>
		/// <returns>Максимальный узел в дереве.</returns>
		template<typename T>
		BinaryNode<T>* GetMaximumNode(BinaryNode<T>* root)
		{
            BinaryNode<T>* current = root;

            while (current->Right != nullptr)
                current = current->Right;

            return current;
		}


		/// <summary>
		/// Получить минимальный узел.
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		/// <param name="root">Узел с которого начинать поиск минимального.</param>
		/// <returns>Минимальный узел в дереве.</returns>
		template<typename T>
		BinaryNode<T>* GetMinimumNode(BinaryNode<T>* root)
		{
			BinaryNode<T>* current = root;

			while (current->Left != nullptr)
				current = current->Left;

			return current;
		}


		/// <summary>
		/// Получить следующего наибольшего преемника узла.
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		/// <param name="root">Узел для которого ищется следующий наибольший узел.</param>
		/// <returns>Указатель на найденный узел.</returns>
		template<typename T>
		BinaryNode<T>* GetInOrderSuccessor(BinaryNode<T>* root)
		{
			if (root == nullptr)
				return nullptr;

			if (root->Right)
				return GetMinimumNode(root->Right);
			else
				return GetParent(root);
		}

	
		/// <summary>
		/// Удалить узел по ключу.
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		/// <param name="node">Узел с которого начинать поиск удаляемого узла.</param>
		/// <param name="key">Данные узла который нужно удалить.</param>
		template<typename T>
		void Remove(BinaryNode<T>*& node, const T& key)
		{
			if (node == nullptr) return;

			// Поиск удаляемого узла
			if (key < node->Data)
			{
				Remove(node->Left, key);
			}
			else if (key > node->Data)
			{
				Remove(node->Right, key);
			}
			// Если у удаляемого узла есть оба дочерних узла
			else if (node->Left != nullptr && node->Right != nullptr)
			{
				node->Data = GetMinimumNode(node->Right)->Data;
				Remove(node->Right, node->Data);
			}
			else
			{
				BinaryNode<T>* temp = nullptr;

				// Есть только левый дочерний узел
				if (node->Left != nullptr)
				{
					temp = node;
					node = node->Left;
					delete temp;
				}
				// Есть только правый дочерний узел
				else if (node->Right != nullptr)
				{
					temp = node;
					node = node->Right;
					delete temp;
				}
				// Нет дочерних узлов
				else
				{
					delete node;
					node = nullptr;
				}
			}
		}


		/// <summary>
		/// Вставить данные в бинарное дерево поиска.
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		/// <param name="root">Корень дерева поиска.</param>
		/// <param name="data">Данные для нового узла.</param>
		template<typename T>
		void Insert(BinaryNode<T>*& root, const T& data)
		{
			if (root == nullptr)
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
		/// Скопировать дерево.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="root">Дерево которое нужно скопировать.</param>
		/// <returns>Указатель на новое скопированное дерево.</returns>
		template<typename T>
		BinaryNode<T>* Clone(BinaryNode<T>* root)
		{
			if (root == nullptr) return nullptr;

			BinaryNode<T>* copyRoot = new BinaryNode<T>(root->Data);

			copyRoot->Left = Clone(root->Left);
			copyRoot->Right = Clone(root->Right);

			return copyRoot;
		}


		/// <summary>
		/// Удалить дерево.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="root">Корень дерева.</param>
		template<typename T>
		void Delete(BinaryNode<T>*& root)
		{
			if (root == nullptr) return;

			Delete(root->Left);
			Delete(root->Right);

			delete root;
			root = nullptr;
		}
	}
}

