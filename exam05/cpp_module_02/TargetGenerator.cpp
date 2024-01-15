#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::TargetGenerator( TargetGenerator const & src ) { *this = src; }
TargetGenerator & TargetGenerator::operator=( TargetGenerator const & rhs ) 
{
    _target = rhs._target;
    return *this;
}
TargetGenerator::~TargetGenerator()
{
    for (std::map<std::string, ATarget *>::iterator it = _target.begin(); it != _target.end(); it++) {
        delete it->second;
    }
    _target.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
    {
        if (_target.find(target->getType()) == _target.end())
            _target[target->getType()] = target->clone();
    }
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
    std::map<std::string, ATarget *>::iterator it = _target.find(type);
    if (it != _target.end())
    {
        delete it->second;
        _target.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(std::string const &type)
{
    ATarget *tmp = NULL;
    if (_target.find(type) != _target.end())
        tmp = _target[type];
    return tmp;
}