#include "Cat.cpp"
#include "Dog.cpp"
#include "WrongCat.cpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrong = new WrongAnimal;
    const WrongAnimal* c = new WrongCat();

    std::cout << c->getType() << " " << std::endl;
    c->makeSound();
    wrong->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrong;
    delete c;

    return 0;
}