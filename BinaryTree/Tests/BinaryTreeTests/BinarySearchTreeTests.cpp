// @author Lisoferma

#include <vector>
#include <algorithm>
#include "pch.h"
#include "../../BinaryTree/BinarySearchTree.h"
#include "../../BinaryTree/BinaryTreeService.h"

using namespace std;
using namespace DSAABinaryTree;

TEST(Constructor, NoArguments_InitializeNullptr)
{
	BinarySearchTree<int> bst;

	EXPECT_EQ(bst.GetRoot(), nullptr);
}


TEST(Constructor, ArgumentRoot_InitializeRoot)
{
	BinaryNode<int>* initializeRoot = new BinaryNode<int>(5);
	BinarySearchTree<int> bst(initializeRoot);

	EXPECT_EQ(bst.GetRoot(), initializeRoot);
}


TEST(Constructor, ArgumentVector_InitializeTreeFromVector)
{
	vector<int> initData = { 3, 1, 2, 4, 5, 6 };
	BinarySearchTree<int> bst(initData);

	vector<int> resultData;
	bst.ToVector(resultData);

	EXPECT_EQ(resultData.size(), initData.size());

	for (auto resultItem : resultData)
	{
		auto result = find(begin(initData), end(initData), resultItem);
		EXPECT_FALSE(result == end(initData));
	}
}


TEST(Insert, InsertSomeData_AllDataInTree)
{
	vector<int> insertData = { 3, 1, 2, 4, 5, 6 };
	BinarySearchTree<int> bst;

	for (auto insertItem : insertData)
	{
		bst.Insert(insertItem);
	}

	vector<int> resultData;
	bst.ToVector(resultData);

	EXPECT_EQ(resultData.size(), insertData.size());

	for (auto resultItem : resultData)
	{
		auto result = find(begin(insertData), end(insertData), resultItem);
		EXPECT_FALSE(result == end(insertData));
	}
}


TEST(Remove, RemoveSomeData_DeletedDataNotInTreeOtherStill)
{
	vector<char> initData{ 'a', 'b', 'c', 'd', 'e', 'f' };
	vector<char> expectedAfterDelete{ 'a', 'c', 'f' };
	BinarySearchTree<char> bst(initData);

	bst.Remove('b');
	bst.Remove('d');
	bst.Remove('e');

	vector<char> resultData;
	bst.ToVector(resultData);

	EXPECT_EQ(expectedAfterDelete.size(), resultData.size());

	for (auto resultItem : resultData)
	{
		auto result = find(begin(expectedAfterDelete), end(expectedAfterDelete), resultItem);
		EXPECT_FALSE(result == end(expectedAfterDelete));
	}
}


TEST(Remove, RemoveNonExistingData_TreeDataNotChanged)
{
	vector<char> initData{ 'b', 'c', 'a', 'd', 'e', 'f' };
	BinarySearchTree<char> bst(initData);

	bst.Remove('O');

	vector<char> resultData;
	bst.ToVector(resultData);

	EXPECT_EQ(initData.size(), resultData.size());

	for (auto resultItem : resultData)
	{
		auto result = find(begin(initData), end(initData), resultItem);
		EXPECT_FALSE(result == end(initData));
	}
}


TEST(Remove, TreeHaveOnlyRootRemoveRoot_TreeIsEmpty)
{
	int rootData = 5;
	BinarySearchTree<int> bst;
	bst.Insert(rootData);

	bst.Remove(rootData);

	EXPECT_TRUE(bst.IsEmpty());
}


TEST(Remove, TreeIsEmptyRemoveItem_TreeIsEmpty)
{
	BinarySearchTree<int> bst;

	bst.Remove(5);

	EXPECT_TRUE(bst.IsEmpty());
}


TEST(Search, SearchExistingItem_ResultItemIsCorrect)
{
	char searchData = 'd';
	vector<char> initData{ 'b', 'c', 'a', 'd', 'e', 'f' };
	BinarySearchTree<char> bst(initData);

	BinaryNode<char>* result = bst.Search(searchData);

	EXPECT_EQ(result->Data, searchData);
}


TEST(Search, SearchNonExistingItem_ResultNullptr)
{
	vector<char> initData{ 'b', 'c', 'a', 'd', 'e', 'f' };
	BinarySearchTree<char> bst(initData);

	BinaryNode<char>* result = bst.Search('O');

	EXPECT_EQ(result, nullptr);
}


TEST(Search, SearchInEmptyTree_ReturnNullptr)
{
	BinarySearchTree<int> tree;

	EXPECT_EQ(tree.Search(100), nullptr);
}


TEST(MaxItem, GetMaxItemInFilledTree_MaxItemIsCorrect)
{
	int expectedMaxItem = 10;
	vector<int> initData = { 3, 1, 2, 4, 5, 6 };
	BinarySearchTree<int> bst(initData);
	bst.Insert(expectedMaxItem);

	int result = bst.MaxItem();

	EXPECT_EQ(result, expectedMaxItem);
}


TEST(MaxItem, GetMaxItemInEmptyTree_ShouldThrowOutOfRange)
{
	BinarySearchTree<int> bst;

	ASSERT_THROW(bst.MaxItem(), std::out_of_range);
}


TEST(MinItem, GetMinItemInFilledTree_MinItemIsCorrect)
{
	int expectedMinItem = -5;
	vector<int> initData = { 3, 1, 2, 4, 5, 6 };
	BinarySearchTree<int> bst(initData);
	bst.Insert(expectedMinItem);

	int result = bst.MinItem();

	EXPECT_EQ(result, expectedMinItem);
}


TEST(MinItem, GetMinItemInEmptyTree_ShouldThrowOutOfRange)
{
	BinarySearchTree<int> bst;

	ASSERT_THROW(bst.MinItem(), std::out_of_range);
}


TEST(Iterator, UseIteratorInForEach_IteratorItemsSameInorderTreversal)
{
	vector<int> initData = { 3, 1, 2, 4, 5, 6 };
	BinarySearchTree<int> bst(initData);

	vector<int> inorderTreversal;
	bst.ToVector(inorderTreversal);

	int i = 0;
	for (auto item : bst)
	{
		ASSERT_EQ(item, inorderTreversal[i]);
		++i;
	}
}


TEST(Iterator, UseIteratorForEmptyTree_IteratorEqualEnd)
{
	BinarySearchTree<int> bst;

	ASSERT_EQ(bst.begin(), bst.end());
}


TEST(Iterator, UseIteratorForEmptyTree_IteratorIsNullptr)
{
	BinarySearchTree<int> bst;

	ASSERT_TRUE(bst.begin().IsEnd());
}


TEST(Iterator, UseIteratorForOnlyOneNode_ReturnCorrect)
{
	vector<int> initData = { 1 };
	BinarySearchTree<int> bst(initData);

	for (auto item : bst)
		ASSERT_EQ(item, 1);
}
