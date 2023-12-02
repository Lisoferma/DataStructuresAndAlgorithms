// @author Lisoferma

#include <vector>
#include <stdexcept>
#include "pch.h"
#include "../Heap/Heap.h"


/// <summary>
/// Является ли заданная куча минимальной кучей.
/// </summary>
/// <typeparam name="T">Тип данных кучи</typeparam>
/// <param name="heap">Куча которую нужно проверить</param>
template <typename T>
bool IsMinHeap(const Heap<T>& heap)
{
	std::vector<T> vectorHeap;
	heap.CopyToVector(vectorHeap);
	return VectorIsMinHeap(vectorHeap, 0);
}


/// <summary>
/// Является ли заданный вектор минимальной кучей.
/// </summary>
/// <param name="vector">Вектор который нужно проверить.</param>
/// <param name="index">Индекс с которого начать проверку.</param>
/// <typeparam name="T">Тип данных который содержит вектор.</typeparam>
template <typename T>
bool VectorIsMinHeap(const std::vector<T>& vector, size_t index)
{
	if (2 * index + 2 > vector.size())
		return true;

	bool left = (vector[index] <= vector[2 * index + 1]) &&
		VectorIsMinHeap(vector, 2 * index + 1);

	bool right = (2 * index + 2 == vector.size()) ||
		(vector[index] <= vector[2 * index + 2] &&
		VectorIsMinHeap(vector, 2 * index + 2));

	return left && right;
}


TEST(Constructor, NoParameters_InitializeEmpty)
{
	Heap<int> heap;

	EXPECT_TRUE(heap.IsEmpty());
}


TEST(Constructor, ParameterVector_DataBecameHeap)
{
	std::vector<int> initVector{ 10, 5, 7, 15, 4, 200, 1 };

	Heap<int> heap(initVector);

	EXPECT_TRUE(IsMinHeap(heap));
}


TEST(Insert, Insert100Times_DataBecameHeap)
{
	Heap<int> heap;

	for (int i = 50; i > -50; --i)
		heap.Insert(i);

	EXPECT_TRUE(IsMinHeap(heap));
}


TEST(Remove, Remove3Times_DataRemainsHeap)
{
	std::vector<int> initVector{ 10, 5, 7, 15, 4, 200, 1 };
	Heap<int> heap(initVector);

	heap.Remove(5);
	heap.Remove(200);
	heap.Remove(1);

	EXPECT_TRUE(IsMinHeap(heap));
}


TEST(Remove, RemoveAllItems_HeapBecameEmpty)
{
	std::vector<int> initVector{ 10, 5, 7, 15, 4, 200, 1 };
	Heap<int> heap(initVector);

	heap.Remove(5);
	heap.Remove(200);
	heap.Remove(1);
	heap.Remove(10);
	heap.Remove(7);
	heap.Remove(15);
	heap.Remove(4);

	EXPECT_TRUE(heap.IsEmpty());
}


TEST(Remove, RemoveNonExistentItem_ShouldThrowOutOfRange)
{
	std::vector<int> initVector{ 10, 5, 7, 15, 4, 200, 1 };
	Heap<int> heap(initVector);

	ASSERT_THROW(heap.Remove(999), std::out_of_range);
}


TEST(Top, GetTopItemInFilledHeap_ItemIsMinimal)
{
	std::vector<int> initVector{ 10, 5, 7, 15, -4, 200, -1, 3 };
	Heap<int> heap(initVector);
	int minimalItemExpected = -5;
	heap.Insert(minimalItemExpected);

	EXPECT_EQ(minimalItemExpected, heap.Top());
}


TEST(Top, GetTopItemInEmptyHeap_ShouldThrowOutOfRange)
{
	Heap<int> emptyHeap;

	ASSERT_THROW(emptyHeap.Top(), std::out_of_range);
}


TEST(Pop, PopInFilledHeap_DataRemainsHeap)
{
	std::vector<int> initVector{ 10, 5, 7, 15, 4, 200, 12 };
	Heap<int> heap(initVector);

	heap.Pop();

	EXPECT_TRUE(IsMinHeap(heap));
}


TEST(Pop, PopInEmptyHeap_ShouldThrowOutOfRange)
{
	Heap<int> emptyHeap;

	ASSERT_THROW(emptyHeap.Pop(), std::out_of_range);
}


TEST(CopyToVector, CopyFilledHeapToVector_VectorIsHeap)
{
	std::vector<int> initVector{ 10, 5, 7, 15, 4, 200, 12 };
	Heap<int> heap(initVector);

	EXPECT_TRUE(IsMinHeap(heap));
}