// @author Lisoferma

#pragma once

#include "IIterator.h"

namespace DSAList
{
	/// <summary>
	/// Предоставляет методы для доступа к итератору.
	/// </summary>
	/// <typeparam name="T">Тип данных итерируемой коллекции.</typeparam>
	template<typename T>
	class IIterated
	{
		/// <summary>
		/// Получить итератор в начале коллекции.
		/// </summary>
		virtual IIterator<T>& begin() = 0;

		/// <summary>
		/// Получить итератор в конце коллекции.
		/// </summary>
		virtual IIterator<T>& end() = 0;
	};
}