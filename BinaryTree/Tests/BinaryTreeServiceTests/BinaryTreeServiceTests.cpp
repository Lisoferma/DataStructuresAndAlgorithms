// @author Lisoferma

#include <vector>
#include <algorithm>
#include "pch.h"
#include "../../BinaryTree/BinaryNode.h"
#include "../../BinaryTree/BinaryTreeService.h"


using namespace std;
using namespace DSAABinaryTree;
using namespace BinaryTreeService;


/// <summary>
/// Получить высоту дерева.
/// </summary>
/// <typeparam name="T">Тип данных который содержит дерево.</typeparam>
/// <param name="root">Корень дерева.</param>
/// <returns>Высота дерева.</returns>
template <typename T>
int GetHeight(BinaryNode<T>* root)
{
	if (root == nullptr)
		return 0;

	return 1 + std::max(GetHeight(root->GetLeft()), GetHeight(root->GetRight()));
}


/// <summary>
/// Является ли бинарное дерево сбалансированным.
/// </summary>
/// <typeparam name="T">Тип данных который хранит дерево.</typeparam>
/// <param name="root">Корень дерева.</param>
/// <returns>True - сбалансировано, false - несбалансировано.</returns>
template <typename T>
bool IsBalanced(BinaryNode<T>* root)
{
	int leftHeight;
	int rightHeight;

	if (root == nullptr)
		return true;

	leftHeight = GetHeight(root->GetLeft());
	rightHeight = GetHeight(root->GetRight());

	if (abs(leftHeight - rightHeight) <= 1
		&& IsBalanced(root->GetLeft())
		&& IsBalanced(root->GetRight()))
	{
		return true;
	}

	return false;
}


/// <summary>
/// Наполненное данными дерево.
/// </summary>
class FilledTree : public::testing::Test
{
public:
	// Количество узлов которое содержит дерево
	const int NODES = 5;

	// Высота дерева
	const int HEIGHT = 3;

	// Данные которыми инициализируется дерево
	const vector<int> INIT_DATA{ 6, 4, 7, 3, 5 };

	// Корень дерева
	BinaryNode<int>* root;


	// Созданное дерево:
	//           6
	//          / \
	//         4   7
	//        / \
	//       3   5
	void SetUp()
	{
		root = new BinaryNode<int>(INIT_DATA[0]);
		root->Left = new BinaryNode<int>(INIT_DATA[1]);
		root->Right = new BinaryNode<int>(INIT_DATA[2]);
		root->Left->Left = new BinaryNode<int>(INIT_DATA[3]);
		root->Left->Right = new BinaryNode<int>(INIT_DATA[4]);
	}
};


/// <summary>
/// Вырожденное дерево.
/// </summary>
class DegenerateTree : public::testing::Test
{
public:
	// Количество узлов которое содержит дерево
	const int NODES = 5;

	// Высота дерева
	const int HEIGHT = 5;

	// Данные которыми инициализируется дерево
	const vector<int> INIT_DATA{ 1, 2, 3, 4, 5 };

	// Корень дерева
	BinaryNode<int>* root;


	// Созданное дерево:
	// 1
	//  \
	//   2
	//    \
	//     3
	//      \
	//       4
	//        \
	//         5
	void SetUp()
	{
		root = new BinaryNode<int>(INIT_DATA[0]);
		root->Right = new BinaryNode<int>(INIT_DATA[1]);
		root->Right->Right = new BinaryNode<int>(INIT_DATA[2]);
		root->Right->Right->Right = new BinaryNode<int>(INIT_DATA[3]);
		root->Right->Right->Right->Right = new BinaryNode<int>(INIT_DATA[4]);
	}
};


/// <summary>
/// Дерево имеющее только корень.
/// </summary>
class StumpTree : public::testing::Test
{
public:
	// Количество узлов которое содержит дерево
	const int NODES = 1;

	// Высота дерева
	const int HEIGHT = 1;

	// Данные которыми инициализируется дерево
	const int INIT_DATA = 1;

	// Корень дерева
	BinaryNode<int>* root;


	// Созданное дерево:
	//   1
	//  / \
	//
	void SetUp()
	{
		root = new BinaryNode<int>(INIT_DATA);
	}
};


/// <summary>
/// Пустое дерево.
/// </summary>
class EmptyTree : public::testing::Test
{
public:
	// Количество узлов которое содержит дерево
	const int NODES = 0;

	// Высота дерева
	const int HEIGHT = 0;

	// Корень дерева
	BinaryNode<int>* root;

	void SetUp()
	{
		root = nullptr;
	}
};


