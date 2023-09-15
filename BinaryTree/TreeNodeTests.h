#pragma once

#include "TreeNode.h"
//@author Alexander

#include <cassert>

namespace DSAABinaryTree
{
	/// <summary>
	/// Unit test для класса TreeNode.
	/// </summary>
	class TreeNodeTests
	{
	public:
		/// <summary>
		/// Тест создания бинарного дерева из TreeNode.
		/// Данные в дереве должны совпадать с инициализованными.
		/// </summary>
		static void TreeNode_CreateTree_DataIsEqualInitial()
		{
			TreeNode<int>* root = CreateBinareTree();

			assert(root->Data              == 1 && "Данные узла не совпадают с инициализованными.");
			assert(root->Left->Data        == 2 && "Данные узла не совпадают с инициализованными.");
			assert(root->Right->Data       == 3 && "Данные узла не совпадают с инициализованными.");
			assert(root->Left->Left->Data  == 4 && "Данные узла не совпадают с инициализованными.");
			assert(root->Left->Right->Data == 5 && "Данные узла не совпадают с инициализованными.");
		}

	private:
		/// <summary>
		/// Создать бинарное дерево для теста.
		/// </summary>
		/// <returns>Указатель на корень.</returns>
		static TreeNode<int>* CreateBinareTree()
		{
			TreeNode<int>* root = new TreeNode<int>(1);

			root->Left = new TreeNode<int>(2);
			root->Right = new TreeNode<int>(3);

			root->Left->Left = new TreeNode<int>(4);
			root->Left->Right = new TreeNode<int>(5);

			return root;
		}
	};
}


