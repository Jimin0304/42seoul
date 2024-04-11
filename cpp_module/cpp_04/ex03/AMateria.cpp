#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria( const AMateria & src ): _type(src.getType()) {}

AMateria::AMateria( std::string const & type ): _type(type) {}

AMateria::~AMateria()
{
}

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		_type = rhs.getType();
	}
	return *this;
}

std::string const & AMateria::getType() const { return _type; }

void AMateria::use(ICharacter& target) { (void)target; }