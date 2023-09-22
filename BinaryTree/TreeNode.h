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


		// default - компилятор сделает конструктор
		TreeNode() = default;


		/// <summary>
		///	Инициализировать данные узла.
		/// </summary>
		/// <param name="data">Данные узла.</param>
		TreeNode(T data)
		{
			Data = data;
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
		TreeNode(T data, TreeNode* left, TreeNode* right)
		{
			Data = data;
			Left = left;
			Right = right;
		}


		~TreeNode()
		{
			delete Left;
			delete Right;
		}
	};
}

