//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include <vector>

namespace DSAABinaryTree
{
	template<typename T>
	class BinarySearchTree
	{
	private:
        // ������ ��������� ������ ������
        BinaryNode<T>* root;

	public:
        BinarySearchTree() : root(nullptr)
        { }


        /// <summary>
        /// ���������������� ������ ������.
        /// </summary>
        /// <param name="root">������ ������.</param>
        BinarySearchTree(BinaryNode<T>* root) : root(root)
        { }


        /// <summary>
        /// ���������������� ������ ��������.
        /// </summary>
        /// <param name="dataVector">������ ������� ������ ������ ��� �����.</param>
        BinarySearchTree(const std::vector<T>& dataVector)
        {
            for (T data : dataVector)
            {
                Insert(data);
            }
        }


        /// <summary>
        /// �������� ������ � ������.
        /// </summary>
        /// <param name="data">������ ��� ������ ����.</param>
        void Insert(const T& data)
        {
            if (root == nullptr)
                root = new BinaryNode<T>(data);

            BinaryNode<T>* current = root;

            while (current && current->Data != data)
            {
                if (current->Data > data && current->Left == NULL)
                {
                    current->Left = new BinaryNode<T>(data);
                    return;
                }
                if (current->Data < data && current->Right == NULL)
                {
                    current->Right = new BinaryNode<T>(data);
                    return;
                }
                if (current->Data > data)
                {
                    current = current->Left;
                }
                else
                {
                    current = current->Right;
                }                 
            }
        }


        BinaryNode<T>* GetRoot()
        {
            return root;
        }
	};
}