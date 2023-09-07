#pragma once

namespace DSAABinaryTree
{
	/// <summary>
	///	���� ��������� ������.
	/// </summary>
	/// <typeparam name="T">
	///	��� ������ ������� ������ ����.
	/// </typeparam>
	template<typename T>
	class TreeNode
	{
	public:
		// ������ ����
		T Data;

		// ��������� �� ������������ ����
		TreeNode* Parent;

		// ��������� �� �������� ����� ����
		TreeNode* Left;

		// ��������� �� �������� ������ ����
		TreeNode* Right;


		/// <summary>
		///	���������������� ������ ����.
		/// </summary>
		/// <param name="data">������ ����.</param>
		TreeNode(T data)
		{
			Data = data;
			Parent = nullptr;
			Left = nullptr;
			Right = nullptr;
		}


		/// <summary>
		///	���������������� ��� ���� ����.
		/// </summary>
		/// <param name="data">������ ����.</param>
		/// <param name="parent">��������� �� ������������ ����.</param>
		/// <param name="left">��������� �� ����� ����.</param>
		/// <param name="right">��������� �� ������ ����.</param>
		TreeNode(T data, TreeNode* parent, TreeNode* left, TreeNode* right)
		{
			Data = data;
			Parent = parent;
			Left = left;
			Right = right;
		}


		~TreeNode()
		{
			delete Left;
			delete Right;
		}
	};
}  // namespace DSAABinaryTree

