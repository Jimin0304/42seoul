#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *animal[4];

    // const Animal* meta = new Animal();
    // meta->makeSound();

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;

    for (int i = 0; i < 4; i++)
       animal[i]->makeSound();
    std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal[i];
    std::cout << std::endl;

	// system("leaks ex02");
    
    return 0;
}