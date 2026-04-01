#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void)
{
	srand(time(NULL) + rand());
	int random = rand() % 3;
	
	switch (random)
	{
		case 0:
			std::cout << "[Generated type A]" << std::endl;
			return new A();
		case 1:
			std::cout << "[Generated type B]" << std::endl;
			return new B();
		case 2:
			std::cout << "[Generated type C]" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e) {}
	
	std::cout << "Unknown type" << std::endl;
}

int main()
{
	std::cout << "=== Test with random generation ===" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "\nTest " << (i + 1) << ":" << std::endl;
		Base* ptr = generate();
		std::cout << "Identify with pointer: ";
		identify(ptr);
		std::cout << "Identify with reference: ";
		identify(*ptr);
		delete ptr;
	}
	
	std::cout << "\n=== Test with known types ===" << std::endl;
	
	std::cout << "\nCreating A:" << std::endl;
	Base* a = new A();
	std::cout << "Identify with pointer: ";
	identify(a);
	std::cout << "Identify with reference: ";
	identify(*a);
	delete a;
	
	std::cout << "\nCreating B:" << std::endl;
	Base* b = new B();
	std::cout << "Identify with pointer: ";
	identify(b);
	std::cout << "Identify with reference: ";
	identify(*b);
	delete b;
	
	std::cout << "\nCreating C:" << std::endl;
	Base* c = new C();
	std::cout << "Identify with pointer: ";
	identify(c);
	std::cout << "Identify with reference: ";
	identify(*c);
	delete c;
	
	return 0;
}
