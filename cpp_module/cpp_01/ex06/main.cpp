#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong arguments..." << std::endl;
		exit(1);
	}

    Harl h;

	h.complain(argv[1]);
	
	return (0);
}