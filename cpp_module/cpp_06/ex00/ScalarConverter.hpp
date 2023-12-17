#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cctype>

class ScalarConverter
{

	public:

		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );

		static void convert(const std::string& input);

		class WrongType : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:

		ScalarConverter();

};

#endif