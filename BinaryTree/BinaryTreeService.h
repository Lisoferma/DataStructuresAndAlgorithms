//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include <iostream>
#include <functional>

namespace DSAABinaryTree
{
	/// <summary>
	/// ������� ��� ��������� �� �������, ������� ������������ ������ ����.
	/// ����������� � �������� ������.
	/// </summary>
	/// <typeparam name="T">��� ������ ����.</typeparam>
	template <typename T>
	using NodeProcessing = std::function<void(TreeNode<T>&)>;


	/// <summary>
	/// ������� �������� ������ �� ���� �����.
	/// </summary>
	/// <returns>��������� �� ������.</returns>
	TreeNode<int>* CreateBinaryTree()
	{
		TreeNode<int>* root = new TreeNode<int>(1);

		root->Left = new TreeNode<int>(2);
		root->Left->Parent = root;

		root->Right = new TreeNode<int>(3);
		root->Right->Parent = root;

		root->Left->Left = new TreeNode<int>(4);
		root->Left->Left->Parent = root->Left;

		root->Left->Right = new TreeNode<int>(5);
		root->Left->Right->Parent = root->Left;

		return root;
	}


	/// <summary>
	/// ������� �������� ������ ������ �� ���� �����.
	/// </summary>
	/// <returns>��������� �� ������.</returns>
	TreeNode<int>* CreateBinarySearchTree()
	{
		TreeNode<int>* root = new TreeNode<int>(6);

		root->Left = new TreeNode<int>(4);
		root->Left->Parent = root;

		root->Right = new TreeNode<int>(7);
		root->Right->Parent = root;

		root->Left->Left = new TreeNode<int>(3);
		root->Left->Left->Parent = root->Left;

		root->Left->Right = new TreeNode<int>(5);
		root->Left->Right->Parent = root->Left;

		return root;
	}


	/// <summary>
	/// ������ ������ � ������� NLR.
	/// �������� ������������� ���������������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������.</typeparam>
	/// <param name="node">���� � �������� �������� �����.</param>
	/// <param name="nodeProcessing">������� ������� ����� ������������ ����.</param>
	template<typename T>
	void PreorderTraversal(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		nodeProcessing(*node);
		PreorderTraversal(node->Left, nodeProcessing);
		PreorderTraversal(node->Right, nodeProcessing);
	}


	/// <summary>
	/// ������ ������ � ������� LNR.
	/// � �������� ������ ������ ����� ����������� � ������� �����������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������.</typeparam>
	/// <param name="node">���� � �������� �������� �����.</param>
	/// <param name="nodeProcessing">������� ������� ����� ������������ ����.</param>
	template<typename T>
	void InorderTraversal(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		InorderTraversal(node->Left, nodeProcessing);
		nodeProcessing(*node);
		InorderTraversal(node->Right, nodeProcessing);
	}


	/// <summary>
	/// ������ ������ � ������� LRN.
	/// ����� ���� ������� ��� ��������� ������������ ��������� ������ �������� ���������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������.</typeparam>
	/// <param name="node">���� � �������� �������� �����.</param>
	/// <param name="nodeProcessing">������� ������� ����� ������������ ����.</param>
	template<typename T>
	void PostorderTraversal(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		PostorderTraversal(node->Left, nodeProcessing);
		PostorderTraversal(node->Right, nodeProcessing);
		nodeProcessing(*node);
	}


	/// <summary>
	/// ���������� ����� � �������� ������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������.</typeparam>
	/// <param name="node">���� � �������� �������� ������.</param>
	/// <returns>���������� �����.</returns>
	template<typename T>
	size_t NodeCount(TreeNode<T>* node)
	{	
		if (node == nullptr) return 0;

		size_t leftCount = NodeCount(node->Left);
		size_t rightCount = NodeCount(node->Right);

		return 1 + leftCount + rightCount;
	}


