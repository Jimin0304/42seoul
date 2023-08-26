#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
} 

ScavTrap::~ScavTrap()
{
	std::cout  << "ScavTrap " << this->name << " destructor called" << std::endl;
}

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;

	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->hit_points = rhs.hit_points;
		this->energy_points = rhs.energy_points;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hit_points == 0)
	{
		std::cout << this->name << " is already dead.." << std::endl;
		return ;
	}
	if (this->energy_points == 0)
	{
		std::cout << this->name << "'s energy point is empty..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}