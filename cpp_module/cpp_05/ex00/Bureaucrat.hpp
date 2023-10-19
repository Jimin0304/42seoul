#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{

	public:

		Bureaucrat (std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

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
		int getGrade() const;
		void increaseGrade();
		void decreaseGrade();

	private:

		const std::string name;
		int grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif