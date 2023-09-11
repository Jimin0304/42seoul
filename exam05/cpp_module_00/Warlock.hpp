#ifndef WARLCOK_HPP
# define WARLCOK_HPP

#include <iostream>

class Warlock
{
	private:
		std::string	name;
		std::string	title;

		Warlock();
		Warlock( Warlock const & src );
		Warlock &operator=( Warlock const & src );

	public:
		std::string const &getName() const;
		std::string	const &getTitle() const;
		void setTitle(std::string const &title);

		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		void introduce() const;

};

#endif
