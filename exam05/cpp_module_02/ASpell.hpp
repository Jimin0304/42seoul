#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
#include "ATarget.hpp"

class ASpell 
{
    protected:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell( std::string const &name, std::string const &effects );
        ASpell ( ASpell const & src );
        ASpell &operator=( ASpell const & src );
        virtual ~ASpell();

        std::string const &getName() const;
        std::string const &getEffects() const;

        virtual ASpell *clone() const = 0;

        void launch(ATarget const &src) const;

};

#endif