/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:30:36 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/16 14:30:36 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {};
		MutantStack(const MutantStack& object) : std::stack<T>(object) {};
		~MutantStack(void) {};
		MutantStack&	operator=(const MutantStack& object) 
		{
			if (this != &object)
				std::stack<T>::operator=(object);
			return *this;
		};

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;

		iterator begin(void) { return this->c.begin(); };
		iterator end(void) { return this->c.end(); };
		iterator rbegin(void) { return this->c.rbegin(); };
		iterator rend(void) { return this->c.rend(); };
};

#endif
