//#pragma once
//
//#include "../HashTable/HashTable.h"
//
//using namespace DSAHashTable;
//
//namespace DSADictionary
//{
//	/// <summary>
//	/// ������� �� ������ ���-�������. �������, ��������, ����� - � ������ O(logN), � ������� O(1).
//	/// </summary>
//	/// <typeparam name="TKey">��� ������ �����.</typeparam>
//	/// <typeparam name="TValue">��� ������ ��������.</typeparam>
//	template <typename TKey, typename TValue>
//	class Dictionary : private HashTable<TValue>
//	{
//	public:
//		Dictionary(unsigned long capacity, HashTable<TValue>::HashFunction hashFunction) :
//			HashTable<TValue>(capacity, hashFunction)
//		{ }
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
//			HashTable<TValue>::_items[index].Insert(value);
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
//			return HashTable<TValue>::_items[index].Find(value);
//		}
//
//
//		/// <summary>
//		/// ������� ������� �� �������.
//		/// </summary>
//		/// <param name="key">���� ������� ����� �������.</param>
//		void Remove(const TKey& key, const TValue& value)
//		{
//			unsigned long index = GetKeyIndex(key);
//			HashTable<TValue>::_items[index].Remove(value);
//		}
//
//	private:
//		/// <summary>
//		/// �������� ������ � ������� ��� �����, �� ������ ��� ����.
//		/// </summary>
//		/// <param name="key">���� ��� �������� ����� ����� ������.</param>
//		/// <returns>������ � ���-�������.</returns>
//		unsigned long GetKeyIndex(const TKey& key) const
//		{
//			return _hashFunction(key) % HashTable<TValue>::_capacity;
//		}
//	};
//}