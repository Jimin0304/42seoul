#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget( std::string type ): type(type) {}
ATarget::ATarget( ATarget const & src ): type(src.type) {}
ATarget & ATarget::operator=( ATarget const & rhs )
{
    this->type = rhs.type;
    return *this;
}
ATarget::~ATarget() {}

std::string const & ATarget::getType() const { return this->type; }

void ATarget::getHitBySpell( ASpell const & spell ) const
{
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}