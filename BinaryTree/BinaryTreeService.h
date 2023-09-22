//@author Lisoferma

#pragma once

#include "TreeNode.h"
#include <iostream>
#include <functional>

namespace DSAABinaryTree
{
	/// <summary>
	/// ������� ��� ��������� �� �������, ������� ������������ ������ ����.
	/// ����������� � �������� ������.
	/// </summary>
	/// <typeparam name="T">��� ������ ��������� ������</typeparam>
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
		root->Right = new TreeNode<int>(3);

		root->Left->Left = new TreeNode<int>(4);
		root->Left->Right = new TreeNode<int>(5);

		return root;
	}


	/// <summary>
	/// ������� �������� ������ ������ �� ���� �����.
	/// </summary>
	/// <returns>��������� �� ������.</returns>
	TreeNode<int>* CreateBinarySearchTree()
	{
		TreeNode<int>* root = new TreeNode<int>(5);

		root->Left = new TreeNode<int>(4);
		root->Right = new TreeNode<int>(6);

		root->Left->Left = new TreeNode<int>(3);
		root->Left->Right = new TreeNode<int>(5);

		return root;
	}


	template<typename T>
	void TraversalNLR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		nodeProcessing(*node);
		TraversalNLR(node->Left, nodeProcessing);
		TraversalNLR(node->Right, nodeProcessing);
	}


	template<typename T>
	void TraversalLNR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		TraversalLNR(node->Left, nodeProcessing);
		nodeProcessing(*node);
		TraversalLNR(node->Right, nodeProcessing);
	}


	// ����� ����� ������� ��� ������ ������
	template<typename T>
	void TraversalLRN(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		TraversalLRN(node->Left, nodeProcessing);
		TraversalLRN(node->Right, nodeProcessing);
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


	//go up the tree until we have our root node a left child of its parent
	template<typename T>
	TreeNode<T>* GetParent(TreeNode<T>* root)
	{
		if (root->Parent == nullptr)
			return nullptr;

		if (root->Parent->Left == root)
			return root->Parent;
		else
			return GetParent(root->Parent);
	}


	template<typename T>
	TreeNode<T>* GetLeftMostNode(TreeNode<T>* root)
	{
		if (root == nullptr)
			return nullptr;

		TreeNode<T>* left = GetLeftMostNode(root->Left);
		if (left)
			return left;

		return root;
	}


	/// <summary>
	/// ����� ���������� ����������� ��������� ����.
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
}

