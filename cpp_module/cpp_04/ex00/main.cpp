#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    std::cout << std::endl;

    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* c = new WrongCat();
    std::cout << std::endl;

    std::cout << c->getType() << " " << std::endl;
    c->makeSound();
    wrong->makeSound();
    std::cout << std::endl;

    delete wrong;
    delete c;

    // system("leaks ex00");

    return 0;
}