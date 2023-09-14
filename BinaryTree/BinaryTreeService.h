#pragma once

#include "TreeNode.h"
#include <vector>

namespace DSAABinaryTree
{
	template <typename T>
	using NodeProcessing = void (*)(TreeNode<T>*, ...);

	class BinaryTreeService
	{
	public:
		BinaryTreeService() = default;

		template <typename T>
		static void TraversalNLR(TreeNode<T>* root, NodeProcessing<T> nodeProcessing);

		template<typename T>
		static void TraversalLNR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing);

		template<typename T>
		static void TraversalLRN(TreeNode<T>* node, NodeProcessing<T> nodeProcessing);

		template<typename T>
		static void TreeToVector(TreeNode<T>* node, std::vector<T>& vector);
	};
}

