#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget( std::string const &type ) {this->type = type;}

ATarget::ATarget( ATarget const & src ) {*this = src;}

ATarget &ATarget::operator=( ATarget const & src )
{
    this->type = src.type;
    return (*this);
}
ATarget::~ATarget() {}

std::string const &ATarget::getType() const { return(this->type); }

void ATarget::getHitBySpell( ASpell const & src ) const
{
    std::cout << this->type << " has been " << src.getEffects << "!" << std::endl;
}