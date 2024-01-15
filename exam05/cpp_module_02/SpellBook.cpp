#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() 
{
    for (std::map<std::string, ASpell *>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); it++) {
        delete it->second;
    }
    _SpellBook.clear();
}
SpellBook::SpellBook( SpellBook const & src ) { *this = src; }
SpellBook & SpellBook::operator=( SpellBook const & rhs ) 
{
    _SpellBook = rhs._SpellBook;
    return *this;
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
    {
        if (_SpellBook.find(spell->getName()) == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
    }
}

void SpellBook::forgetSpell(std::string const &name)
{
    std::map<std::string, ASpell *>::iterator it = _SpellBook.find(name);
    if (it != _SpellBook.end()) {
        delete it->second;
        _SpellBook.erase(it);
    }
}

ASpell* SpellBook::createSpell(std::string const &name)
{
    ASpell *tmp = NULL;
    if (_SpellBook.find(name) != _SpellBook.end())
        tmp = _SpellBook[name];
    return tmp;
}