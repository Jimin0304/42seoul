#include "Intern.hpp"

int main() {
	try {
		std::cout << "\n-------------PresidentialPardonForm Test-------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Pardon");
		std::cout << rrf->getName() << std::endl;
		delete rrf;
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}

	try {
		std::cout << "\n-------------RobotomyRequestForm Test-------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Roboto");
		std::cout << rrf->getName() << std::endl;
		delete rrf;
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}

	try {
		std::cout << "\n-------------ShrubberyCreationForm Test-------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Shrubbery");
		std::cout << rrf->getName() << std::endl;
		delete rrf;
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}

	try {
		std::cout << "\n-------------No Such Name Test-------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("fail", "Bender");
		std::cout << rrf->getName() << std::endl;
		delete rrf;
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}
}
