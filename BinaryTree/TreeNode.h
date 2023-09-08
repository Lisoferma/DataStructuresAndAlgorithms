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

		// Указатель на родительский узел
		TreeNode* Parent;

		// Указатель на дочерний левый узел
		TreeNode* Left;

		// Указатель на дочерний правый узел
		TreeNode* Right;


		// default - компилятор сделает конструктор
		TreeNode() = default;


		/// <summary>
		///	Инициализировать данные узла.
		/// </summary>
		/// <param name="data">Данные узла.</param>
		TreeNode(T data)
		{
			Data = data;
			Parent = nullptr;
			Left = nullptr;
			Right = nullptr;
		}


		/// <summary>
		///	Инициализировать все поля узла.
		/// </summary>
		/// <param name="data">Данные узла.</param>
		/// <param name="parent">Указатель на родительский узел.</param>
		/// <param name="left">Указатель на левый узел.</param>
		/// <param name="right">Указатель на правый узел.</param>
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

