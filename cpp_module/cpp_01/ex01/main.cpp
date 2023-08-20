#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie_horde = zombieHorde(5, "jimpark");

    for (int i = 0; i < 5; i++)
    {
        zombie_horde[i].announce();
    }
    delete[] zombie_horde;

    // system("leaks zombieHorde");
    return (0);
}