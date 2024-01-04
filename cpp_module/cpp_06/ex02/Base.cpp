#include "Base.hpp"

Base::~Base() {}

Base * generate(void)
{
	std::srand(time(NULL));
	int index = std::rand() % 3;

	switch(index) {
		case 0:
			std::cout << "Generate A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generate B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Generate C" << std::endl;
			return (new C());
	}
	return NULL;
}

void identify(Base* p)
{
	if (p == NULL)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "Pointer A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer C" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference A" << std::endl;
	} catch(std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference B" << std::endl;
	} catch(std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference C" << std::endl;
	} catch(std::exception& e) {}
}