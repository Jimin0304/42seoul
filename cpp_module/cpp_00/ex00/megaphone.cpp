/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:04:23 by jimpark           #+#    #+#             */
/*   Updated: 2023/08/08 02:25:14 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++) {
			str = argv[i];
			for (int j = 0; j < static_cast<int>(str.length()); j++)
				std::cout << static_cast<char>(std::toupper(str[j]));
		}
		std::cout << std::endl;
	}
	return (0);
}