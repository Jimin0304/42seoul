#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

#include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high...\n";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low...\n";
				}
		};

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExcute() const;

		void beSigned(Bureaucrat &b);

	private:

		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExcute;


};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif