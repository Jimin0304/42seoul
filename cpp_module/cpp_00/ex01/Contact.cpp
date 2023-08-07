/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:55:26 by jimpark           #+#    #+#             */
/*   Updated: 2023/08/08 02:42:05 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::checkEOF(void)
{
	if (std::cin.eof()) 
	{
		std::cout << "EOF entered ..." << std::endl;
		exit(1);
	}
}

int	Contact::checkASCII(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] < 32 || str[i] > 126)
			return (0);
	}
	return (1);
}

void	Contact::EnterInformation(void)
{
	while (1)
	{
		std::cout << "Enter the first name: ";
		std::getline(std::cin, this->firstName);
		Contact::checkEOF();
		if (this->firstName.empty())
			continue ;
		if (Contact::checkASCII(this->firstName))
			break ;
		else
			std::cout << "It contains an impossible character ..." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter the last name: ";
		std::getline(std::cin, this->lastName);
		Contact::checkEOF();
		if (this->lastName.empty())
			continue ;
		if (Contact::checkASCII(this->lastName))
			break ;
		else
			std::cout << "It contains an impossible character ..." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, this->nickName);
		Contact::checkEOF();
		if (this->nickName.empty())
			continue ;
		if (Contact::checkASCII(this->nickName))
			break ;
		else
			std::cout << "It contains an impossible character ..." << std::endl;
	}
	while (1)
	{
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, this->phoneNumber);
		Contact::checkEOF();
		if (!this->phoneNumber.empty())
			break ;
	}
	while (1)
	{
		std::cout << "Enter the darkest secret: ";
		std::getline(std::cin, this->darkestSecret);
		Contact::checkEOF();
		if (!this->darkestSecret.empty())
			break ;
	}
	std::cout << "Save the contact..." << std::endl;
}

std::string	Contact::changeLongInfo(std::string info)
{
	if (info.length() <= 10)
		return (info);
	else
		return (info.substr(0, 9) + ".");
}

void	Contact::printAllContact(void)
{
	std::cout << std::setw(10) << changeLongInfo(this->firstName) << "|";
	std::cout << std::setw(10) << changeLongInfo(this->lastName) << "|";
	std::cout << std::setw(10) << changeLongInfo(this->nickName) << std::endl;
}

void	Contact::printContact(void)
{
	std::cout << "This first name is " << this->firstName << std::endl;
	std::cout << "This last name is " << this->lastName << std::endl;
	std::cout << "This nickname is " << this->nickName << std::endl;
}