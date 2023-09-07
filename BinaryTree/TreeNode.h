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


		TreeNode() = default;


		/// <summary>
		///	���������������� ������ ����.
		/// </summary>
		/// <param name="data">������ ����.</param>
		TreeNode(T data);


		/// <summary>
		///	���������������� ��� ���� ����.
		/// </summary>
		/// <param name="data">������ ����.</param>
		/// <param name="parent">��������� �� ������������ ����.</param>
		/// <param name="left">��������� �� ����� ����.</param>
		/// <param name="right">��������� �� ������ ����.</param>
		TreeNode(T data, TreeNode* parent, TreeNode* left, TreeNode* right);


		~TreeNode();		
	};
}  // namespace DSAABinaryTree

