#include "TreeNode.h"
#include "TreeNodeTests.h"
#include <iostream>
#include <iomanip>


using namespace std;
using namespace DSAABinaryTree;


template <typename T>
void TreePrint(TreeNode<T>* root)
{
    if (root == nullptr) return;

    cout << root->Data << endl;
    TreePrint(root->Left);
    TreePrint(root->Right);
}


/// <summary>
/// Создать бинарное дерево.
/// </summary>
/// <returns>Указатель на корень.</returns>
TreeNode<int>* CreateBinareTree()
{
    TreeNode<int>* root = new TreeNode<int>(1);

    root->Left = new TreeNode<int>(2);
    root->Right = new TreeNode<int>(3);

    root->Left->Left = new TreeNode<int>(4);
    root->Left->Right = new TreeNode<int>(5);

    return root;
}


int main()
{
    TreeNodeTests::TreeNode_CreateTree_DataIsEqualInitial();

    TreeNode<int>* root = new TreeNode<int>(1);

    root->Left = new TreeNode<int>(2);
    root->Right = new TreeNode<int>(3);

    root->Left->Left = new TreeNode<int>(4);
    root->Left->Right = new TreeNode<int>(5);

    // Полученное дерево:
    //           1
    //          / \
    //         2   3
    //        / \
    //       4   5

    cout << root->Left->Left->Data; // 4

    delete root;

    return 0;
}
