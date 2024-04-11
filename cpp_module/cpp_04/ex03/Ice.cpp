#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice( const Ice & src ) : AMateria(src) {}

Ice::~Ice() {}

Ice &				Ice::operator=( Ice const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

AMateria* Ice::clone() const
{
  	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}