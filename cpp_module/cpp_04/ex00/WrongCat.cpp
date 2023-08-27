#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meowwwww Meowwwwww~" << std::endl;
}