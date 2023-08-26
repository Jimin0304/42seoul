#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );

		virtual void makeSound();
		std::string	getType();
		void	setType( std::string type );

	protected:

		std::string type;

};

#endif