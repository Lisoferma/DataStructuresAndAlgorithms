//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include "BinaryTreeService.h"
#include <vector>

namespace DSAABinaryTree
{
	template<typename T>
	class BinarySearchTree
	{
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
                Insert(data);
        }
        

        /// <summary>
        /// ����� ���� �� �����.
        /// </summary>
        /// <param name="keyData">���� �� �������� ������������ �����.</param>
        /// <returns>��������� �� ��������� ����. ���� �� ������ - nullptr.</returns>
        BinaryNode<T>* Search(const T& keyData)
        {
            BinaryNode<T>* current = root;

            while (current != nullptr)
                if (current->Data == keyData)
                    return current;
                else
                    current = keyData < current->Data ?
                    current->Left : current->Right;

            return nullptr;
        }


        /// <summary>
        /// �������� ������ � ������.
        /// </summary>
        /// <param name="data">������ ��� ������ ����.</param>
        void Insert(const T& data)
        {
            if (IsEmpty())
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

        
        /// <summary>
        /// ������� ���� �� �����.
        /// </summary>
        /// <param name="key">������ ���� ������� ����� �������.</param>
        void Remove(const T& key)
        {
            BinaryTreeService::Remove(root, key);
        }

        
        bool IsEmpty()
        {
            if (root == nullptr)
                return true;
            else
                return false;
        }


        BinaryNode<T>* const GetRoot() const
        {
            return root;
        }


    private:
        // ������ ��������� ������ ������
        BinaryNode<T>* root;
	};
}