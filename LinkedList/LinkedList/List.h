// @author Lisoferma

#pragma once

#include "Node.h"
#include "IIterated.h"
#include "ListIterator.h"
#include <vector>

namespace DSAList
{
	/// <summary>
	/// ����������� ������.
	/// </summary>
	/// <typeparam name="T">��� ������ ������� ������ ������.</typeparam>
	template <typename T>
	class List : public IIterated<T>
	{
	private:
		/// <summary>
		/// ��������� �� ������ ���� ������.
		/// </summary>
		Node<T>* _first;

		/// <summary>
		/// ��������� �� ��������� ���� ������.
		/// </summary>
		Node<T>* _last;


	public:
		/// <summary>
		/// ���������������� ������ �����.
		/// </summary>
		List() : _first(nullptr), _last(nullptr)
		{ }


		/// <summary>
		/// ���������������� ������ ������� �� �������.
		/// </summary>
		/// <param name="vector">������ ������� ������ ������ ��� ������.</param>
		List(const std::vector<T>& vector) : List()
		{
			for (auto item : vector)
				PushBack(item);
		}


		/// <summary>
		/// ������ �� ������.
		/// </summary>
		/// <returns>True - ������, ����� false.</returns>
		bool IsEmpty() const
		{
			return _first == nullptr;
		}


		/// <summary>
		/// �������� ������ � ����� ������.
		/// </summary>
		/// <param name="data">������ ������� ����� ��������.</param>
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
		/// ��������� ��������� �� ������� � c����� �� ��������� �����.
		/// </summary>
		/// <param name="key">����-������ �������� ������� ����� ���������.</param>
		/// <returns>True - ������� � ������, ����� false.</returns>
		bool IsInList(const T& key) const
		{
			Node<T>* current = _first;

			while (current && current->Data != key)
				current = current->Next;

			return (current && current->Data == key) ? true : false;
		}


		/// <summary>
		/// ������� ������� �� ��������� �����.
		/// </summary>
		/// <param name="key">����-������ �������� ������� ����� �������</param>
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
		/// �������� �������� � ������ ������.
		/// </summary>
		ListIterator<T>& begin() override
		{
			return *new ListIterator<T>(_first);
		}


		/// <summary>
		/// �������� �������� � ����� ������.
		/// </summary>
		ListIterator<T>& end() override
		{
			return *new ListIterator<T>(nullptr);
		}
	};
}

