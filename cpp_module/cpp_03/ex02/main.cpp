#include "FragTrap.hpp"

int main()
{
    ClapTrap c("Clap");
    FragTrap f("Frag");

    c.attack("Frag");
    f.takeDamage(20);
    f.beRepaired(10);

    f.attack("Clap");
    f.highFivesGuys();

}