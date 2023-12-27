#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form( const Form & src );
		~Form();

		Form &		operator=( Form const & rhs );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned( Bureaucrat& b );
		void setIsSigned( bool status );

	private:

		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif