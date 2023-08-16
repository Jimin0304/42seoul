#include "Zombie.hpp"


Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie()
{
}

void	announce( void )
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}