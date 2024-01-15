#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
    private:
        Warlock();
        Warlock( Warlock const &src );
        Warlock & operator=(Warlock const & rhs);
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> SpellBook;

    public:
        ~Warlock();
         Warlock(std::string const & name, std::string const & title);
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget const & target);
};

#endif