#pragma once

namespace DSAList
{
	/// <summary>
	/// ���� ������������ ������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������� ������ ����.</typeparam>
	template <typename T>
	struct Node
	{
		/// <summary>
		/// ������ ������� ������ ����.
		/// </summary>
		T Data;

		/// <summary>
		/// ��������� �� ��������� � ������ ����.
		/// </summary>
		Node<T>* Next;


		/// <summary>
		/// ���������������� ���� �������.
		/// </summary>
		/// <param name="data">������ ������� ������ ����.</param>
		Node(const T& data) : Data(data), Next(nullptr)
		{ }


		/// <summary>
		/// ���������������� ���� ������� � ���������� �� ��������� ����.
		/// </summary>
		/// <param name="data">������ ������� ������ ����.</param>
		/// <param name="next">��������� �� ��������� ����.</param>
		Node(const T& data, Node<T>* next) : Data(data), Next(next)
		{ }
	};
}