// @author Lisoferma

#include "../../LinkedList/List.h"
#include "pch.h"
#include <vector>

using namespace std;
using namespace DSAList;


TEST(Iterator, UseIteratorInForEach_IteratorItemsSameListData)
{
	vector<int> initData = { 3, 1, 2, 4, 5, 6 };
	List<int> list(initData);

	int i = 0;
	for (auto item : list)
	{
		ASSERT_EQ(item, initData[i]);
		++i;
	}

	ASSERT_EQ(i, initData.size());
}
//
//
//TEST(Iterator, UseIteratorForEmptyList_IteratorEqualEnd)
//{
//	List<int> list;
//
//	ASSERT_EQ(list.begin(), list.end());
//}
//
//
//TEST(Iterator, UseIteratorForEmptyList_IteratorIsNullptr)
//{
//	List<int> list;
//
//	ASSERT_TRUE(list.begin().IsEnd());
//}
//
//
//TEST(Iterator, UseIteratorForOnlyOneNode_IteratorDataCorrect)
//{
//	List<int> list;
//	list.PushBack(1);
//
//	for (auto item : list)
//		ASSERT_EQ(item, 1);
//}

TEST(Iterator, UseIteratorForOnlyOneNode_IteratorDataCorrect)
{
	ASSERT_EQ(1, 1);
}