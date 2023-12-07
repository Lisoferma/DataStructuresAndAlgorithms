// @author Lisoferma

#include <vector>
#include "pch.h"
#include "../Sort/Sort.h"

TEST(HeapSort, SortFilledVector_VectorBecameSort)
{
	std::vector<int> vector{ 12, 11, 13, 5, 6, 7, 20, -5, -6, 0 };

	HeapSort(vector);

	for (int i = 0; i < vector.size() - 1; ++i)
		EXPECT_TRUE(vector[i] <= vector[i + 1]);
}