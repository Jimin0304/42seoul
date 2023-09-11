#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
#include "ASpell.hpp"

class ATarget 
{
    private:
        std::string type;

    public:
        ATarget();
        ATarget( std::string const &type );
        ATarget( ATarget const & src );
        ATarget &operator=( ATarget const & src );
        ~ATarget();

        std::string const &getType() const;

        virtual ATarget *clone() const = 0;

        void getHitBySpell( ASpell const & src ) const;
};

#endif