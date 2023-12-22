//#pragma once
//
//#include "../HashTable/HashTable.h"
//
//using namespace DSAHashTable;
//
//namespace DSADictionary
//{
//	/// <summary>
//	/// Словарь на основе хэш-таблицы. Вставка, удаление, поиск - в худшем O(logN), в среднем O(1).
//	/// </summary>
//	/// <typeparam name="TKey">Тип данных ключа.</typeparam>
//	/// <typeparam name="TValue">Тип данных значения.</typeparam>
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
//		/// Вставить значение в словарь по ключу.
//		/// </summary>
//		/// <param name="key">Ключ по которому будет хранится значение.</param>
//		/// <param name="value">Данные которые нужно сохранить.</param>
//		void Insert(const TKey& key, const TValue& value)
//		{
//			unsigned long index = GetKeyIndex(key);
//			HashTable<TValue>::_items[index].Insert(value);
//		}
//
//
//		/// <summary>
//		/// Проверить есть ли элемент в таблице.
//		/// </summary>
//		/// <param name="key">Ключ элемента.</param>
//		/// <param name="value">Значение элемента.</param>
//		/// <returns>True - если элемент найден, иначе false.</returns>
//		bool Find(const TKey& key, const TValue& value) const
//		{
//			unsigned long index = GetKeyIndex(key);
//			return HashTable<TValue>::_items[index].Find(value);
//		}
//
//
//		/// <summary>
//		/// Удалить элемент из таблицы.
//		/// </summary>
//		/// <param name="key">Ключ который нужно удалить.</param>
//		void Remove(const TKey& key, const TValue& value)
//		{
//			unsigned long index = GetKeyIndex(key);
//			HashTable<TValue>::_items[index].Remove(value);
//		}
//
//	private:
//		/// <summary>
//		/// Получить индекс в таблице для ключа, на основе его хэша.
//		/// </summary>
//		/// <param name="key">Ключ для которого нужно найти индекс.</param>
//		/// <returns>Индекс в хэш-таблице.</returns>
//		unsigned long GetKeyIndex(const TKey& key) const
//		{
//			return _hashFunction(key) % HashTable<TValue>::_capacity;
//		}
//	};
//}