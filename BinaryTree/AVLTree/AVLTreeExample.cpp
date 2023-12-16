// @author Lisoferma

#include <iostream>
#include "AVLTree.h"

using namespace std;
using namespace DSAAVLTree;

int main()
{
    AVLTree<int> tree;
    
    // Вставка данных
    tree.Insert(7);
    tree.Insert(6);
    tree.Insert(5);
    tree.Insert(4);
    tree.Insert(3);
    tree.Insert(2);
    tree.Insert(1);
    tree.Insert(0);
    
    // Удаление данных
    tree.Remove(4);
    tree.Remove(7);

    // Полученное дерево:
    // 
    //         2
    //        / \
    //       1   5
    //      /   / \
    //     0   3   6

    //cout << "Height: " << tree.GetHeight();
}