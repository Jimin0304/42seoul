/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:15:06 by jimpark           #+#    #+#             */
/*   Updated: 2023/08/08 02:39:44 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() 
{
	this->index = 0;
}

Phonebook::~Phonebook() {}

void	Phonebook::AddContact(void)
{
	this->contacts[index % 8].EnterInformation();
	this->index++;
}

void	Phonebook::PrintContacts(void)
{
	std::string	index;
	int	num;

	if (this->index == 0)
		std::cout << "Your Phonebook is empty" << std::endl;
	else
	{
		std::cout << std::setw(10) << "index" << "|"
				<< std::setw(10) << "first name" << "|"
				<< std::setw(10) << "last name" << "|"
				<< std::setw(10) << "nickname"
		<< std::endl;

		for (int i = 0; i < this->index && i < 8 ; i++)
		{
			std::cout << std::setw(10) << i + 1 << "|";
			this->contacts[i].printAllContact();
		}
		
		std::cout << "Enter the number what you want: ";
		std::getline(std::cin, index);
		if (std::cin.eof()) 
		{
			std::cout << "EOF entered ..." << std::endl;
			exit(1);
		}
		if (index.length() > 1 || (index[0] != '1' && index[0] != '2' && index[0] != '3' && index[0] != '4' && index[0] != '5' && index[0] != '6' && index[0] != '7' && index[0] != '8'))
			std::cout << "Wrong index..." << std::endl;
		else
		{
			num = index[0] - 48;
			if (num <= this->index)
				this->contacts[num - 1].printContact();
			else
				std::cout << "Wrong index..." << std::endl;
		}
	}
}