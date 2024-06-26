#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & src );
		virtual ~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:

		std::string 	name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

};

#endif