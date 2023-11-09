//@author Lisoferma

#include "BinaryNode.h"
#include "BinaryNodeTests.h"
#include "BinarySearchTree.h"
#include "BinaryTreeService.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace DSAABinaryTree;
using namespace BinaryTreeService;


/// <summary>
/// Вывести дерево в консоль.
/// </summary>
/// <typeparam name="T">Тип данных дерева.</typeparam>
/// <param name="vector">Корень дерева которое нужно вывести.</param>
template <typename T>
void TreePrintToConsole(BinaryNode<T>* root)
{
    InorderTraversal<T>(root, [](BinaryNode<T>& node) { cout << node.Data << " "; });
}


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

    // DeleteRecursively(root); // удаление дерева


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

    cout << "\n\nVector from tree: ";
    VectorPrintToConsole(vectorFromTree);


    // Количество узлов в дереве
    cout << "\n\nNode count: " << NodeCount(root);

    // Высота дерева
    cout << "\nHeight: " << TreeHeight(root);

    // Поиск узла по ключу
    BinaryNode<int>* findedNode = Search(root, 4);
    cout << "\n\nFind node: " << findedNode->Data;

    // Поиск следующего наибольшего
    BinaryNode<int>* successor = GetInOrderSuccessor(findedNode);
    cout << "\n\nSuccessor for 4: " << successor->Data;

    // Удаление узла по ключу
    cout << "\n\nDelete 4: " << endl;
    Remove(root, 4);
    TreePrintToConsole(root);

    // Клонирование дерева
    cout << "\n\nClone binary tree: " << endl;
    BinaryNode<int>* rootClone = Clone(root);
    TreePrintToConsole(rootClone);


    // Класс бинарного дерева поиска
    cout << "\n\nBST class: " << endl;
    BinarySearchTree<int> bst;

    // Вставка
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(8);
    bst.Insert(7);
    bst.Insert(9);
    
    // Удаление узлов
    bst.Remove(8);
    bst.Remove(9);

    TreePrintToConsole(bst.GetRoot());

    // Максимум и минимум
    cout << "\n\nBST max: " << bst.MaxItem();
    cout << "\nBST min: " << bst.MinItem();

    // Поиск узла по ключу
    BinaryNode<int>* findedNodeInBst = bst.Search(6);
    cout << "\n\nSearch in BST: " << findedNodeInBst->Data;

    //// Удаление всего дерева
    //bst.Delete();
    //cout << "\n\nBST is empty after delete: " << bst.IsEmpty() << endl;
    
    cout << "\n\nBegin: " << *bst.begin();

    //auto end = bst.end();
    cout << "\nEnd: " << (bst.end() == InorderIterator<int>(nullptr, false) ? "true" : "false");
    
    auto iterator = bst.begin();
    auto end = bst.end();

    while (iterator != end)
    {
        cout << *iterator << " " << endl;
        ++iterator;
    }


    //for (int item : bst)
    //{
    //    cout << item;
    //}

    //std::for_each(bst.begin(), bst.end(), [](auto item) { std::cout << item << " "; });

    return 0;
}
