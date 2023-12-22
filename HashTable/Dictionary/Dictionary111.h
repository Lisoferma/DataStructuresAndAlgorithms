//// @author Lisoferma
//
//#pragma once
//
//#include "../../BinaryTree/AVLTree/AVLTree.h"
//
//namespace DSAHashTable
//{
//	/// <summary>
//	/// Словарь на основе хэш-таблицы. Вставка, удаление, поиск - в худшем O(logN), в среднем O(1).
//	/// </summary>
//	/// <typeparam name="TKey">Тип данных ключа.</typeparam>
//	/// <typeparam name="TValue">Тип данных значения.</typeparam>
//	template <typename TKey, typename TValue>
//	class Dictionary2
//	{
//	public:
//		/// <summary>
//		/// Указатель на функцию которая возвращает хэш ключа.
//		/// </summary>
//		using HashFunction = unsigned long(*)(const TKey& Key);
//
//
//		/// <summary>
//		/// Инициализировать хэш-таблицу.
//		/// </summary>
//		/// <param name="capacity">Вместимость таблицы.</param>
//		/// <param name="hashFunction">Хэш-функция для заданного типа ключей.</param>
//		Dictionary2(unsigned long capacity, HashFunction hashFunction)
//			: _capacity(capacity), _hashFunction(hashFunction)
//		{
//			_items = new DSAAVLTree::AVLTree<TValue>[_capacity];
//		}
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
//			_items[index].Insert(value);
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
//			return _items[index].Find(value);
//		}
//
//
//		/// <summary>
//		/// Удалить элемент из таблицы по ключу.
//		/// </summary>
//		/// <param name="key">Ключ который нужно удалить.</param>
//		void Remove(const TKey& key, const TValue& value)
//		{
//			unsigned long index = GetKeyIndex(key);
//			_items[index].Remove(value);
//		}
//
//
//		/// <summary>
//		/// Проверить ключи на равенство.
//		/// </summary>
//		/// <param name="key1">Первый ключ.</param>
//		/// <param name="key2">Второй ключ.</param>
//		/// <returns>True - если ключи равны, иначе false.</returns>
//		bool KeyAreEqual(const T& key1, const T& key2) const
//		{
//			return _hashFunction(key1) == _hashFunction(key2);
//		}
//
//
//		/// <summary>
//		/// Получить ёмкость словаря.
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
//		/// Массив ключей, которые хранятся в дереве для избежания коллизии.
//		/// </summary>
//		DSAAVLTree::AVLTree<T>* _items;
//
//		/// <summary>
//		/// Вместимость хэш-таблицы.
//		/// </summary>
//		unsigned long _capacity;
//
//		/// <summary>
//		/// Хэш-функция для получения хэша из ключа.
//		/// </summary>
//		HashFunction _hashFunction;
//
//
//		/// <summary>
//		/// Получить индекс в таблице для ключа, на основе его хэша.
//		/// </summary>
//		/// <param name="key">Ключ для которого нужно найти индекс.</param>
//		/// <returns>Индекс в хэш-таблице.</returns>
//		unsigned long GetKeyIndex(const T& key) const
//		{
//			return _hashFunction(key) % _capacity;
//		}
//	};
//}
