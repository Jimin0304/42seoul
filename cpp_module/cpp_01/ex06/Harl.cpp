#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << C_BLUE << "[ DEBUG ]" << C_NRML << std::endl
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< std::endl << "I just love it!" << std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << C_GREN << "[ INFO ]" << C_NRML << std::endl
		<< "I cannot believe adding extra bacon cost more money." << std::endl
		<< "You don’t put enough! If you did I would not have to ask for it!"
		<< std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout << C_YLLW << "[ WARNING ]" << C_NRML << std::endl
		<< "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming here for years and you just started working here last month."
		<< std::endl << std::endl;
}

void	Harl::error()
{
	std::cout << C_RED << "[ ERROR ]" << C_NRML << std::endl
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i;
	for (i = 0; i < 4; i++)
	{
		if (level == level_list[i])
			break ;
	}
	
	switch (i) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}