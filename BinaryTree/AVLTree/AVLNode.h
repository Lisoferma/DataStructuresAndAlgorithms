//@author Lisoferma

#pragma once

#include "../BinaryTree/BinaryNode.h"

using namespace DSAABinaryTree;

namespace DSAAVLTree
{
	/// <summary>
	///	���� ���-������.
	/// </summary>
	/// <typeparam name="T">
	///	��� ������ ������� ������ ����.
	/// </typeparam>
	template<typename T>
	struct AVLNode : BinaryNode<T>
	{
		/// <summary>
		/// ������ ��������� � ������ � ������ ����.
		/// </summary>
		unsigned char Height;


		/// <summary>
		/// �������������� ���� � ������� ������ 1.
		/// </summary>
		AVLNode() : Height(1)
		{ }


		/// <summary>
		/// �������������� ���� � ������� ������ 1.
		/// </summary>
		AVLNode(const T& data) : BinaryNode<T>(data)
		{
			Height = 1;
		}
	};
}