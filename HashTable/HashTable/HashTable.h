// @author Lisoferma

#pragma once

#include "../../BinaryTree/AVLTree/AVLTree.h"

namespace DSAHashTable
{
	/// <summary>
	/// ���-�������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������� ��� ��������.</typeparam>
	template <typename T>
	class HashTable
	{
	public:
		/// <summary>
		/// ��������� �� ������� ������� ���������� ��� �����.
		/// </summary>
		using HashFunction = unsigned long(*)(const T& Key);


		/// <summary>
		/// ���������������� ���-�������.
		/// </summary>
		/// <param name="capacity">����������� �������.</param>
		/// <param name="hashFunction">���-������� ��� ��������� ���� ������.</param>
		HashTable(unsigned long capacity, HashFunction hashFunction)
			: _capacity(capacity), _hashFunction(hashFunction)
		{
			_items = new DSAAVLTree::AVLTree<T>[_capacity];
		}


		/// <summary>
		/// �������� ���� � �������.
		/// </summary>
		/// <param name="key">���� ������� ����� ��������.</param>
		void Insert(const T& key)
		{
			unsigned long index = GetKeyIndex(key);
			_items[index].Insert(key);
		}


		/// <summary>
		/// ��������� ���� �� ���� � �������.
		/// </summary>
		/// <param name="key">���� ������� ����� �����.</param>
		/// <returns>True - ���� ���� ������, ����� false.</returns>
		bool Find(const T& key) const
		{
			unsigned long index = GetKeyIndex(key);
			return _items[index].Find(key);
		}


		/// <summary>
		/// ������� ���� �� �������.
		/// </summary>
		/// <param name="key">���� ������� ����� �������.</param>
		void Remove(const T& key)
		{
			unsigned long index = GetKeyIndex(key);
			_items[index].Remove(key);
		}


		/// <summary>
		/// ��������� ����� �� ���������.
		/// </summary>
		/// <param name="key1">������ ����.</param>
		/// <param name="key2">������ ����.</param>
		/// <returns>True - ���� ����� �����, ����� false.</returns>
		bool KeyAreEqual(const T& key1, const T& key2) const
		{
			return _hashFunction(key1) == _hashFunction(key2);
		}


		~HashTable()
		{
			delete[] _items;
			_items = nullptr;
		}


	private:
		/// <summary>
		/// ������ ������, ������� �������� � ������ ��� ��������� ��������.
		/// </summary>
		DSAAVLTree::AVLTree<T>* _items;

		/// <summary>
		/// ����������� ���-�������.
		/// </summary>
		unsigned long _capacity;

		/// <summary>
		/// ���-������� ��� ��������� ���� �� �����.
		/// </summary>
		HashFunction _hashFunction;


		/// <summary>
		/// �������� ������ � ������� ��� �����, �� ������ ��� ����.
		/// </summary>
		/// <param name="key">���� ��� �������� ����� ����� ������.</param>
		/// <returns>������ � ���-�������.</returns>
		unsigned long GetKeyIndex(const T& key) const
		{
			return _hashFunction(key) % _capacity;
		}
	};
}
