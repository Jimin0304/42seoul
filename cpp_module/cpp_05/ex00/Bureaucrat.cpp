#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) { *this = src; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		grade = rhs.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::increaseGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooHighException();
	grade++;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}