//@author Lisoferma

#include <vector>
#include <stdexcept>
#include "pch.h"
#include "../../AVLTree/AVLNode.h"
#include "../../AVLTree/AVLTree.h"

using namespace DSAAVLTree;


/// <summary>
/// Получить высоту дерева.
/// </summary>
/// <typeparam name="T">Тип данных который содержит дерево.</typeparam>
/// <param name="root">Корень дерева.</param>
/// <returns>Высота дерева.</returns>
template <typename T>
int GetHeight(AVLNode<T>* root)
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
bool IsBalanced(AVLNode<T>* root)
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


TEST(Constructor, NoParameters_TreeIsEmpty)
{
    AVLTree<int> tree;

    EXPECT_TRUE(tree.IsEmpty());
}


TEST(Constructor, ParameterVector_TreeIsBalanced)
{
    std::vector<int> initData{ 10, 5, 7, -5, 1, -1, 3, 9, -10, 4, 2 };
    AVLTree<int> tree(initData);

	EXPECT_TRUE(IsBalanced(tree.GetRoot()));
}


TEST(Insert, InsertData_TreeIsBalanced)
{
    std::vector<int> insertData{ 10, 5, 7, -5, 1, -1, 3, 9, -10, 4, 2 };
    AVLTree<int> tree;

    for (int item : insertData)
        tree.Insert(item);

    EXPECT_TRUE(IsBalanced(tree.GetRoot()));
}


TEST(Insert, InsertOrderedData_TreeIsBalanced)
{
    std::vector<int> insertData{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    AVLTree<int> tree;

    for (int item : insertData)
        tree.Insert(item);

    EXPECT_TRUE(IsBalanced(tree.GetRoot()));
}


TEST(Remove, RemoveData_TreeIsBalanced)
{
    std::vector<int> initData{ 10, 5, 7, -5, 1, -1, 3, 9, -10, 4, 2 };
    AVLTree<int> tree(initData);

    tree.Remove(-5);
    tree.Remove(-1);
    tree.Remove(10);
    tree.Remove(2);
    tree.Remove(9);

    EXPECT_TRUE(IsBalanced(tree.GetRoot()));
}


TEST(Remove, RemoveAllData_TreeIsEmpty)
{
    std::vector<int> initData{ 10, 5, 7, -5, 1, -1, 3, 9, -10, 4, 2 };
    AVLTree<int> tree(initData);

    for (int item : initData)
        tree.Remove(item);

    EXPECT_TRUE(tree.IsEmpty());
}


TEST(MaxItem, GetMaxItemInFilledTree_MaxItemIsCorrect)
{
    int maxItem = 20;
    std::vector<int> initData{ 10, 5, 7, -5, 1, -1, 3, 9, -10, 4, 2 };
    AVLTree<int> tree(initData);
    tree.Insert(maxItem);

    EXPECT_EQ(tree.MaxItem(), maxItem);
}


TEST(MaxItem, GetMaxItemInEmptyTree_ShouldThrowOutOfRange)
{
    AVLTree<int> tree;

    ASSERT_THROW(tree.MaxItem(), std::out_of_range);
}


TEST(MinItem, GetMinItemInFilledTree_MinItemIsCorrect)
{
    int minItem = -20;
    std::vector<int> initData{ 10, 5, 7, -5, 1, -1, 3, 9, -10, 4, 2 };
    AVLTree<int> tree(initData);
    tree.Insert(minItem);

    EXPECT_EQ(tree.MinItem(), minItem);
}


TEST(MinItem, GetMinItemInEmptyTree_ShouldThrowOutOfRange)
{
    AVLTree<int> tree;

    ASSERT_THROW(tree.MinItem(), std::out_of_range);
}