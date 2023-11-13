//@author Lisoferma

#pragma once

#include "IIterator.h"

namespace DSAABinaryTree
{
	/// <summary>
	/// ������������� ������ ��� ������� � ���������.
	/// </summary>
	/// <typeparam name="T">��� ������ ����������� ���������.</typeparam>
	template<typename T>
	class IIterated
	{
		/// <summary>
		/// �������� �������� � ������ ���������.
		/// </summary>
		virtual IIterator<T>& begin() = 0;

		/// <summary>
		/// �������� �������� � ����� ���������.
		/// </summary>
		virtual IIterator<T>& end() = 0;
	};
}