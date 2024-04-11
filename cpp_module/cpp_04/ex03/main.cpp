#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// void leaks()
// {
//     system("leaks ex03");
// }

int main()
{
    // atexit(leaks);
    {
        std::cout << "----- Test 0 default test -----" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << std::endl << "--------- Test 1 ---------" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        AMateria* ice;
        AMateria* cure;
        ice = src->createMateria("ice");
        me->equip(ice);
        cure = src->createMateria("cure");
        me->equip(cure);
        tmp = src->createMateria("tmp");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);

        me->unequip(0);
        me->unequip(1);
        me->unequip(2);
        me->unequip(7);

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
        delete ice;
        delete cure;
    }

    return 0;
}