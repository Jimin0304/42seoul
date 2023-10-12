#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const & src)
{
	*this = src;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & src)
{
	_target = src._target;
	return (*this);
}


TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}


void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target)
        _target[target->getType()] = target;
}
void TargetGenerator::forgetTargetType(std::string const &type)
{
    if (_target.find(type) != _target.end())
        _target.erase(_target.find(type));
}
ATarget* TargetGenerator::createTarget(std::string const &type)
{
    ATarget *tmp;
    if (_target.find(type) != _target.end())
        tmp = _target[type];
    return (tmp);
}