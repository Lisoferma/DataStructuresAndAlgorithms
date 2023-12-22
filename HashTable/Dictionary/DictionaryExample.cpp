//// @author Lisoferma
//
//#include <iostream>
//#include <string>
//#include "Dictionary.h"
//
//using namespace std;
//using namespace DSADictionary;
//
//
///// <summary>
///// Хэш-функция djb2 для строк.
///// </summary>
///// <param name="str">Строка для которой нужно получить хэш.</param>
///// <returns>Хэш строки.</returns>
//unsigned long HashDJB2(const string& str)
//{
//	unsigned long hash = 5381;
//
//	for (char character : str)
//		hash = ((hash << 5) + hash) + character;	// hash * 33 + character
//
//	return hash;
//}
//
//
//int main()
//{
//	Dictionary<int, string> table(100ul, HashDJB2);
//
//	// Вставка элементов
//	table.Insert(1, "Hello");
//	table.Insert(3, "World");
//	table.Insert(5, "Fox");
//	table.Insert(10, "Cat");
//	table.Insert(-50, "Dog");
//
//
//	// Проверить есть ли элемент в таблице
//	cout << "Find(1, Hello): ";
//
//	table.Find(1, "1, Hello")
//		? cout << "found" << endl
//		: cout << "not found" << endl;
//
//	cout << "Find(99, World): ";
//
//	table.Find(99, "World")
//		? cout << "found" << endl
//		: cout << "not found" << endl;
//
//
//	// Удалить элемент
//	table.Remove(1, "Hello");
//
//	cout << "Remove(1, Hello): ";
//
//	table.Find(1, "Hello")
//		? cout << "not deleted" << endl
//		: cout << "deleted" << endl;
//}

