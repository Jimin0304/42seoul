#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	brain = new Brain();
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		*this->brain = *rhs.brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meowwwww Meowwwwww~" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (brain);
}