TEST_F(FilledTree, ToVector_GetVectorByInorderTreversal_VectorDataSameTreeData)
{
	vector<int> expectedVector{ 3, 4, 5, 6, 7 };
	vector<int> resultVector;

	ToVector(root, resultVector);

	EXPECT_EQ(expectedVector.size(), resultVector.size());

	for (int i = 0; i < expectedVector.size(); ++i)
	{
		EXPECT_EQ(resultVector[i], expectedVector[i]);
	}
}


TEST_F(DegenerateTree, ToVector_GetVectorByInorderTreversal_VectorDataSameTreeData)
{
	vector<int> resultVector;

	ToVector(root, resultVector);

	EXPECT_EQ(INIT_DATA.size(), resultVector.size());

	for (int i = 0; i < INIT_DATA.size(); ++i)
	{
		EXPECT_EQ(resultVector[i], INIT_DATA[i]);
	}
}


TEST_F(StumpTree, ToVector_GetVectorByInorderTreversal_VectorDataSameTreeData)
{
	vector<int> resultVector;

	ToVector(root, resultVector);

	EXPECT_EQ(resultVector.size(), 1);
	EXPECT_EQ(resultVector[0], INIT_DATA);
}


TEST_F(EmptyTree, ToVector_GetVectorByInorderTreversal_VectorIsEmpty)
{
	vector<int> resultVector;

	ToVector(root, resultVector);

	EXPECT_TRUE(resultVector.empty());
}


TEST_F(FilledTree, NodeCount_GetNodeCount_NodeCountIsCorrect)
{
	EXPECT_EQ(NodeCount(root), NODES);
}


TEST_F(DegenerateTree, NodeCount_GetNodeCount_NodeCountIsCorrect)
{
	EXPECT_EQ(NodeCount(root), NODES);
}


TEST_F(StumpTree, NodeCount_GetNodeCount_NodeCountIsCorrect)
{
	EXPECT_EQ(NodeCount(root), NODES);
}


TEST_F(EmptyTree, NodeCount_GetNodeCount_NodeCountIsCorrect)
{
	EXPECT_EQ(NodeCount(root), NODES);
}


TEST_F(FilledTree, TreeHeight_GetTreeHeight_TreeHeightIsCorrect)
{
	EXPECT_EQ(TreeHeight(root), HEIGHT);
}


TEST_F(DegenerateTree, TreeHeight_GetTreeHeight_TreeHeightIsCorrect)
{
	EXPECT_EQ(TreeHeight(root), HEIGHT);
}


TEST_F(StumpTree, TreeHeight_GetTreeHeight_TreeHeightIsCorrect)
{
	EXPECT_EQ(TreeHeight(root), HEIGHT);
}


TEST_F(EmptyTree, TreeHeight_GetTreeHeight_TreeHeightIsCorrect)
{
	EXPECT_EQ(TreeHeight(root), HEIGHT);
}


TEST_F(FilledTree, Search_SearchExistingItem_ResultSearchedItem)
{
	int searchedItem = 5;

	int result = Search(root, searchedItem)->Data;

	EXPECT_EQ(result, searchedItem);
}


TEST_F(FilledTree, Search_SearchNonExistingItem_ResultNullptr)
{
	EXPECT_EQ(Search(root, 100), nullptr);
}


TEST_F(DegenerateTree, Search_SearchExistingItem_ResultSearchedItem)
{
	int searchedItem = 5;

	int result = Search(root, searchedItem)->Data;

	EXPECT_EQ(result, searchedItem);
}


TEST_F(DegenerateTree, Search_SearchNonExistingItem_ResultNullptr)
{
	EXPECT_EQ(Search(root, 100), nullptr);
}


TEST_F(StumpTree, Search_SearchExistingItem_ResultSearchedItem)
{
	int searchedItem = 1;

	int result = Search(root, searchedItem)->Data;

	EXPECT_EQ(result, searchedItem);
}


TEST_F(StumpTree, Search_SearchNonExistingItem_ResultNullptr)
{
	EXPECT_EQ(Search(root, 100), nullptr);
}


TEST_F(EmptyTree, Search_SearchNonExistingItem_ResultNullptr)
{
	EXPECT_EQ(Search(root, 100), nullptr);
}


TEST_F(FilledTree, Insert_InsertBiggestItem_AllItemsInExpectedPositions)
{
	vector<int> expectedData{ 3, 4, 5, 6, 7, 10 };

	Insert(root, 10);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedData.size(), resultData.size());

	for (int i = 0; i < expectedData.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedData[i]);
	}
}


