//@author Lisoferma

#pragma once

#include "TreeNode.h"
#include <iostream>
#include <functional>

namespace DSAABinaryTree
{
	/// <summary>
	/// Синоним для указателя на функцию, которая обрабатывает данные узла.
	/// Применяется в функциях обхода.
	/// </summary>
	/// <typeparam name="T">Тип данных узла.</typeparam>
	template <typename T>
	using NodeProcessing = std::function<void(TreeNode<T>&)>;


	/// <summary>
	/// Создать бинарное дерево из пяти узлов.
	/// </summary>
	/// <returns>Указатель на корень.</returns>
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
	/// Создать бинарное дерево поиска из пяти узлов.
	/// </summary>
	/// <returns>Указатель на корень.</returns>
	TreeNode<int>* CreateBinarySearchTree()
	{
		TreeNode<int>* root = new TreeNode<int>(5);

		root->Left = new TreeNode<int>(4);
		root->Right = new TreeNode<int>(6);

		root->Left->Left = new TreeNode<int>(3);
		root->Left->Right = new TreeNode<int>(5);

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
	void TraversalNLR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		nodeProcessing(*node);
		TraversalNLR(node->Left, nodeProcessing);
		TraversalNLR(node->Right, nodeProcessing);
	}


	/// <summary>
	/// Обойти дерево в порядке LNR.
	/// В бинарном дереве поиска ключи извлекаются в порядке возрастания.
	/// </summary>
	/// <typeparam name="T">Тип данных дерева.</typeparam>
	/// <param name="node">Узел с которого начинать обход.</param>
	/// <param name="nodeProcessing">Функция которая будет обрабатывать узлы.</param>
	template<typename T>
	void TraversalLNR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		TraversalLNR(node->Left, nodeProcessing);
		nodeProcessing(*node);
		TraversalLNR(node->Right, nodeProcessing);
	}


	/// <summary>
	/// Обойти дерево в порядке LRN.
	/// Может быть полезно для получения постфиксного выражения дерева двоичных выражений.
	/// </summary>
	/// <typeparam name="T">Тип данных дерева.</typeparam>
	/// <param name="node">Узел с которого начинать обход.</param>
	/// <param name="nodeProcessing">Функция которая будет обрабатывать узлы.</param>
	template<typename T>
	void TraversalLRN(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		TraversalLRN(node->Left, nodeProcessing);
		TraversalLRN(node->Right, nodeProcessing);
		nodeProcessing(*node);
	}


	/// <summary>
	/// Количество узлов в бинарном дереве.
	/// </summary>
	/// <typeparam name="T">Тип данных дерева.</typeparam>
	/// <param name="node">Узел с которого начинать отсчёт.</param>
	/// <returns>Количество узлов.</returns>
	template<typename T>
	size_t NodeCount(TreeNode<T>* node)
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
	size_t TreeHeight(TreeNode<T>* node)
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
	/// Получить родительский узел для узла - при котором он будет левым потомком. 
	/// </summary>
	/// <typeparam name="T">Тип данных узла.</typeparam>
	/// <param name="node">Узел для которого нужно получить родителя.</param>
	/// <returns>Указатель на найденного родителя. nullptr - если не нашлось</returns>
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
	/// Получить крайний левый узел в поддереве.
	/// </summary>
	/// <typeparam name="T">Тип данных узла.</typeparam>
	/// <param name="node">Узел с которого начинать поиск.</param>
	/// <returns>Указатель на крайний левый узел.</returns>
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
	/// Получить следующего наибольшего преемника узла.
	/// </summary>
	/// <typeparam name="T">Тип данных узла.</typeparam>
	/// <param name="root">Узел для которого ищется следующий наибольший узел.</param>
	/// <returns>Указатель на найденный узел.</returns>
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

