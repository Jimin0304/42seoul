#include "ASpell.hpp"

ASpell::ASpell() {}
ASpell::ASpell( std::string name, std::string effects ): name(name), effects(effects) {}
ASpell::ASpell( ASpell const & src ): name(src.name), effects(src.effects) {}
ASpell & ASpell::operator=( ASpell const & rhs )
{
    name = rhs.name;
    effects = rhs.effects;
    return *this;
}
ASpell::~ASpell() {}

std::string ASpell::getName() const { return this->name; }
std::string ASpell::getEffects() const { return this->effects; }

void ASpell::launch( ATarget const & target ) const
{
    target.getHitBySpell(*this);
}