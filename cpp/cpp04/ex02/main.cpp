#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
    std::cout << "Test sujet :" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    std::cout << std::endl;

    std::cout << "Create array of Animals :" << std::endl;
    const int size = 6;
    Animal* animals[size];
    
    for (int idx = 0; idx < size / 2; idx++) {
        animals[idx] = new Dog();
    }
    for (int idx = size / 2; idx < size; idx++) {
        animals[idx] = new Cat();
    }
    std::cout << std::endl;

    std::cout << "Test makeSound :" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        std::cout << animals[idx]->getType() << ": ";
        animals[idx]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "Delete all animals :" << std::endl;
    for (int idx = 0; idx < size; idx++) {
        delete animals[idx];
    }
    std::cout << std::endl;

    std::cout << "Test deep copy Dog :" << std::endl;
    Dog dog1;
    dog1.getBrain()->setBrain(0, "I am dog1");
    dog1.getBrain()->setBrain(1, "First idea");
    
    Dog dog2(dog1);
    Dog dog3;
    dog3 = dog1;
    
    dog1.getBrain()->setBrain(0, "I am modified dog1");
    dog1.getBrain()->setBrain(1, "Modified idea");
    
    std::cout << "dog1 brain[0]: " << dog1.getBrain()->getBrain(0) << std::endl;
    std::cout << "dog2 brain[0]: " << dog2.getBrain()->getBrain(0) << " (should be 'I am dog1')" << std::endl;
    std::cout << "dog3 brain[0]: " << dog3.getBrain()->getBrain(0) << " (should be 'I am dog1')" << std::endl;
    std::cout << std::endl;

    std::cout << "Test deep copy Cat :" << std::endl;
    Cat cat1;
    cat1.getBrain()->setBrain(0, "I am cat1");
    cat1.getBrain()->setBrain(1, "Meow meow");
    
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;
    
    cat1.getBrain()->setBrain(0, "I am modified cat1");
    cat1.getBrain()->setBrain(1, "Modified meow");
    
    std::cout << "cat1 brain[0]: " << cat1.getBrain()->getBrain(0) << std::endl;
    std::cout << "cat2 brain[0]: " << cat2.getBrain()->getBrain(0) << " (should be 'I am cat1')" << std::endl;
    std::cout << "cat3 brain[0]: " << cat3.getBrain()->getBrain(0) << " (should be 'I am cat1')" << std::endl;
    std::cout << std::endl;

    std::cout << "Destructors :" << std::endl;
    return 0;
}