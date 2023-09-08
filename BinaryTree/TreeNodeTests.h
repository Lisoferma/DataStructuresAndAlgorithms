#pragma once

#include "TreeNode.h"
#include <cassert>

namespace DSAABinaryTree
{
	static class TreeNodeTests
	{
	public:
		static void TreeNode_CreateTree_DataIsEqualInitial()
		{
			TreeNode<int>* root = new TreeNode<int>(1);

			root->Left = new TreeNode<int>(2);
			root->Right = new TreeNode<int>(3);

			root->Left->Left = new TreeNode<int>(4);
			root->Left->Right = new TreeNode<int>(5);

			assert(root->Left->Left->Data == 4 && "Данные узла не совпадают с инициализованными.");
		}
	};
}


