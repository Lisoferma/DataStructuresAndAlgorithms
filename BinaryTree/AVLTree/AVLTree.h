//@author Lisoferma

#pragma once

#include <stdexcept>
#include "AVLNode.h"

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
		/// Вставить данные в дерево.
		/// </summary>
		/// <param name="data">Данные которые нужно вставить.</param>
		void Insert(const T& data)
		{
			_root = Insert(_root, data);
		}


	private:
		// Корень АВЛ-дерева
		AVLNode<T>* _root;


		/// <summary>
		/// Вспомогательный метод для получения высоты поддерева
		/// с корнем в указаном узле с проверкой на пустоту (nullptr).
		/// </summary>
		/// <param name="node">Узел у которого нужно получить высоту.</param>
		unsigned char GetHeight(AVLNode<T>* node)
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
		int GetBalanceFactor(AVLNode<T>* node)
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


		//node* findmin(node* p) // поиск узла с минимальным ключом в дереве p 
		//{
		//	return p->left ? findmin(p->left) : p;
		//}

		//node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
		//{
		//	if (p->left == 0)
		//		return p->right;
		//	p->left = removemin(p->left);
		//	return balance(p);
		//}

		//node* remove(node* p, int k) // удаление ключа k из дерева p
		//{
		//	if (!p) return 0;
		//	if (k < p->key)
		//		p->left = remove(p->left, k);
		//	else if (k > p->key)
		//		p->right = remove(p->right, k);
		//	else //  k == p->key 
		//	{
		//		node* q = p->left;
		//		node* r = p->right;
		//		delete p;
		//		if (!r) return q;
		//		node* min = findmin(r);
		//		min->right = removemin(r);
		//		min->left = q;
		//		return balance(min);
		//	}
		//	return balance(p);
		//}
	};
}