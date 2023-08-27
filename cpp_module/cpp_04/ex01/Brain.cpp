#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		setIdea(i, "default");
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.getIdea(i);
	}
	return *this;
}

std::string Brain::getIdea( int i ) const
{
	if (i < 0 || i > 99)
		return ("out of range (0 ~ 99)");
	return (ideas[i]);
} 

void	Brain::setIdea( int i, std::string idea )
{
	ideas[i] = idea;
}