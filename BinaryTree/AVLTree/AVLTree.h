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
		/// �������� ������ � ������.
		/// </summary>
		/// <param name="data">������ ������� ����� ��������.</param>
		void Insert(const T& data)
		{
			_root = Insert(_root, data);
		}


	private:
		// ������ ���-������
		AVLNode<T>* _root;


		/// <summary>
		/// ��������������� ����� ��� ��������� ������ ���������
		/// � ������ � �������� ���� � ��������� �� ������� (nullptr).
		/// </summary>
		/// <param name="node">���� � �������� ����� �������� ������.</param>
		unsigned char GetHeight(AVLNode<T>* node)
		{
			return node == nullptr ? 0 : node->Height;
		}


		/// <summary>
		/// ������������ ��������� �������� ���� Height ��������� ����.
		/// </summary>
		/// <param name="node">���� � ������� ����� ������������ ������.</param>
		void FixHeight(AVLNode<T>* node)
		{
			unsigned char HeightLeft = GetHeight(node->Left);
			unsigned char HeightRight = GetHeight(node->Right);

			node->Height = (HeightLeft > HeightRight ? HeightLeft : HeightRight) + 1;
		}


		/// <summary>
		/// �������� ������ ������ ��������� ����.
		/// </summary>
		/// <param name="node">���� ��� �������� ����� ����� ������ ������.</param>
		/// <returns></returns>
		int GetBalanceFactor(AVLNode<T>* node)
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			return GetHeight(node->Right) - GetHeight(node->Left);
		}


		/// <summary>
		/// ������ ������� ������ ��������� ����.
		/// </summary>
		/// <param name="node">���� ��� �������� ������� �������.</param>
		/// <returns>����� ������ ������.</returns>
		AVLNode<T>* RotateRight(AVLNode<T>* node)
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			AVLNode<T>* q = node->Left;
			node->Left = q->right;
			q->right = node;

			FixHeight(node);
			FixHeight(q);

			return q;
		}


		/// <summary>
		/// ����� ������� ������ ��������� ����.
		/// </summary>
		/// <param name="node">���� ��� �������� ������� �������.</param>
		/// <returns>����� ������ ������.</returns>
		AVLNode<T>* RotateLeft(AVLNode<T>* node)
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			AVLNode<T>* p = node->Right;
			node->Right = p->Left;
			p->Left = node;

			FixHeight(node);
			FixHeight(p);

			return p;
		}


		/// <summary>
		/// ������������ ��������� ����.
		/// </summary>
		/// <param name="node">���� ��� �������� ���������� ������������.</param>
		/// <returns>����� ������ ������.</returns>
		AVLNode<T>* Balance(AVLNode<T>* node)
		{
			if (node == nullptr)
				throw std::invalid_argument("Node must not be nullptr.");

			FixHeight(node);

			if (GetBalanceFactor(node) == 2)
			{
				if (GetBalanceFactor(node->Right) < 0)
					node->Right = RotateRight(node->Right);

				return RotateLeft(node);
			}

			if (GetBalanceFactor(node) == -2)
			{
				if (GetBalanceFactor(node->Left) > 0)
					node->Left = RotateLeft(node->Left);

				return RotateRight(node);
			}

			// ���� ������������ �� �����.
			return node;
		}


		/// <summary>
		/// �������� ������ � ������.
		/// </summary>
		/// <param name="root">������ ������.</param>
		/// <param name="data">������ ������� ����� ��������.</param>
		/// <returns>����� ������ ������.</returns>
		AVLNode<T>* Insert(AVLNode<T>* root, const T& data)
		{
			if (root == nullptr)
				return new AVLNode<T>(data);

			if (data < root->Data)
				root->Left = Insert(root->Left, data);
			else
				root->Right = Insert(root->Right, data);

			return Balance(root);
		}


		//node* findmin(node* p) // ����� ���� � ����������� ������ � ������ p 
		//{
		//	return p->left ? findmin(p->left) : p;
		//}

		//node* removemin(node* p) // �������� ���� � ����������� ������ �� ������ p
		//{
		//	if (p->left == 0)
		//		return p->right;
		//	p->left = removemin(p->left);
		//	return balance(p);
		//}

		//node* remove(node* p, int k) // �������� ����� k �� ������ p
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