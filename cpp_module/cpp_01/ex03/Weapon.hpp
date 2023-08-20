#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{

	public:

		Weapon( std::string type );
		const 	std::string&	getType();
		void	setType( std::string type );
		~Weapon();


	private:

		std::string type;

};

#endif