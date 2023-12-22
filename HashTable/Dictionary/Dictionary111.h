//// @author Lisoferma
//
//#pragma once
//
//#include "../../BinaryTree/AVLTree/AVLTree.h"
//
//namespace DSAHashTable
//{
//	/// <summary>
//	/// ������� �� ������ ���-�������. �������, ��������, ����� - � ������ O(logN), � ������� O(1).
//	/// </summary>
//	/// <typeparam name="TKey">��� ������ �����.</typeparam>
//	/// <typeparam name="TValue">��� ������ ��������.</typeparam>
//	template <typename TKey, typename TValue>
//	class Dictionary2
//	{
//	public:
//		/// <summary>
//		/// ��������� �� ������� ������� ���������� ��� �����.
//		/// </summary>
//		using HashFunction = unsigned long(*)(const TKey& Key);
//
//
//		/// <summary>
//		/// ���������������� ���-�������.
//		/// </summary>
//		/// <param name="capacity">����������� �������.</param>
//		/// <param name="hashFunction">���-������� ��� ��������� ���� ������.</param>
//		Dictionary2(unsigned long capacity, HashFunction hashFunction)
//			: _capacity(capacity), _hashFunction(hashFunction)
//		{
//			_items = new DSAAVLTree::AVLTree<TValue>[_capacity];
//		}
//
//
//		/// <summary>
//		/// �������� �������� � ������� �� �����.
//		/// </summary>
//		/// <param name="key">���� �� �������� ����� �������� ��������.</param>
//		/// <param name="value">������ ������� ����� ���������.</param>
//		void Insert(const TKey& key, const TValue& value)
//		{
//			unsigned long index = GetKeyIndex(key);
//			_items[index].Insert(value);
//		}
//
//
//		/// <summary>
//		/// ��������� ���� �� ������� � �������.
//		/// </summary>
//		/// <param name="key">���� ��������.</param>
//		/// <param name="value">�������� ��������.</param>
//		/// <returns>True - ���� ������� ������, ����� false.</returns>
//		bool Find(const TKey& key, const TValue& value) const
//		{
//			unsigned long index = GetKeyIndex(key);
//			return _items[index].Find(value);
//		}
//
//
//		/// <summary>
//		/// ������� ������� �� ������� �� �����.
//		/// </summary>
//		/// <param name="key">���� ������� ����� �������.</param>
//		void Remove(const TKey& key, const TValue& value)
//		{
//			unsigned long index = GetKeyIndex(key);
//			_items[index].Remove(value);
//		}
//
//
//		/// <summary>
//		/// ��������� ����� �� ���������.
//		/// </summary>
//		/// <param name="key1">������ ����.</param>
//		/// <param name="key2">������ ����.</param>
//		/// <returns>True - ���� ����� �����, ����� false.</returns>
//		bool KeyAreEqual(const T& key1, const T& key2) const
//		{
//			return _hashFunction(key1) == _hashFunction(key2);
//		}
//
//
//		/// <summary>
//		/// �������� ������� �������.
//		/// </summary>
//		unsigned long GetCapacity() const
//		{
//			return _capacity;
//		}
//
//
//		~HashTable()
//		{
//			delete[] _items;
//			_items = nullptr;
//		}
//
//
//	private:
//		/// <summary>
//		/// ������ ������, ������� �������� � ������ ��� ��������� ��������.
//		/// </summary>
//		DSAAVLTree::AVLTree<T>* _items;
//
//		/// <summary>
//		/// ����������� ���-�������.
//		/// </summary>
//		unsigned long _capacity;
//
//		/// <summary>
//		/// ���-������� ��� ��������� ���� �� �����.
//		/// </summary>
//		HashFunction _hashFunction;
//
//
//		/// <summary>
//		/// �������� ������ � ������� ��� �����, �� ������ ��� ����.
//		/// </summary>
//		/// <param name="key">���� ��� �������� ����� ����� ������.</param>
//		/// <returns>������ � ���-�������.</returns>
//		unsigned long GetKeyIndex(const T& key) const
//		{
//			return _hashFunction(key) % _capacity;
//		}
//	};
//}
