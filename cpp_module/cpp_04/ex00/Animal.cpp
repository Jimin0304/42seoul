#include "Animal.hpp"

Animal::Animal() : type(NULL)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &				Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

void Animal::makeSound() {}

std::string	Animal::getType() 
{
	return (this->type);
}

void	Animal::setType( std::string type )
{
	this->type = type;
}
