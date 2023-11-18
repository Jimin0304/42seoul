#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
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
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (grade == 150)
		throw GradeTooHighException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade is too High...\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade is too low...\n";
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}