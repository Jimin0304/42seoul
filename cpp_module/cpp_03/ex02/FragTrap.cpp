#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout  << "FragTrap " << this->name << " destructor called" << std::endl;
}

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;

	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->hit_points = rhs.hit_points;
		this->energy_points = rhs.energy_points;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (this->hit_points == 0)
		std::cout << this->name << " is already dead.." << std::endl;
	else
		std::cout << "High Fives Guys!" << std::endl;
}