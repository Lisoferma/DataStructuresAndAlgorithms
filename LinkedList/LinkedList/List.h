// @author Lisoferma

#pragma once

#include "Node.h"
#include "IIterated.h"
#include "ListIterator.h"
#include <vector>

namespace DSAList
{
	/// <summary>
	/// Односвязный список.
	/// </summary>
	/// <typeparam name="T">Тип данных который хранит список.</typeparam>
	template <typename T>
	class List : public IIterated<T>
	{
	private:
		/// <summary>
		/// Указатель на первый узел списка.
		/// </summary>
		Node<T>* _first;

		/// <summary>
		/// Указатель на последний узел списка.
		/// </summary>
		Node<T>* _last;


	public:
		/// <summary>
		/// Инициализировать пустой списк.
		/// </summary>
		List() : _first(nullptr), _last(nullptr)
		{ }


		/// <summary>
		/// Инициализировать список данными из вектора.
		/// </summary>
		/// <param name="vector">Вектор который хранит данные для списка.</param>
		List(const std::vector<T>& vector) : List()
		{
			for (auto item : vector)
				PushBack(item);
		}


		/// <summary>
		/// Пустой ли список.
		/// </summary>
		/// <returns>True - пустой, иначе false.</returns>
		bool IsEmpty() const
		{
			return _first == nullptr;
		}


		/// <summary>
		/// Вставить данные в конец списка.
		/// </summary>
		/// <param name="data">Данные которые нужно вставить.</param>
		void PushBack(const T& data)
		{
			Node<T>* newNode = new Node(data);

			if (IsEmpty())
			{
				_first = newNode;
				_last = newNode;
				return;
			}

			_last->Next = newNode;
			_last = newNode;
		}


		/// <summary>
		/// Проверить находится ли элемент в cписке по заданному ключу.
		/// </summary>
		/// <param name="key">Ключ-данные элемента который нужно проверить.</param>
		/// <returns>True - элемент в списке, иначе false.</returns>
		bool IsInList(const T& key) const
		{
			Node<T>* current = _first;

			while (current && current->Data != key)
				current = current->Next;

			return (current && current->Data == key) ? true : false;
		}


		/// <summary>
		/// Удалить элемент по заданному ключу.
		/// </summary>
		/// <param name="key">Ключ-данные элемента который нужно удалить</param>
		void Remove(const T& key)
		{
			Node<T>* current = _first;
			Node<T>* previous = _first;

			if (_first->Data == key)
			{
				_first = _first->Next;
				delete current;
				return;
			}

			while (current != nullptr)
			{
				if (current->Data == key)
				{
					previous->Next = current->Next;
					delete current;
					return;
				}
				else
				{
					previous = current;
					current = current->Next;
				}			
			}
		}


		/// <summary>
		/// Получить итератор в начале списка.
		/// </summary>
		ListIterator<T>& begin() override
		{
			return *new ListIterator<T>(_first);
		}


		/// <summary>
		/// Получить итератор в конце списка.
		/// </summary>
		ListIterator<T>& end() override
		{
			return *new ListIterator<T>(nullptr);
		}
	};
}

