//@author Lisoferma

#pragma once

namespace DSAABinaryTree
{
	/// <summary>
	///	Узел бинарного дерева.
	/// </summary>
	/// <typeparam name="T">
	///	Тип данных который хранит узел.
	/// </typeparam>
	template<typename T>
	class TreeNode
	{
	public:
		// Данные узла
		T Data;

		/// <summary>
		/// Указатель на дочерний левый узел.
		/// </summary>
		TreeNode* Left;
 
		/// <summary>
		/// Указатель на дочерний правый узел.
		/// </summary>
		TreeNode* Right;

		/// <summary>
		/// Указатель на родительский узел.
		/// </summary>
		TreeNode* Parent;


		TreeNode() = default;


		/// <summary>
		///	Инициализировать данные узла.
		/// </summary>
		/// <param name="data">Данные узла.</param>
		TreeNode(const T& data)
		{
			Data = data;
			Left = nullptr;
			Right = nullptr;
			Parent = nullptr;
		}


		/// <summary>
		/// Инициализировать узел всеми данными.
		/// </summary>
		/// <param name="data">Данные которые хранит узел.</param>
		/// <param name="left">Дочерний левый узел.</param>
		/// <param name="right">Дочерний правый узел.</param>
		/// <param name="parent">Родительский узел.</param>
		TreeNode(const T& data, TreeNode* left, TreeNode* right, TreeNode* parent)
			: Data(data), Left(left), Right(right), Parent(parent)
		{ }


		~TreeNode()
		{
			delete Left;
			delete Right;
		}
	};
}

