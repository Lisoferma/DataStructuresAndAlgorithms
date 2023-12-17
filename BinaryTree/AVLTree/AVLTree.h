//@author Lisoferma

#pragma once

#include <vector>
#include <stdexcept>
#include "AVLNode.h"
#include "../BinaryTree/BinaryTreeService.h"

namespace DSAAVLTree
{
	template<typename T>
	class AVLTree
	{
	public:
		/// <summary>
		/// Инициализировать пустое дерево.
		/// </summary>
		AVLTree() : _root(nullptr)
		{ }

		
		/// <summary>
		/// Инициализировать дерево вектрором.
		/// </summary>
		/// <param name="dataVector">Вектор который содержит данные для вставки в дерево.</param>
		AVLTree(const std::vector<T>& dataVector) : AVLTree()
		{
			for (T data : dataVector)
				Insert(data);
		}


		/// <summary>
		/// Вставить данные в дерево.
		/// </summary>
		/// <param name="data">Данные которые нужно вставить.</param>
		void Insert(const T& data)
		{
			_root = Insert(_root, data);
		}


		/// <summary>
		/// Удалить узел по заданому ключу.
		/// </summary>
		/// <param name="key">Данные узла который нужно удалить.</param>
		void Remove(const T& key)
		{
			_root = Remove(_root, key);
		}


		/// <summary>
		/// Проверить наличие элемента в дереве.
		/// </summary>
		/// <param name="key">Данные которые нужно проверить.</param>
		/// <returns>True - элемент есть в дереве, false - элемента нет в дереве.</returns>
		bool Find(const T& key) const
		{
			return BinaryTreeService::Search(_root, key) != nullptr;
		}


		/// <summary>
		/// Максимальный элемент в дереве.
		/// </summary>
		T MaxItem() const
		{
			if (IsEmpty())
				throw std::out_of_range("Tree is empty.");

			return BinaryTreeService::GetMaximumNode(_root)->Data;
		}


		/// <summary>
		/// Минимальный элемент в дереве.
		/// </summary>
		T MinItem() const
		{
			if (IsEmpty())
				throw std::out_of_range("Tree is empty.");

			return BinaryTreeService::GetMinimumNode(_root)->Data;
		}


		/// <summary>
		/// Высота дерева, -1 если пустое.
		/// </summary>
		int GetHeight() const
		{
			if (IsEmpty())
				return -1;

			return _root->Height - 1;
		}


		/// <summary>
		/// Пустое ли дерево.
		/// </summary>
		/// <returns>True - пустое, false - не пустое.</returns>
		bool IsEmpty() const
		{
			return _root == nullptr;
		}


		// TODO: Исправить метод удаления дерева.
		/// <summary>
		/// Удалить дерево.
		/// </summary>
		//void Delete()
		//{
		//	BinaryNode<T>* rootPtr = static_cast<BinaryNode<T>*>(_root);
		//	BinaryNode<T>*& rootPtrRef = _root;

		//	BinaryTreeService::Delete(rootPtrRef);
		//}
		
		
		/// <summary>
		/// Получить корень дерева.
		/// </summary>
		/// <remarks>
		/// Только для тестов. Не изменяйте корень.
		/// </remarks>
		AVLNode<T>* GetRoot()
		{
			return _root;
		}


	private:
		// Корень АВЛ-дерева
		AVLNode<T>* _root;


		/// <summary>
		/// Вспомогательный метод для получения высоты поддерева
		/// с корнем в указаном узле с проверкой на пустоту (nullptr).
		/// </summary>
		/// <param name="node">Узел у которого нужно получить высоту.</param>
		unsigned char GetHeight(AVLNode<T>* node) const
		{
			return node == nullptr ? 0 : node->Height;
		}


		/// <summary>
		/// Восстановить коректное значение поля Height заданного узла.
		/// </summary>
		/// <param name="node">Узел в котором нужно восстановить высоту.</param>
		void FixHeight(AVLNode<T>* node)
		{
			unsigned char HeightLeft = GetHeight(node->GetLeft());
			unsigned char HeightRight = GetHeight(node->GetRight());

			node->Height = (HeightLeft > HeightRight ? HeightLeft : HeightRight) + 1;
		}


