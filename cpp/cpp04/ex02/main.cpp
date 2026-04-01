#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
    std::cout << "Test sujet :" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
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
    
    Dog dog2(dog1);  // Copy constructor
    Dog dog3;
    dog3 = dog1;     // Assignment operator
    
    // Modify dog1's brain
    dog1.getBrain()->setBrain(0, "I am modified dog1");
    dog1.getBrain()->setBrain(1, "Modified idea");
    
    // Verify dog2 and dog3 are not affected (deep copy proof)
    std::cout << "dog1 brain[0]: " << dog1.getBrain()->getBrain(0) << std::endl;
    std::cout << "dog2 brain[0]: " << dog2.getBrain()->getBrain(0) << " (should be 'I am dog1')" << std::endl;
    std::cout << "dog3 brain[0]: " << dog3.getBrain()->getBrain(0) << " (should be 'I am dog1')" << std::endl;
    std::cout << std::endl;

    std::cout << "Test deep copy Cat :" << std::endl;
    Cat cat1;
    cat1.getBrain()->setBrain(0, "I am cat1");
    cat1.getBrain()->setBrain(1, "Meow meow");
    
    Cat cat2(cat1);  // Copy constructor
    Cat cat3;
    cat3 = cat1;     // Assignment operator
    
    // Modify cat1's brain
    cat1.getBrain()->setBrain(0, "I am modified cat1");
    cat1.getBrain()->setBrain(1, "Modified meow");
    
    // Verify cat2 and cat3 are not affected (deep copy proof)
    std::cout << "cat1 brain[0]: " << cat1.getBrain()->getBrain(0) << std::endl;
    std::cout << "cat2 brain[0]: " << cat2.getBrain()->getBrain(0) << " (should be 'I am cat1')" << std::endl;
    std::cout << "cat3 brain[0]: " << cat3.getBrain()->getBrain(0) << " (should be 'I am cat1')" << std::endl;
    std::cout << std::endl;

    // error bcs annimal is abstract
    // Animal* abstract = new Animal(); // Error: cannot instantiate abstract class

    std::cout << "Destructors :" << std::endl;
    return 0;
}