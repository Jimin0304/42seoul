#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{

	public:
	
		Bureaucrat();
		Bureaucrat (const std::string name, int grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
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