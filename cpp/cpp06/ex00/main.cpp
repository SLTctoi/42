#include "ScalarConverter.hpp"
#include <iostream>

void testConversion(const std::string& input)
{
	std::cout << "Input: " << input << std::endl;
	ScalarConverter::convert(input);
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return 0;
	}

	std::cout << "=== Char literals ===" << std::endl;
	testConversion("'c'");
	testConversion("'a'");
	testConversion("'Z'");

	std::cout << "=== Int literals ===" << std::endl;
	testConversion("0");
	testConversion("42");
	testConversion("-42");
	testConversion("2147483647");

	std::cout << "=== Float literals ===" << std::endl;
	testConversion("0.0f");
	testConversion("4.2f");
	testConversion("-4.2f");
	testConversion("42.0f");

	std::cout << "=== Double literals ===" << std::endl;
	testConversion("0.0");
	testConversion("4.2");
	testConversion("-4.2");
	testConversion("42.0");

	std::cout << "=== Pseudo-literals (float) ===" << std::endl;
	testConversion("nanf");
	testConversion("+inff");
	testConversion("-inff");

	std::cout << "=== Pseudo-literals (double) ===" << std::endl;
	testConversion("nan");
	testConversion("+inf");
	testConversion("-inf");

	std::cout << "=== Edge cases ===" << std::endl;
	testConversion("127");
	testConversion("128");
	testConversion("-1");

	return 0;
}
