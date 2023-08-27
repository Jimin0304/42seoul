#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat & src )
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meowwwww Meowwwwww~" << std::endl;
}