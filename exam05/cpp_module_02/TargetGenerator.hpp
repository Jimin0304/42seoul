#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ATarget.hpp"

class TargetGenerator {
    private:
        TargetGenerator( TargetGenerator const & src );
        TargetGenerator & operator=( TargetGenerator const & rhs );
        std::map<std::string, ATarget *> _target;

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);
};