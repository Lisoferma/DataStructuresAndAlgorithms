// @author Lisoferma

#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;
using namespace DSAHashTable;


/// <summary>
/// Хэш-функция djb2 для строк.
/// </summary>
/// <param name="str">Строка для которой нужно получить хэш.</param>
/// <returns>Хэш строки.</returns>
unsigned long HashDJB2(const string& str)
{
	unsigned long hash = 5381;

	for (char character : str)
		hash = ((hash << 5) + hash) + character;	// hash * 33 + character

	return hash;
}


int main()
{
	HashTable<string> table(100ul, HashDJB2);

	// Вставка элементов
	table.Insert("Hello");
	table.Insert("World");
	table.Insert("Fox");
	table.Insert("Cat");
	table.Insert("Dog");


	// Проверить есть ли ключ в таблице
	cout << "Find(Hello): ";

	table.Find("Hello") 
		? cout << "found" << endl 
		: cout << "not found" << endl;

	cout << "Find(World): ";

	table.Find("World")
		? cout << "found" << endl
		: cout << "not found" << endl;


	// Проверка ключей на равенство
	cout << "KeyAreEqual(fox, fox): ";

	table.KeyAreEqual("fox", "fox")
		? cout << "equal" << endl
		: cout << "not Equal" << endl;

	cout << "KeyAreEqual(dog, cat): ";

	table.KeyAreEqual("dog", "cat")
		? cout << "equal" << endl
		: cout << "not equal" << endl;


	// Удалить ключ
	table.Remove("Hello");

	cout << "Remove(Hello): ";

	table.Find("Hello")
		? cout << "not deleted" << endl
		: cout << "deleted" << endl;
}
