#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm(const std::string name, const int gradeToSing, const int gradeToExecute);
		AForm( const AForm & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AFormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned( Bureaucrat& b );
		void setIsSigned( bool status );

		virtual void execute(Bureaucrat const & executor) const = 0;

	private:

		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;


};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif