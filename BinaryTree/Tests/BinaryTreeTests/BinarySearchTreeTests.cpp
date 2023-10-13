#include "pch.h"
#include "../../BinarySearchTree.h"
#include "../../BinaryTreeService.h"
#include <vector>

using namespace DSAABinaryTree;

TEST(Constructor, NoArguments_InitializeNullptr)
{
	BinarySearchTree<int> bst;

	EXPECT_EQ(bst.GetRoot(), nullptr);
}


TEST(Constructor, ArgumentRoot_InitializeRoot)
{
	BinaryNode<int>* initializeRoot = new BinaryNode<int>(5);
	BinarySearchTree<int> bst(initializeRoot);

	EXPECT_EQ(bst.GetRoot(), initializeRoot);
}


//TEST(Constructor, ArgumentVector_InitializeTreeFromVector)
//{
//	std::vector<int> vectorInitialize = { 1, 2, 3, 4, 5, 6 };
//	BinarySearchTree<int> bst(vectorInitialize);
//
//	std::vector<int> vectorFromTree;
//	BinaryTreeService::InorderTraversal<int>(bst.GetRoot(), [&vectorFromTree](BinaryNode<int>& node) {
//		vectorFromTree.push_back(node.Data); });
//
//	EXPECT_EQ(vectorInitialize, vectorFromTree);
//}