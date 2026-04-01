#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T const & x)
{
	std::cout << x << std::endl;
}

template <typename T>
void printWithPrefix(T const & x)
{
	std::cout << "Value: " << x << std::endl;
}

void addOne(int& x)
{
	x += 1;
}

void toUpper(char& c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
}

void doubleValue(double& d)
{
	d *= 2.0;
}

int main()
{
	std::cout << "=== Test 1: Array of integers with print ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	::iter(intArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "=== Test 2: Array of strings with print ===" << std::endl;
	std::string strArray[] = {"Hello", "World", "From", "Templates"};
	::iter(strArray, 4, print<std::string>);
	std::cout << std::endl;

	std::cout << "=== Test 3: Array of doubles with prefix ===" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	::iter(doubleArray, 4, printWithPrefix<double>);
	std::cout << std::endl;

	std::cout << "=== Test 4: Modify array - add one to each int ===" << std::endl;
	int modArray[] = {10, 20, 30, 40, 50};
	std::cout << "Before: ";
	::iter(modArray, 5, print<int>);
	::iter(modArray, 5, addOne);
	std::cout << "After: ";
	::iter(modArray, 5, print<int>);
	std::cout << std::endl;

	std::cout << "=== Test 5: Modify char array - to uppercase ===" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	std::cout << "Before: ";
	::iter(charArray, 5, print<char>);
	::iter(charArray, 5, toUpper);
	std::cout << "After: ";
	::iter(charArray, 5, print<char>);
	std::cout << std::endl;

	std::cout << "=== Test 6: Modify double array - double values ===" << std::endl;
	double modDoubleArray[] = {1.5, 2.5, 3.5};
	std::cout << "Before: ";
	::iter(modDoubleArray, 3, print<double>);
	::iter(modDoubleArray, 3, doubleValue);
	std::cout << "After: ";
	::iter(modDoubleArray, 3, print<double>);
	std::cout << std::endl;

	std::cout << "=== Test 7: Const array ===" << std::endl;
	int const constArray[] = {100, 200, 300};
	::iter(constArray, 3, print<int>);
	std::cout << std::endl;

	return 0;
}