TEST_F(FilledTree, Insert_InsertSmallestItem_AllItemsInExpectedPositions)
{
	vector<int> expectedData{ 1, 3, 4, 5, 6, 7 };

	Insert(root, 1);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedData.size(), resultData.size());

	for (int i = 0; i < expectedData.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedData[i]);
	}
}


TEST_F(DegenerateTree, Insert_InsertBiggestItem_AllItemsInExpectedPositions)
{
	vector<int> expectedData{ 1, 2, 3, 4, 5, 10 };

	Insert(root, 10);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedData.size(), resultData.size());

	for (int i = 0; i < expectedData.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedData[i]);
	}
}


TEST_F(DegenerateTree, Insert_InsertSmallestItem_AllItemsInExpectedPositions)
{
	vector<int> expectedData{ 0, 1, 2, 3, 4, 5 };

	Insert(root, 0);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedData.size(), resultData.size());

	for (int i = 0; i < expectedData.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedData[i]);
	}
}


TEST_F(StumpTree, Insert_InsertBiggestItem_AllItemsInExpectedPositions)
{
	vector<int> expectedData{ 1, 2 };

	Insert(root, 2);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedData.size(), resultData.size());

	for (int i = 0; i < expectedData.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedData[i]);
	}
}


TEST_F(StumpTree, Insert_InsertSmallestItem_AllItemsInExpectedPositions)
{
	vector<int> expectedData{ 0, 1 };

	Insert(root, 0);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedData.size(), resultData.size());

	for (int i = 0; i < expectedData.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedData[i]);
	}
}


TEST_F(EmptyTree, Insert_InsertSomeItem_DataIsSearchTree)
{
	const vector<int> initData{ 6, 4, 7, 3, 5 };

	for (auto item : initData)
		Insert(root, item);

	EXPECT_EQ(root->Data, 6);
	EXPECT_EQ(root->Right->Data, 7);
	EXPECT_EQ(root->Left->Data, 4);
	EXPECT_EQ(root->Left->Left->Data, 3);
	EXPECT_EQ(root->Left->Right->Data, 5);
}


TEST_F(FilledTree, Successor_GetSuccessorForExistingItems_ReturnCorrect)
{
	EXPECT_EQ(Successor(root, 6)->Data, 7);
	EXPECT_EQ(Successor(root, 5)->Data, 6);
	EXPECT_EQ(Successor(root, 4)->Data, 5);
	EXPECT_EQ(Successor(root, 3)->Data, 4);
}


TEST_F(FilledTree, Successor_GetSuccessorForNonExistingItem_ReturnNullptr)
{
	EXPECT_EQ(Successor(root, 100), nullptr);
}


TEST_F(FilledTree, Successor_GetSuccessorForBiggestItem_ReturnNullptr)
{
	EXPECT_EQ(Successor(root, 7), nullptr);
}


TEST_F(DegenerateTree, Successor_GetSuccessorForExistingItems_ReturnCorrect)
{
	EXPECT_EQ(Successor(root, 4)->Data, 5);
}


TEST_F(StumpTree, Successor_GetSuccessorForExistingItems_ReturnNullptr)
{
	EXPECT_EQ(Successor(root, 1), nullptr);
}


TEST_F(EmptyTree, Successor_GetSuccessorForNonExistingItems_ReturnNullptr)
{
	EXPECT_EQ(Successor(root, 100), nullptr);
}


TEST_F(FilledTree, Remove_RemoveExistingItems_OtherItemsStill)
{
	vector<int> expectedResult{ 3, 6, 7 };

	Remove(root, 4);
	Remove(root, 5);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedResult.size(), resultData.size());

	for (int i = 0; i < expectedResult.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedResult[i]);
	}
}


TEST_F(FilledTree, Remove_RemoveNonExistingItems_AllItemsStill)
{
	vector<int> expectedResult{ 3, 4, 5, 6, 7 };

	Remove(root, 100);

	vector<int> resultData;
	ToVector(root, resultData);

	EXPECT_EQ(expectedResult.size(), resultData.size());

	for (int i = 0; i < expectedResult.size(); ++i)
	{
		EXPECT_EQ(resultData[i], expectedResult[i]);
	}
}


TEST_F(FilledTree, Remove_RemoveAllItems_TreeIsEmpty)
{
	for (auto item : INIT_DATA)
		Remove(root, item);

	EXPECT_EQ(root, nullptr);
}


TEST_F(EmptyTree, Remove_RemoveNonExistingItem_TreeStillEmpty)
{
	Remove(root, 100);

	EXPECT_EQ(root, nullptr);
}