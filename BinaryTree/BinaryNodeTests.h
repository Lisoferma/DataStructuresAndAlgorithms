//@author Lisoferma

#pragma once

#include "BinaryNode.h"
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
			BinaryNode<int>* root = CreateBinareTree();

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
		static BinaryNode<int>* CreateBinareTree()
		{
			BinaryNode<int>* root = new BinaryNode<int>(1);

			root->Left = new BinaryNode<int>(2);
			root->Right = new BinaryNode<int>(3);

			root->Left->Left = new BinaryNode<int>(4);
			root->Left->Right = new BinaryNode<int>(5);

			return root;
		}
	};
}


