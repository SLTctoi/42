#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

void additionalTests()
{
	std::cout << "\n=== Additional Tests ===" << std::endl;
	
	std::cout << "\n1. Test empty array:" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
	
	std::cout << "\n2. Test array with 5 elements:" << std::endl;
	Array<int> arr(5);
	std::cout << "Array size: " << arr.size() << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		arr[i] = i * 10;
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
	
	std::cout << "\n3. Test copy constructor:" << std::endl;
	Array<int> copy(arr);
	std::cout << "Copy size: " << copy.size() << std::endl;
	copy[0] = 999;
	std::cout << "After modifying copy[0] to 999:" << std::endl;
	std::cout << "Original arr[0] = " << arr[0] << " (should be 0)" << std::endl;
	std::cout << "Copy copy[0] = " << copy[0] << " (should be 999)" << std::endl;
	
	std::cout << "\n4. Test assignment operator:" << std::endl;
	Array<int> assigned;
	assigned = arr;
	std::cout << "Assigned size: " << assigned.size() << std::endl;
	assigned[1] = 888;
	std::cout << "After modifying assigned[1] to 888:" << std::endl;
	std::cout << "Original arr[1] = " << arr[1] << " (should be 10)" << std::endl;
	std::cout << "Assigned assigned[1] = " << assigned[1] << " (should be 888)" << std::endl;
	
	std::cout << "\n5. Test with strings:" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	for (unsigned int i = 0; i < strArray.size(); i++)
		std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
	
	std::cout << "\n6. Test const array:" << std::endl;
	const Array<int> constArr(copy);
	std::cout << "Const array[0] = " << constArr[0] << std::endl;
	
	std::cout << "\n7. Test exception on empty array:" << std::endl;
	try
	{
		empty[0] = 42;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main(int, char**)
{
	std::cout << "=== Main Test from Subject ===" << std::endl;
	
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "✓ Deep copy test passed (750 elements)" << std::endl;
	
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << "✓ Exception for negative index: " << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << "✓ Exception for index >= size: " << e.what() << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	
	additionalTests();
	
	std::cout << "\n=== All tests completed successfully ===" << std::endl;
	return 0;
}
