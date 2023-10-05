//@author Lisoferma

#include "BinaryNode.h"
#include "BinaryNodeTests.h"
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

    BinaryNode<int>* root = CreateBinarySearchTree();

    // Созданное дерево:
    //           6
    //          / \
    //         4   7
    //        / \
    //       3   5

    // delete root; // удаление дерева


    // Вывод дерева в консоль разными способами обхода
    cout << "Tree (Inorder): ";
    InorderTraversal<int>(root, [](BinaryNode<int>& node) { cout << node.Data << " "; });

    cout << "\n\nTree (Preorder): ";
    PreorderTraversal<int>(root, [](BinaryNode<int>& node) { cout << node.Data << " "; });

    cout << "\n\nTree (Postorder): ";
    PostorderTraversal<int>(root, [](BinaryNode<int>& node) { cout << node.Data << " "; });


    // Получение вектора на основе дерева
    vector<int> vectorFromTree;

    InorderTraversal<int>(root, [&vectorFromTree](BinaryNode<int>& node) {
        vectorFromTree.push_back(node.Data); });

    cout << "\n\nVector from tree (LNR): ";
    VectorPrintToConsole(vectorFromTree);


    // Количество узлов в дереве
    cout << "\n\nNode count: " << NodeCount(root);

    // Высота дерева
    cout << "\nHeight: " << TreeHeight(root);

    // Поиск узла по ключу
    BinaryNode<int>* findedNode = Find(root, 4);
    cout << "\n\nFind node: " << findedNode->Data;

    // Поиск следующего наибольшего
    BinaryNode<int>* successor = GetInOrderSuccessor(findedNode);
    cout << "\n\nSuccessor for 4: " << successor->Data;

    // Удаление узла по ключу
    cout << "\n\nDelete 4: " << endl;
    Remove(root, 4);
    InorderTraversal<int>(root, [](BinaryNode<int>& node) { cout << node.Data << " "; });

    return 0;
}
