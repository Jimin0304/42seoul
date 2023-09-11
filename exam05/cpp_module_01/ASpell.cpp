#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell( std::string const &name, std::string const &effects )
{
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell ( ASpell const & src ) { *this = src; }

ASpell::ASpell &operator=( ASpell const & src )
{
    this->name = src.name;
    this->effects = src.effects;
    return (*this);
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const;
std::string const &ASpell::getEffects() const;

void ASpell::launch(ATarget const &src) const;