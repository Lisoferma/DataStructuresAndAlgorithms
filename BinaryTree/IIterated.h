#pragma once

#include "IIterator.h"

namespace DSAABinaryTree
{
	template<typename T>
	class IIterated
	{
		virtual IIterator<T>& begin() = 0;

		virtual IIterator<T>& end() = 0;
	};
}