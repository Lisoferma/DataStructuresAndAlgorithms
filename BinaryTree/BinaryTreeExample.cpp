//@author Lisoferma

#include "BinaryNode.h"
#include "BinaryNodeTests.h"
#include "BinarySearchTree.h"
#include "BinaryTreeService.h"
#include <vector>
#include <iostream>
#include <algorithm>

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
    

    // Применение итератора
    cout << "\n\nIterator: ";

    for (int item : bst)
    {
        cout << item;
    }


    // Использование std algorithm
    cout << "\n\nAlgorithm: ";
   

    cout << "\n for_each: ";
    std::for_each(bst.begin(), bst.end(), [](auto item) { std::cout << item << " "; });


    cout << "\n any_of: ";
    if ( std::any_of(bst.begin(), bst.end(), [](int i) { return i % 2 == 0; }) )
        std::cout << "There are even numbers";
    else
        std::cout << "There are no even numbers";


    cout << "\n all_of: ";
    if (std::all_of(bst.begin(), bst.end(), [](int i) { return i % 2 == 0; }))
        std::cout << "All numbers are even";
    else
        std::cout << "Not all numbers are even";


    cout << "\n none_of: ";
    if (std::none_of(bst.begin(), bst.end(), [](int i) { return i == 8; }))
        std::cout << "No number is equal to 8";
    else
        std::cout << "There is a number equal to 8";


    cout << "\n transform: ";
    std::transform(bst.begin(), bst.end(), bst.begin(), [](int i) { return i * 2; });
    for (int item : bst) cout << item << " ";


    cout << "\n copy_if: ";
    std::vector<int> vector(2);
    std::copy_if(bst.begin(), bst.end(), vector.begin(), [](int i) { return i % 4 == 0; });
    for (int item : vector) cout << item << " ";


    return 0;
}
