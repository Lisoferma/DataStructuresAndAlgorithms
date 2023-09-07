#include "TreeNode.h"
#include <iostream>
#include <iomanip>


using namespace std;
using namespace DSAABinaryTree;

/// <summary>
/// ������� �������� ������, root ����� ����� nullptr.
/// </summary>
/// <typeparam name="T">��� ������ ������� ������ ������.</typeparam>
/// <param name="root">������ ������.</param>
template <typename T>
void DeleteBinaryTree(TreeNode<T>* root)
{
    if (root == nullptr) return;
    delete root;
    root = nullptr;
}


template <typename T>
void TreePrint(TreeNode<T>* root)
{
    if (root == nullptr) return;

    cout << root->Data << endl;
    TreePrint(root->Left);
    TreePrint(root->Right);
}


int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);

    root->Left = new TreeNode<int>(2);
    root->Right = new TreeNode<int>(3);

    root->Left->Left = new TreeNode<int>(4);
    root->Left->Right = new TreeNode<int>(5);

    // ���������� ������:
    //           1
    //          / \
    //         2   3
    //        / \
    //       4   5

    //cout << root->Left->Left->Data; // 4

    //DeleteBinaryTree(root);

    // << root->Data;

    TreePrint(root);

    return 0;
}
