#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm* makeForm( std::string name, std::string target );

		class NoSuchFormName : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:

};

#endif