#include "TreeNode.h"

namespace DSAABinaryTree
{
	/// <summary>
	///	���������������� ������ ����.
	/// </summary>
	/// <param name="data">������ ����.</param>
	template<typename T>
	TreeNode<T>::TreeNode(T data)
	{
		Data = data;
		Parent = nullptr;
		Left = nullptr;
		Right = nullptr;
	}


	/// <summary>
	///	���������������� ������ ���� � ��������� �� ������������ � �������� ����.
	/// </summary>
	/// <param name="data">������ ����.</param>
	/// <param name="parent">��������� �� ������������ ����.</param>
	/// <param name="left">��������� �� ����� ����.</param>
	/// <param name="right">��������� �� ������ ����.</param>
	template<typename T>
	TreeNode<T>::TreeNode(T data, TreeNode* parent, TreeNode* left, TreeNode* right)
	{
		Data = data;
		Parent = parent;
		Left = left;
		Right = right;
	}


	template <typename T>
	TreeNode<T>::~TreeNode()
	{
		delete Left;
		delete Right;
	}
}  // namespace DSAABinaryTree
