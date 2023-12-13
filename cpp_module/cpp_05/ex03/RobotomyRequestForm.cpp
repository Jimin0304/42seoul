#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ): target(src.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->target = rhs.getTarget();
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const { return (target); }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		std::cout << "Whirrr...Buzzzz..." << std::endl;
		srand((unsigned int)time(NULL));
		if (rand() % 2 == 0)
			std::cout << getTarget() << " has been robotomized!" << std::endl;
		else
			std::cout << "fail to robotomize " << getTarget() << "..." << std::endl;
	}
}

