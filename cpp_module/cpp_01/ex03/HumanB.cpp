#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : weapon(NULL)
{
	this->name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (!this->weapon)
	{
		std::cout << "Weapon is null" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->weapon = &weapon;
}
