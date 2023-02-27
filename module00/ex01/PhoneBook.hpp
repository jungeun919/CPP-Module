/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:55:52 by jungeun           #+#    #+#             */
/*   Updated: 2023/02/26 22:17:10 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook
{
	private:
		Contact	contact[8];
		int		index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void		add(void);
		std::string	getContactInfo(void);
		void		search(void);
		std::string	checkColumn(std::string column);
};

#endif
