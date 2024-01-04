#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <cctype>
# include <sstream>
# include <limits> 
# include <cstdlib>

class ScalarConverter
{

	public:

		static void convert(const std::string& input);

		class NotANumber : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );


};

#endif