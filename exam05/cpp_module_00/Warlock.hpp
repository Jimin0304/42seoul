#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock {
    private:
        Warlock();
        Warlock( Warlock const &src );
        Warlock & operator=(Warlock const & rhs);
        std::string name;
        std::string title;

    public:
        ~Warlock();
        Warlock(std::string const & name, std::string const & title);
        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
        void introduce() const;
};

#endif