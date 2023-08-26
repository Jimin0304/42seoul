#include "ScavTrap.hpp"

int main()
{
    ClapTrap c("Clap");
    ScavTrap s("Scav");

    c.attack("Scav");
    s.takeDamage(80);
    s.beRepaired(50);

    s.attack("Clap");
    c.beRepaired(3);
    c.takeDamage(10);
    c.beRepaired(1);

    s.guardGate();
}