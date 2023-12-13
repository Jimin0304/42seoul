#include "AForm.hpp"

AForm::AForm(): name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm & src ): name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()) {}

AForm::~AForm() {}

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		isSigned = rhs.getIsSigned();
	}
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw() 
{
	return "Grade is too High...\n";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
	return "Grade is too low...\n";
}

const char* AForm::AFormNotSignedException::what() const throw()
{
	return "AForm is not signed...\n";
}

std::string AForm::getName() const { return (name); }
bool		AForm::getIsSigned() const { return (isSigned); }
int			AForm::getGradeToSign() const { return (gradeToSign); }
int			AForm::getGradeToExecute() const { return (gradeToExecute); }

void		AForm::setIsSigned(bool status) { isSigned = status; }

void AForm::beSigned( Bureaucrat& b )
{
	if (b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	setIsSigned(true);
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm name: " << i.getName() << std::endl
		<< "Grade to sign: " << i.getGradeToSign() << std::endl
		<< "Grade to execute: " << i.getGradeToExecute()  << std::endl
		<< "Is Signed: " << i.getIsSigned() << std::endl;
	return o;
}