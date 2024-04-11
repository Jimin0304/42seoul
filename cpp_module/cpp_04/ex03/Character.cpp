#include "Character.hpp"

Character::Character(): _name("default")
{
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character( std::string const & name ): _name(name)
{
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character( const Character & src ): _name(src.getName())
{
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = src._inventory[i];
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		_name = rhs.getName();
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			_inventory[i] = rhs._inventory[i];
		}
	}
	return *this;
}

std::string const & Character::getName() const { return _name; }
		
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] != NULL)
    	_inventory[idx]->use(target);
}