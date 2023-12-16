//@author Lisoferma

#pragma once

#include "../BinaryTree/BinaryNode.h"

using namespace DSAABinaryTree;

namespace DSAAVLTree
{
	/// <summary>
	///	Узел АВЛ-дерева.
	/// </summary>
	/// <typeparam name="T">
	///	Тип данных который хранит узел.
	/// </typeparam>
	template<typename T>
	struct AVLNode : BinaryNode<T>
	{
		/// <summary>
		/// Высота поддерева с корнем в данном узле.
		/// </summary>
		unsigned char Height;


		/// <summary>
		/// Инициализирует узел с высотой равной 1.
		/// </summary>
		AVLNode() : Height(1)
		{ }


		/// <summary>
		/// Инициализирует узел с высотой равной 1.
		/// </summary>
		AVLNode(const T& data) : BinaryNode<T>(data)
		{
			Height = 1;
		}


		AVLNode<T>* GetLeft()
		{
			return static_cast<AVLNode<T>*>(this->Left);
		}


		AVLNode<T>* GetRight()
		{
			return static_cast<AVLNode<T>*>(this->Right);
		}
	};
}