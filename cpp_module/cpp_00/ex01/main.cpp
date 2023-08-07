/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:55:20 by jimpark           #+#    #+#             */
/*   Updated: 2023/08/07 22:22:24 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	std::string command;
	Phonebook p;

	while (1)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			p.AddContact();
		}
		else if (command == "SEARCH")
		{
			p.PrintContacts();
		}
		else if (command == "EXIT")
		{
			std::cout << "bye bye !" << std::endl;
			break ;
		}
		else if (std::cin.eof()) {
			std::cout << "EOF entered ..." << std::endl;
			exit(1);
		}
		else
			std::cout << "Wrong command ..." << std::endl;
	}
	return (0);
}