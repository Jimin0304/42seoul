#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern( const Intern & src ) { (void)src; }

Intern::~Intern() {}

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

AForm* Intern::makeForm( std::string name, std::string target )
{
	std::string formName[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	
	int i;
	for (i = 0; i < 3; i++)
	{
		if (name == formName[i])
			break ;
	}
	
	switch (i) {
		case 0:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(target));
		case 1:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			throw Intern::NoSuchFormName();
	}
}

const char* Intern::NoSuchFormName::what() const throw() 
{
	return "No such form name...\n";
}