#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell {
    protected:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell( std::string name, std::string effects );
        ASpell( ASpell const & src );
        ASpell & operator=( ASpell const & rhs );
        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;

        virtual ASpell *clone() const = 0;

        void launch( ATarget const & target ) const;
};