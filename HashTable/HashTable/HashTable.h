// @author Lisoferma

#pragma once

#include <stdexcept>
#include "../../BinaryTree/AVLTree/AVLTree.h"

namespace DSAHashTable
{
	/// <summary>
	/// Хэш-таблица. Вставка, удаление, поиск - в худшем O(logN), в среднем O(1).
	/// </summary>
	/// <typeparam name="T">Тип ключей который она содержит.</typeparam>
	template <typename T>
	class HashTable
	{
	public:
		/// <summary>
		/// Указатель на функцию которая возвращает хэш ключа.
		/// </summary>
		using HashFunction = unsigned long(*)(const T& Key);


		/// <summary>
		/// Инициализировать хэш-таблицу.
		/// </summary>
		/// <param name="capacity">Вместимость таблицы.</param>
		/// <param name="hashFunction">Хэш-функция для заданного типа ключей.</param>
		HashTable(unsigned long capacity, HashFunction hashFunction)
			: _capacity(capacity), _hashFunction(hashFunction)
		{
			if (capacity == 0)
				throw std::invalid_argument("Capacity should not be equal to 0.");

			_items = new DSAAVLTree::AVLTree<T>[_capacity];
		}


		/// <summary>
		/// Вставить ключ в таблицу.
		/// </summary>
		/// <param name="key">Ключ который нужно вставить.</param>
		void Insert(const T& key)
		{
			unsigned long index = GetKeyIndex(key);
			_items[index].Insert(key);
		}


		/// <summary>
		/// Проверить есть ли ключ в таблице.
		/// </summary>
		/// <param name="key">Ключ который нужно найти.</param>
		/// <returns>True - если ключ найден, иначе false.</returns>
		bool Find(const T& key) const
		{
			unsigned long index = GetKeyIndex(key);
			return _items[index].Find(key);
		}


		/// <summary>
		/// Удалить ключ из таблицы.
		/// </summary>
		/// <param name="key">Ключ который нужно удалить.</param>
		void Remove(const T& key)
		{
			unsigned long index = GetKeyIndex(key);
			_items[index].Remove(key);
		}


		/// <summary>
		/// Проверить ключи на равенство.
		/// </summary>
		/// <param name="key1">Первый ключ.</param>
		/// <param name="key2">Второй ключ.</param>
		/// <returns>True - если ключи равны, иначе false.</returns>
		bool KeyAreEqual(const T& key1, const T& key2) const
		{
			return _hashFunction(key1) == _hashFunction(key2);
		}


		/// <summary>
		/// Получить ёмкость хэш-таблицы.
		/// </summary>
		unsigned long GetCapacity() const
		{
			return _capacity;
		}


		unsigned long GetItemsCount() const
		{
			unsigned long count = 0;

			for (item : _items)
			{
				if (!item.IsEmpty())
					count += item.
			}

			return _capacity;
		}


		~HashTable()
		{
			delete[] _items;
			_items = nullptr;
		}


	private:
		/// <summary>
		/// Массив ключей, которые хранятся в дереве для избежания коллизии.
		/// </summary>
		DSAAVLTree::AVLTree<T>* _items;

		/// <summary>
		/// Вместимость хэш-таблицы.
		/// </summary>
		unsigned long _capacity;

		/// <summary>
		/// Хэш-функция для получения хэша из ключа.
		/// </summary>
		HashFunction _hashFunction;


		/// <summary>
		/// Получить индекс в таблице для ключа, на основе его хэша.
		/// </summary>
		/// <param name="key">Ключ для которого нужно найти индекс.</param>
		/// <returns>Индекс в хэш-таблице.</returns>
		unsigned long GetKeyIndex(const T& key) const
		{
			return _hashFunction(key) % _capacity;
		}
	};
}