	/// <summary>
	/// ������ ��������� ������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������.</typeparam>
	/// <param name="node">���� � �������� �������� ������.</param>
	/// <returns>������ ������.</returns>
	template<typename T>
	size_t TreeHeight(TreeNode<T>* node)
	{
		if (node == nullptr) return 0;

		size_t leftCount = TreeHeight(node->Left);
		size_t rightCount = TreeHeight(node->Right);

		return 1 + (leftCount > rightCount ? leftCount : rightCount);
	}

	
	/// <summary>
	/// ����� ���� �� �����.
	/// </summary>
	/// <typeparam name="T">��� ������ ������� ������ ����.</typeparam>
	/// <param name="node">���� � �������� �������� �����.</param>
	/// <param name="keyData">���� �� �������� ������������ �����.</param>
	/// <returns>��������� �� ��������� ����.</returns>
	template<typename T>
	TreeNode<T>* Find(TreeNode<T>* node, T keyData)
	{
		TreeNode<T>* current = node;

		while (current != nullptr)
			if (current->Data == keyData)
				return current;
			else
				current = keyData < current->Data ?
				current->Left : current->Right;

		return nullptr;
	}


	/// <summary>
	/// �������� ������������ ���� ��� ���� - ��� ������� �� ����� ����� ��������. 
	/// </summary>
	/// <typeparam name="T">��� ������ ����.</typeparam>
	/// <param name="node">���� ��� �������� ����� �������� ��������.</param>
	/// <returns>��������� �� ���������� ��������. nullptr - ���� �� �������</returns>
	template<typename T>
	TreeNode<T>* GetParent(TreeNode<T>* node)
	{
		if (node->Parent == nullptr)
			return nullptr;

		if (node->Parent->Left == node)
			return node->Parent;
		else
			return GetParent(node->Parent);
	}


	/// <summary>
	/// �������� ������� ����� ���� � ���������.
	/// </summary>
	/// <typeparam name="T">��� ������ ����.</typeparam>
	/// <param name="node">���� � �������� �������� �����.</param>
	/// <returns>��������� �� ������� ����� ����.</returns>
	template<typename T>
	TreeNode<T>* GetLeftMostNode(TreeNode<T>* node)
	{
		if (node == nullptr)
			return nullptr;

		TreeNode<T>* left = GetLeftMostNode(node->Left);
		if (left)
			return left;

		return node;
	}


	/// <summary>
	/// �������� ���������� ����������� ��������� ����.
	/// </summary>
	/// <typeparam name="T">��� ������ ����.</typeparam>
	/// <param name="root">���� ��� �������� ������ ��������� ���������� ����.</param>
	/// <returns>��������� �� ��������� ����.</returns>
	template<typename T>
	TreeNode<T>* GetInOrderSuccessor(TreeNode<T>* root)
	{
		if (root == nullptr)
			return nullptr;

		if (root->Right)
			return GetLeftMostNode(root->Right);
		else
			return GetParent(root);
	}


	/// <summary>
	/// �������� ����������� ����.
	/// </summary>
	/// <typeparam name="T">��� ������ ����.</typeparam>
	/// <param name="root">���� � �������� �������� ����� ������������.</param>
	/// <returns>����������� ���� � ������.</returns>
	template<typename T>
	TreeNode<T>* GetMinimumNode(TreeNode<T>* root)
	{
		TreeNode<T>* current = root;

		while (current && current->Left != nullptr)
			current = current->Left;

		return current;
	}

	
	/// <summary>
	/// ������� ���� �� �����.
	/// </summary>
	/// <typeparam name="T">��� ������ ����.</typeparam>
	/// <param name="node">���� � �������� �������� ����� ���������� ����.</param>
	/// <param name="key">������ ���� ������� ����� �������.</param>
	template<typename T>
	void Remove(TreeNode<T>*& node, T key)
	{
		if (node == nullptr) return;

		if (key < node->Data)
		{
			Remove(node->Left, key);
		}
		else if (key > node->Data)
		{
			Remove(node->Right, key);
		}
		else if (node->Left != nullptr && node->Right != nullptr)
		{
			node->Data = GetMinimumNode(node->Right)->Data;
			Remove(node->Right, node->Data);
		}
		else
		{
			TreeNode<T>* temp = nullptr;

			if (node->Left != nullptr)
			{
				temp = node;
				node = temp->Left;
				delete temp;
			}
			else if (node->Right != nullptr)
			{
				temp = node;
				node = temp->Right;
				delete temp;
			}
			else
			{
				delete node;
				node = nullptr;
			}
		}
	}
}

