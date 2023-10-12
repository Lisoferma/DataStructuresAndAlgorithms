//@author Lisoferma

#pragma once

#include "BinaryNode.h"
#include "BinaryTreeService.h"
#include <vector>
#include <queue>

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


        /// <summary>
        /// �������� � ������.
        /// </summary>
        /// <returns>������������ ������ � ������.</returns>
        T MaxItem()
        {
            BinaryNode<T>* current = root;

            while (current->Right != nullptr)
                current = current->Right;

            return current->Data;
        }


        /// <summary>
        /// ������� � ������.
        /// </summary>
        /// <returns>����������� ������ � ������.</returns>
        T MinItem()
        {
            BinaryNode<T>* current = root;

            while (current->Left != nullptr)
                current = current->Left;

            return current->Data;
        }


        /// <summary>
        /// ������ �� ������.
        /// </summary>
        /// <returns>True - ������, false - �� ������.</returns>
        bool IsEmpty()
        {
            if (root == nullptr)
                return true;
            else
                return false;
        }


        /// <summary>
        /// ������� ������.
        /// </summary>
        void Delete()
        {
            if (IsEmpty()) return;

            std::queue<BinaryNode<T>*> queue;
            queue.push(root);

            BinaryNode<T>* front = nullptr;

            while (!queue.empty())
            {
                front = queue.front();
                queue.pop();

                if (front->Left)
                    queue.push(front->Left);

                if (front->Right)
                    queue.push(front->Right);

                delete front;
            }

            root = nullptr;
        }


        /// <summary>
        /// �������� ��������� �� ������ ������.
        /// </summary>
        /// <returns>��������� �� ������ ������.</returns>
        BinaryNode<T>* const GetRoot() const
        {
            return root;
        }


    private:
        // ������ ��������� ������ ������
        BinaryNode<T>* root;
	};
}