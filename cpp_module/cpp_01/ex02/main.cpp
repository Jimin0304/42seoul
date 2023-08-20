#include <iostream>

int	main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "==================================" << std::endl;
	std::cout << " the memory address of the string " << std::endl;
	std::cout << "==================================" << std::endl;
	std::cout << "string   : " << &str << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;
    
    std::cout << std::endl;

	std::cout << "===================================" << std::endl;
	std::cout << "      the value of the string      " << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << "string   : " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return (0);
}