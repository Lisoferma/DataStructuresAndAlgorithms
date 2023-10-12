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
	struct BinaryNode
	{
		// Данные узла
		T Data;

		/// <summary>
		/// Указатель на дочерний левый узел.
		/// </summary>
		BinaryNode* Left;
 
		/// <summary>
		/// Указатель на дочерний правый узел.
		/// </summary>
		BinaryNode* Right;

		/// <summary>
		/// Указатель на родительский узел.
		/// </summary>
		BinaryNode* Parent;


		BinaryNode() = default;


		/// <summary>
		///	Инициализировать данные узла.
		/// </summary>
		/// <param name="data">Данные узла.</param>
		BinaryNode(const T& data)
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
		BinaryNode(const T& data, BinaryNode* left, BinaryNode* right, BinaryNode* parent)
			: Data(data), Left(left), Right(right), Parent(parent)
		{ }
	};
}

