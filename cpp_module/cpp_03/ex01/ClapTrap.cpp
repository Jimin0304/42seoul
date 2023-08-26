#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout  << "ClapTrap " << this->name << " destructor called" << std::endl;
}

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->hit_points = rhs.hit_points;
		this->energy_points = rhs.energy_points;
		this->attack_damage = rhs.attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << this->name << " is already dead.." << std::endl;
		return ;
	}
	if (this->hit_points < amount)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
	std::cout << this->name << " takes " << amount << " damage..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
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
	this->hit_points += amount;
	this->energy_points -= 1;
	std::cout << this->name << " takes " << amount << " hit points!" << std::endl;
}
