#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		Brain &		operator=( Brain const & rhs );

		std::string getIdea( int i ) const;
		void	setIdea( int i, std::string idea );

	private:

		std::string ideas[100];

};

#endif