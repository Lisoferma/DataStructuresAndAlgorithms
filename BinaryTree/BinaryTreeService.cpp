#include "BinaryTreeService.h"

namespace DSAABinaryTree
{
	template<typename T>
	void BinaryTreeService::TraversalNLR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		nodeProcessing(node);
		TraversalNLR(node->Left, nodeProcessing);
		TraversalNLR(node->Right, nodeProcessing);
	}


	template<typename T>
	void BinaryTreeService::TraversalLNR(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;
		
		TraversalLNR(node->Left, nodeProcessing);
		nodeProcessing(node);		
		TraversalLNR(node->Right, nodeProcessing);
	}


	template<typename T>
	void BinaryTreeService::TraversalLRN(TreeNode<T>* node, NodeProcessing<T> nodeProcessing)
	{
		if (node == nullptr) return;

		TraversalLRN(node->Left, nodeProcessing);
		TraversalLRN(node->Right, nodeProcessing);
		nodeProcessing(node);	
	}


	template<typename T>
	void BinaryTreeService::TreeToVector(TreeNode<T>* node, std::vector<T>& vector)
	{
		if (vector == nullptr)
			vector = new std::vector<T>();

		vector.push_back(node->Data);
	}
}