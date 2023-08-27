#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *animal[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	std::cout << std::endl;

    // 깊은 복사인지 확인
    for (int i = 0; i < 10; i++)
       std::cout << &animal[i] << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
       animal[i]->makeSound();
    std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animal[i];
    std::cout << std::endl;

    Cat* cat = new Cat();
    std::cout << cat->getBrain()->getIdea(0) << std::endl;
    cat->getBrain()->setIdea(0, "Idea");
    std::cout << cat->getBrain()->getIdea(0) << std::endl;
    delete cat;

	// system("leaks ex01");
    
    return 0;
}