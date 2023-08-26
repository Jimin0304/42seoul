#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("A");
    ClapTrap b("B");

    a.attack("B");
    b.takeDamage(8);
    b.beRepaired(5);

    b.attack("A");
    a.beRepaired(3);
    a.takeDamage(15);    // 죽음
    a.beRepaired(1);

    for (int i = 0; i < 8; i++) {
        b.beRepaired(1);
    } // energy point 다 씀
    b.attack("A");
}