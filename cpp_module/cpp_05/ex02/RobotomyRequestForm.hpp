#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void execute(Bureaucrat const & executor) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif