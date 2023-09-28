//@author Lisoferma

#include "TreeNode.h"
#include "TreeNodeTests.h"
#include "BinaryTreeService.h"
#include <iostream>

using namespace std;
using namespace DSAABinaryTree;


/// <summary>
/// Вывести вектор в консоль.
/// </summary>
/// <typeparam name="T">Тип данных вектора.</typeparam>
/// <param name="vector">Вектор который нужно вывести.</param>
template <typename T>
void VectorPrintToConsole(const vector<T>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
        cout << vector[i] << " ";
}


// Пример работы с двоичным деревом
int main()
{
    TreeNodeTests::TreeNode_CreateTree_DataIsEqualInitial();

    TreeNode<int>* root = CreateBinarySearchTree();

    // Созданное дерево:
    //           5
    //          / \
    //         4   6
    //        / \
    //       3   5

    // delete root; // удаление дерева


    // Вывод дерева в консоль разными способами обхода
    cout << "Tree (LNR): ";
    TraversalLNR<int>(root, [](TreeNode<int>& node) { cout << node.Data << " "; });

    cout << "\n\nTree (NLR): ";
    TraversalNLR<int>(root, [](TreeNode<int>& node) { cout << node.Data << " "; });

    cout << "\n\nTree (LRN): ";
    TraversalLRN<int>(root, [](TreeNode<int>& node) { cout << node.Data << " "; });


    // Получение вектора на основе дерева
    vector<int> vectorFromTree;

    TraversalLNR<int>(root, [&vectorFromTree](TreeNode<int>& node) {
        vectorFromTree.push_back(node.Data); });

    cout << "\n\nVector from tree (LNR): ";
    VectorPrintToConsole(vectorFromTree);


    // Количество узлов в дереве
    cout << "\n\nNode count: " << NodeCount(root);

    // Высота дерева
    cout << "\nHeight: " << TreeHeight(root);

    // Поиск узла по ключу
    TreeNode<int>* findedNode = Find(root, 4);
    cout << "\n\nFind node: " << findedNode->Data;

    // Поиск следующего наибольшего
    TreeNode<int>* successor = GetInOrderSuccessor(findedNode);
    cout << "\n\nSuccessor for 4: " << successor->Data;

    return 0;
}
