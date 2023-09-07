#include "TreeNode.h"

namespace DSAABinaryTree
{
	/// <summary>
	///	Инициализировать данные узла.
	/// </summary>
	/// <param name="data">Данные узла.</param>
	template<typename T>
	TreeNode<T>::TreeNode(T data)
	{
		Data = data;
		Parent = nullptr;
		Left = nullptr;
		Right = nullptr;
	}


	/// <summary>
	///	Инициализировать данные узла и указатель на родительский и дочерние узлы.
	/// </summary>
	/// <param name="data">Данные узла.</param>
	/// <param name="parent">Указатель на родительский узел.</param>
	/// <param name="left">Указатель на левый узел.</param>
	/// <param name="right">Указатель на правый узел.</param>
	template<typename T>
	TreeNode<T>::TreeNode(T data, TreeNode* parent, TreeNode* left, TreeNode* right)
	{
		Data = data;
		Parent = parent;
		Left = left;
		Right = right;
	}


	template <typename T>
	TreeNode<T>::~TreeNode()
	{
		delete Left;
		delete Right;
	}
}  // namespace DSAABinaryTree
