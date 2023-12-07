//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include <iostream>
#include <functional>
#include <queue>

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

			root->Right = new BinaryNode<int>(3);

			root->Left->Left = new BinaryNode<int>(4);

			root->Left->Right = new BinaryNode<int>(5);

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

			root->Right = new BinaryNode<int>(7);

			root->Left->Left = new BinaryNode<int>(3);

			root->Left->Right = new BinaryNode<int>(5);

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
		/// Получить узел преемник для указанного ключа.
		/// </summary>
		/// <typeparam name="T">Тип данных узла.</typeparam>
		/// <param name="root">Корень дерева.</param>
		/// <param name="key">Ключ для которого нужно найти преемника.</param>
		/// <returns>Найденный узел.</returns>
		template<typename T>
		BinaryNode<T>* Successor(BinaryNode<T>* root, int key)
		{
			BinaryNode<T>* temp = root;
			BinaryNode<T>* s = nullptr;

			while (temp != nullptr)
			{
				if (temp->Data < key)
				{
					temp = temp->Right;
				}
				else if (temp->Data > key)
				{
					temp = temp->Left;
				}
				// если ключ найден в узле, то самый левый узел правого поддерева
				// является преемником ключа
				else if (temp->Data == key)
				{
					// находит крайний левый узел правого поддерева
					if (temp->Right != nullptr)
					{
						temp = GetMinimumNode(temp->Right);
					}
					// если правого поддерева не существует, то преемником
					// будет узел, от которого сделан последний поворот налево
					else
					{
						// переход начинается от корня к этому узлу
						while (root->Data != key)
						{
							// если ключ меньше корневого, переходит в левое поддерево
							// s сохраняет узел, откуда берется левый поворот
							if (key < root->Data)
							{
								s = root;
								root = root->Left;
							}
							// иначе, к правому поддереву
							else
								root = root->Right;
						}
						temp = s;
					}
					return temp;
				}
			}

			return nullptr;
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
		/// Удалить дерево рекурсивным методом.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="root">Корень дерева.</param>
		template<typename T>
		void DeleteRecursively(BinaryNode<T>*& root)
		{
			if (root == nullptr) return;

			Delete(root->Left);
			Delete(root->Right);

			delete root;
			root = nullptr;
		}


		/// <summary>
		/// Удалить дерево итеративным методом.
		/// </summary>
		/// <typeparam name="T">Тип данных дерева.</typeparam>
		/// <param name="root">Корень дерева.</param>
		template<typename T>
		void Delete(BinaryNode<T>*& root)
		{
			if (root == nullptr) return;

			std::queue<BinaryNode<T>*> queue;
			queue.push(root);

			BinaryNode<T>* front = nullptr;

			while (!queue.empty())
			{
				front = queue.front();
				queue.pop();

				if (front->Left)
					queue.push(front->Left);

				if (front->Right)
					queue.push(front->Right);

				delete front;
			}

			root = nullptr;
		}
	}
}

