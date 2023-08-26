#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog & src )
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	td::cout << "Dog destructor called" << std::endl;
}

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

void Dog::makeSound()
{
	std::cout << "Barkkkkk Barkkkkk!" << std::endl;
}