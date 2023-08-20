#include "Zombie.hpp"

int main(void)
{
    Zombie stack = Zombie("stack");
	Zombie	*heap = newZombie("heap");

    stack.announce();
    heap->announce();
    randomChump("Chump");

	delete heap;

    // system("leaks zombie");
    return (0);
}