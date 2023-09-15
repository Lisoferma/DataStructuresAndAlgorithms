//@author Alexander

#pragma once

#include "TreeNode.h"
#include <vector>

namespace DSAABinaryTree
{
	namespace BinaryTreeService
	{
		template <typename T>
		using NodeProcessing = void (*)(TreeNode<T>&);

		template<typename T>
		static void TraversalNLR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
		{
			if (node == nullptr) return;

			nodeProcessing(*node);
			TraversalNLR(node->Left, nodeProcessing);
			TraversalNLR(node->Right, nodeProcessing);
		}


		template<typename T>
		static void TraversalLNR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
		{
			if (node == nullptr) return;

			TraversalLNR(node->Left, nodeProcessing);
			nodeProcessing(*node);
			TraversalLNR(node->Right, nodeProcessing);
		}


		// какой будет порядок для дерева поиска
		template<typename T>
		static void TraversalLRN(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
		{
			if (node == nullptr) return;

			TraversalLRN(node->Left, nodeProcessing);
			TraversalLRN(node->Right, nodeProcessing);
			nodeProcessing(*node);
		}


		template<typename T>
		static void TreeToVector(TreeNode<T>* node, std::vector<T>& vector)
		{
			if (node == nullptr) return;

			if (vector == nullptr)
				vector = new std::vector<T>();

			vector.push_back(node->Data);
		}
	}
}

