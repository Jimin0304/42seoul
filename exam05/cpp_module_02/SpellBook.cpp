#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	_Spellbook = src._Spellbook;
	return (*this);
}

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell* spell)
{
    if (spell)
        _Spellbook[spell->getName()] = spell;
}
void SpellBook::forgetSpell(std::string const &name)
{
    if (_Spellbook.find(name)!= _Spellbook.end())
        _Spellbook.erase(_Spellbook.find(name));
}
ASpell* SpellBook::createSpell(std::string const &name)
{
    ASpell *tmp = NULL;
    if (_Spellbook.find(name) != _Spellbook.end())
        tmp = _Spellbook[name];
    return (tmp);
}
