//@author Lisoferma

#pragma once

#include "TreeNode.h"
#include <functional>

namespace DSAABinaryTree
{
	/// <summary>
	/// —оздать бинарное дерево из п€ти узлов.
	/// </summary>
	/// <returns>”казатель на корень.</returns>
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
	/// —оздать бинарное дерево поиска из п€ти узлов.
	/// </summary>
	/// <returns>”казатель на корень.</returns>
	TreeNode<int>* CreateBinarySearchTree()
	{
		TreeNode<int>* root = new TreeNode<int>(5);

		root->Left = new TreeNode<int>(4);
		root->Right = new TreeNode<int>(6);

		root->Left->Left = new TreeNode<int>(3);
		root->Left->Right = new TreeNode<int>(5);

		return root;
	}


	template <typename T>
	using NodeProcessing = std::function<void(TreeNode<T>&)>;


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


	// какой будет пор€док дл€ дерева поиска
	template<typename T>
	void TraversalLRN(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		TraversalLRN(node->Left, nodeProcessing);
		TraversalLRN(node->Right, nodeProcessing);
		nodeProcessing(*node);
	}
}

