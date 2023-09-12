#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell( std::string const &name, std::string const &effects )
{
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell ( ASpell const & src ) { *this = src; }

ASpell &ASpell::operator=( ASpell const & src )
{
    this->name = src.name;
    this->effects = src.effects;
    return (*this);
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const { return(this->name); }
std::string const &ASpell::getEffects() const { return(this->effects); }

void ASpell::launch(ATarget const &src) const
{
    src.getHitBySpell(*this);
}