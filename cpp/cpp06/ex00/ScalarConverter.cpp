#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cerrno>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str)
{
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& str)
{
	if (str.empty())
		return false;
	
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	
	if (i >= str.length())
		return false;
	
	while (i < str.length())
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (str.length() < 2 || str[str.length() - 1] != 'f')
		return false;
	
	std::string withoutF = str.substr(0, str.length() - 1);
	
	if (withoutF == "-inf" || withoutF == "+inf" || withoutF == "nan")
		return true;
	
	size_t i = 0;
	if (withoutF[i] == '+' || withoutF[i] == '-')
		i++;
	
	bool hasDot = false;
	bool hasDigit = false;
	
	while (i < withoutF.length())
	{
		if (withoutF[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (isdigit(withoutF[i]))
			hasDigit = true;
		else
			return false;
		i++;
	}
	
	return hasDot && hasDigit;
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	
	bool hasDot = false;
	bool hasDigit = false;
	
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (isdigit(str[i]))
			hasDigit = true;
		else
			return false;
		i++;
	}
	
	return hasDot && hasDigit;
}

bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf" ||
			str == "-inf" || str == "+inf" || str == "nan");
}

void ScalarConverter::convertFromChar(const std::string& str)
{
	char c = str[1];
	
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& str)
{
	errno = 0;
	long value = strtol(str.c_str(), NULL, 10);
	
	if (errno == ERANGE || value > INT_MAX || value < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	
	int intValue = static_cast<int>(value);
	
	if (intValue < 0 || intValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(intValue))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
	
	std::cout << "int: " << intValue << std::endl;
	
	float floatValue = static_cast<float>(intValue);
	std::cout << "float: " << floatValue;
	if (floatValue == floor(floatValue) && floatValue >= -1000000.0f && floatValue <= 1000000.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	double doubleValue = static_cast<double>(intValue);
	std::cout << "double: " << doubleValue;
	if (doubleValue == floor(doubleValue) && doubleValue >= -1000000.0 && doubleValue <= 1000000.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& str)
{
	float floatValue = strtof(str.c_str(), NULL);
	
	if (std::isnan(floatValue) || std::isinf(floatValue))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int intValue = static_cast<int>(floatValue);
		
		if (floatValue < 0 || floatValue > 127 || floatValue != static_cast<float>(intValue))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(intValue))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		
		if (floatValue > INT_MAX || floatValue < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << intValue << std::endl;
	}
	
	std::cout << "float: " << floatValue;
	if (!std::isnan(floatValue) && !std::isinf(floatValue) && 
		floatValue == floor(floatValue) &&
		floatValue >= -1000000.0f && floatValue <= 1000000.0f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	std::cout << "double: " << static_cast<double>(floatValue);
	if (!std::isnan(floatValue) && !std::isinf(floatValue) && 
		floatValue == floor(floatValue) &&
		floatValue >= -1000000.0f && floatValue <= 1000000.0f)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& str)
{
	double doubleValue = strtod(str.c_str(), NULL);
	
	if (std::isnan(doubleValue) || std::isinf(doubleValue))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int intValue = static_cast<int>(doubleValue);
		
		if (doubleValue < 0 || doubleValue > 127 || doubleValue != static_cast<double>(intValue))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(intValue))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		
		if (doubleValue > INT_MAX || doubleValue < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << intValue << std::endl;
	}
	
	std::cout << "float: " << static_cast<float>(doubleValue);
	if (!std::isnan(doubleValue) && !std::isinf(doubleValue) && 
		doubleValue == floor(doubleValue) &&
		doubleValue >= -1000000.0 && doubleValue <= 1000000.0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	
	std::cout << "double: " << doubleValue;
	if (!std::isnan(doubleValue) && !std::isinf(doubleValue) && 
		doubleValue == floor(doubleValue) &&
		doubleValue >= -1000000.0 && doubleValue <= 1000000.0)
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convertPseudoLiteral(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (str == "nanf" || str == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inff" || str == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return;
	}
	
	if (isPseudoLiteral(str))
		convertPseudoLiteral(str);
	else if (isChar(str))
		convertFromChar(str);
	else if (isFloat(str))
		convertFromFloat(str);
	else if (isDouble(str))
		convertFromDouble(str);
	else if (isInt(str))
		convertFromInt(str);
	else
		std::cout << "Error: invalid input" << std::endl;
}
