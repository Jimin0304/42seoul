/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:15:12 by jimpark           #+#    #+#             */
/*   Updated: 2023/08/07 22:39:49 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{

	public:

		Phonebook();
		~Phonebook();

		void	AddContact(void);
		void	PrintContacts(void);
		int		ft_stoi(std::string);
	
	private:

		Contact contacts[8];
		int		index;
		
};

#endif