		/// <summary>
		/// Получить баланс фактор заданного узла.
		/// </summary>
		/// <param name="node">Узел для которого нужно найти баланс фактор.</param>
		/// <returns>Баланс фактор.</returns>
		int GetBalanceFactor(AVLNode<T>* node) const
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			return GetHeight(node->GetRight()) - GetHeight(node->GetLeft());
		}


		/// <summary>
		/// Правый поворот вокруг заданного узла.
		/// </summary>
		/// <param name="node">Узел для которого сделать поворот.</param>
		/// <returns>Новый корень дерева.</returns>
		AVLNode<T>* RotateRight(AVLNode<T>* node)
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			AVLNode<T>* q = node->GetLeft();
			node->Left = q->GetRight();
			q->Right = node;

			FixHeight(node);
			FixHeight(q);

			return q;
		}


		/// <summary>
		/// Левый поворот вокруг заданного узла.
		/// </summary>
		/// <param name="node">Узел для которого сделать поворот.</param>
		/// <returns>Новый корень дерева.</returns>
		AVLNode<T>* RotateLeft(AVLNode<T>* node)
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			AVLNode<T>* p = node->GetRight();
			node->Right = p->GetLeft();
			p->Left = node;

			FixHeight(node);
			FixHeight(p);

			return p;
		}


		/// <summary>
		/// Балансировка заданного узла.
		/// </summary>
		/// <param name="node">Узел для которого произвести балансировку.</param>
		/// <returns>Новый корень дерева.</returns>
		AVLNode<T>* Balance(AVLNode<T>* node)
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			FixHeight(node);

			if (GetBalanceFactor(node) == 2)
			{
				if (GetBalanceFactor(node->GetRight()) < 0)
					node->Right = RotateRight(node->GetRight());

				return RotateLeft(node);
			}

			if (GetBalanceFactor(node) == -2)
			{
				if (GetBalanceFactor(node->GetLeft()) > 0)
					node->Left = RotateLeft(node->GetLeft());

				return RotateRight(node);
			}

			// Если балансировка не нужна.
			return node;
		}


		/// <summary>
		/// Вставить данные в дерево.
		/// </summary>
		/// <param name="root">Корень дерева.</param>
		/// <param name="data">Данные которые нужно вставить.</param>
		/// <returns>Новый корень дерева.</returns>
		AVLNode<T>* Insert(AVLNode<T>* root, const T& data)
		{
			if (root == nullptr)
				return new AVLNode<T>(data);

			if (data < root->Data)
				root->Left = Insert(root->GetLeft(), data);
			else
				root->Right = Insert(root->GetRight(), data);

			return Balance(root);
		}


		/// <summary>
		/// Получить узел с минимальными данными в дереве.
		/// </summary>
		/// <param name="root">Корень дерева.</param>
		/// <returns>Указатель на найденный узел.</returns>
		AVLNode<T>* GetMin(AVLNode<T>* root) const
		{
			return root->Left ? GetMin(root->GetLeft()) : root;
		}


		/// <summary>
		/// Удалить узел с минимальными данными.
		/// </summary>
		/// <param name="root">Корень дерева.</param>
		/// <returns>Указатель на новй корень дерева.</returns>
		AVLNode<T>* RemoveMin(AVLNode<T>* root)
		{
			if (root->Left == nullptr)
				return root->GetRight();

			root->Left = RemoveMin(root->GetLeft());

			return Balance(root);
		}


		/// <summary>
		/// Удаление узла по заданому ключу.
		/// </summary>
		/// <param name="root">Корень дерева.</param>
		/// <param name="key">Данные узла который нужно удалить.</param>
		/// <returns>Указатель на новый корень дерева.</returns>
		AVLNode<T>* Remove(AVLNode<T>* root, const T& key)
		{
			if (root == nullptr)
				return nullptr;

			if (key < root->Data)
			{
				root->Left = Remove(root->GetLeft(), key);
			}	
			else if (key > root->Data)
			{
				root->Right = Remove(root->GetRight(), key);
			}
			else // key == root->Data 
			{
				AVLNode<T>* q = root->GetLeft();
				AVLNode<T>* r = root->GetRight();

				delete root;

				if (r == nullptr)
					return q;

				AVLNode<T>* min = GetMin(r);

				min->Right = RemoveMin(r);
				min->Left = q;

				return Balance(min);
			}

			return Balance(root);
		}
	};
}