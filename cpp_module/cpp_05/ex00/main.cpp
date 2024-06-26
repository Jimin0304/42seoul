#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("test", 200);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    try
	{
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl << std::endl;

		a.increaseGrade();
		b.decreaseGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl << std::endl;

        b.increaseGrade();
        b.increaseGrade();	// exception
        std::cout << b << std::endl << std::endl;

		b.decreaseGrade();
		std::cout << b << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}