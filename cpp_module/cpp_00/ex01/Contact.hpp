/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:55:22 by jimpark           #+#    #+#             */
/*   Updated: 2023/08/07 22:39:46 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{

	public:
	
		void		EnterInformation(void);
		void		printAllContact(void);
		void		printContact(void);
		std::string	changeLongInfo(std::string);
		void		checkEOF(void);
		int			checkASCII(std::string);

	private:

		std::string firstName;
    	std::string lastName;
    	std::string nickName;
    	std::string phoneNumber;
    	std::string darkestSecret;
		
};

#endif