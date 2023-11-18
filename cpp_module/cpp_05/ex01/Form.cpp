#include "Form.hpp"

Form::Form(): name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form( const Form & src ): name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()) {}

Form::~Form() {}

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		isSigned = rhs.getIsSigned();
	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() 
{
	return "Grade is too High...\n";
}

const char* Form::GradeTooLowException::what() const throw() 
{
	return "Grade is too low...\n";
}

std::string Form::getName() const { return (name); }
bool		Form::getIsSigned() const { return (isSigned); }
int			Form::getGradeToSign() const { return (gradeToSign); }
int			Form::getGradeToExecute() const { return (gradeToExecute); }

void		Form::setIsSigned(bool status) { isSigned = status; }

void Form::beSigned( Bureaucrat& b )
{
	if (b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	setIsSigned(true);
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form name: " << i.getName() << std::endl
		<< "Grade to sign: " << i.getGradeToSign() << std::endl
		<< "Grade to execute: " << i.getGradeToExecute()  << std::endl
		<< "Is Signed: " << std::boolalpha << i.getIsSigned() << std::endl;
	return o;
}