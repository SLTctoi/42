#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";
	originalData.value = 3.14159;
	originalData.active = true;

	std::cout << "=== Original Data ===" << std::endl;
	std::cout << "Address: " << &originalData << std::endl;
	std::cout << "ID: " << originalData.id << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Value: " << originalData.value << std::endl;
	std::cout << "Active: " << (originalData.active ? "true" : "false") << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "=== Serialization ===" << std::endl;
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "=== Deserialized Data ===" << std::endl;
	std::cout << "Address: " << deserialized << std::endl;
	std::cout << "ID: " << deserialized->id << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Value: " << deserialized->value << std::endl;
	std::cout << "Active: " << (deserialized->active ? "true" : "false") << std::endl;
	std::cout << std::endl;

	std::cout << "=== Comparison ===" << std::endl;
	std::cout << "Original pointer: " << &originalData << std::endl;
	std::cout << "Deserialized pointer: " << deserialized << std::endl;
	std::cout << "Pointers are equal: " << (deserialized == &originalData ? "YES ✓" : "NO ✗") << std::endl;
	std::cout << std::endl;

	std::cout << "=== Additional Tests ===" << std::endl;
	Data* dynamicData = new Data();
	dynamicData->id = 100;
	dynamicData->name = "Dynamic Data";
	dynamicData->value = 2.71828;
	dynamicData->active = false;

	uintptr_t serializedDynamic = Serializer::serialize(dynamicData);
	Data* deserializedDynamic = Serializer::deserialize(serializedDynamic);

	std::cout << "Dynamic data test: " << (deserializedDynamic == dynamicData ? "PASS ✓" : "FAIL ✗") << std::endl;
	std::cout << "Dynamic data ID: " << deserializedDynamic->id << std::endl;
	std::cout << "Dynamic data Name: " << deserializedDynamic->name << std::endl;

	delete dynamicData;

	return 0;
}
