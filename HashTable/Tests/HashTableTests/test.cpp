#include <string>
#include <vector>
#include "pch.h"
#include "../../HashTable/HashTable.h"

using namespace DSAHashTable;

/// <summary>
/// Хэш-функция djb2 для строк.
/// </summary>
/// <param name="str">Строка для которой нужно получить хэш.</param>
/// <returns>Хэш строки.</returns>
unsigned long HashDJB2(const std::string& str)
{
	unsigned long hash = 5381;

	for (char character : str)
		hash = ((hash << 5) + hash) + character;	// hash * 33 + character

	return hash;
}


TEST(Constructor, InitializeZeroCapacity_ShouldThrowInvalidArgument)
{
	ASSERT_THROW(HashTable<std::string> table(0ul, HashDJB2), std::invalid_argument);
}


TEST(Constructor, Initialize1Capacity_DontThrowInvalidArgument)
{
	ASSERT_NO_THROW(HashTable<std::string> table(1ul, HashDJB2), std::invalid_argument);
}


TEST(Insert, InsertItems_ItemsFoundInTable)
{
	std::vector<std::string> initData { "Hello", "World", "Fox", "Cat", "Dog" };
	HashTable<std::string> table(6ul, HashDJB2);

	for (size_t i = 0; i < initData.size(); ++i)
		table.Insert(initData[i]);

	for (size_t i = 0; i < initData.size(); ++i)
		EXPECT_TRUE(table.Find(initData[i]));
}


TEST(Find, FindExistingItem_ReturnTrue)
{
	std::vector<std::string> initData{ "Hello", "World", "Fox", "Cat", "Dog" };
	HashTable<std::string> table(6ul, HashDJB2);

	for (size_t i = 0; i < initData.size(); ++i)
		table.Insert(initData[i]);

	for (size_t i = 0; i < initData.size(); ++i)
		EXPECT_TRUE(table.Find(initData[i]));
}


TEST(Find, FindNonExistingItem_ReturnFalse)
{
	std::vector<std::string> initData{ "Hello", "World", "Fox", "Cat", "Dog" };
	std::vector<std::string> findData{ "This", "Item", "Are", "Not", "In", "Table"};
	HashTable<std::string> table(6ul, HashDJB2);

	for (size_t i = 0; i < initData.size(); ++i)
		table.Insert(initData[i]);

	for (size_t i = 0; i < initData.size(); ++i)
		EXPECT_FALSE(table.Find(findData[i]));
}


TEST(Remove, RemoveNonExistingKey_TableDataHasntChanged)
{
	std::vector<std::string> initData{ "Hello", "World", "Fox", "Cat", "Dog" };
	HashTable<std::string> table(6ul, HashDJB2);

	for (size_t i = 0; i < initData.size(); ++i)
		table.Insert(initData[i]);

	table.Remove("Test");

	for (size_t i = 0; i < initData.size(); ++i)
		EXPECT_TRUE(table.Find(initData[i]));
}


TEST(Remove, RemoveKeys_KeysDeletes)
{
	std::vector<std::string> initData{ "Hello", "World", "Fox", "Cat", "Dog" };
	HashTable<std::string> table(6ul, HashDJB2);

	for (size_t i = 0; i < initData.size(); ++i)
		table.Insert(initData[i]);

	table.Remove("Hello");
	table.Remove("Cat");

	EXPECT_FALSE(table.Find("Hello"));
	EXPECT_FALSE(table.Find("Cat"));
}


TEST(Remove, RemoveKeys_OtherKeysIsSaved)
{
	std::vector<std::string> initData{ "Hello", "World", "Fox", "Cat", "Dog" };
	HashTable<std::string> table(6ul, HashDJB2);

	for (size_t i = 0; i < initData.size(); ++i)
		table.Insert(initData[i]);

	table.Remove("Hello");
	table.Remove("Cat");

	EXPECT_TRUE(table.Find("World"));
	EXPECT_TRUE(table.Find("Fox"));
	EXPECT_TRUE(table.Find("Dog"));
}


TEST(KeyAreEqual, СompareSameKeys_ReturnTrue)
{
	HashTable<std::string> table(1ul, HashDJB2);

	EXPECT_TRUE(table.KeyAreEqual("TEST", "TEST"));
}


TEST(KeyAreEqual, СompareDifferentKeys_ReturnFalse)
{
	HashTable<std::string> table(1ul, HashDJB2);

	EXPECT_FALSE(table.KeyAreEqual("Yes", "Not"));
}


TEST(GetCapacity, InitializyCapacity_CapacityIsCorrect)
{
	unsigned long initCapacity = 15ul;
	HashTable<std::string> table(initCapacity, HashDJB2);

	EXPECT_TRUE(table.GetCapacity() == initCapacity);
}