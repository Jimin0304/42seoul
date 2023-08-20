#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <sstream>

#define C_NRML "\033[0m"
#define C_RED  "\033[31m"
#define C_GREN "\033[32m"
#define C_YLLW "\033[33m"
#define C_BLUE "\033[34m"

class Harl
{

	public:

		Harl();
		~Harl();
		void complain( std::string level );

	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};

#endif