#ifndef WARLCOK_HPP
# define WARLCOK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
	private:
		std::string	name;
		std::string	title;

		Warlock();
		Warlock( Warlock const & src );
		Warlock &operator=( Warlock const & src );
		std::map < std::string, ASpell * > _Spellbook;

	public:
		std::string const &getName() const;
		std::string	const &getTitle() const;
		void setTitle(std::string const &title);

		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		void introduce() const;

		void learnASpell(ASpell *aspell);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, ATarget const &atarget);

};

#endif
