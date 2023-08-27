#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src)
{
	brain = new Brain();
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		*this->brain = *rhs.brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Barkkkkk Barkkkkk!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (brain);
}