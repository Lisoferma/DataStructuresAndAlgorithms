#pragma once

namespace DSAList
{
	/// <summary>
	/// Узел односвязного списка.
	/// </summary>
	/// <typeparam name="T">Тип данных который хранит узел.</typeparam>
	template <typename T>
	struct Node
	{
		/// <summary>
		/// Данные которые хранит узел.
		/// </summary>
		T Data;

		/// <summary>
		/// Указатель на следующий в списке узел.
		/// </summary>
		Node<T>* Next;


		/// <summary>
		/// Инициализировать узел данными.
		/// </summary>
		/// <param name="data">Данные которые хранит узел.</param>
		Node(const T& data) : Data(data), Next(nullptr)
		{ }


		/// <summary>
		/// Инициализировать узел данными и указателем на следующий узел.
		/// </summary>
		/// <param name="data">Данные которые хранит узел.</param>
		/// <param name="next">Указатель на следующий узел.</param>
		Node(const T& data, Node<T>* next) : Data(data), Next(next)
		{ }
	};
}