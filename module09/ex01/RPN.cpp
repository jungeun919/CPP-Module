/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:32 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 01:28:32 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& object)
{
	*this = object;
}

RPN::~RPN()
{
}

RPN&	RPN::operator=(const RPN& object)
{
	(void)object;
	return *this;
}

void	RPN::run(std::string input)
{
	std::stack<int> stack;
	int a;
	int b;
	int result;

	for (int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == ' ')
			continue ;
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%')
		{
			if (stack.size() < 2)
				throw ErrorException();
			
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();

			if (input[i] == '+')
				result = b + a;
			else if (input[i] == '-')
				result = b - a;
			else if (input[i] == '*')
				result = b * a;
			else if (input[i] == '/')
			{
				if (a == 0)
					throw DivisionByZeroException();
				result = b / a;
			}
			else if (input[i] == '%')
				result = b % a;
			
			stack.push(result);
		}
		else if (input[i] >= '0' && input[i] <= '9')
			stack.push(input[i] - '0');
		else
			throw ErrorException();
	}

	if (stack.size() != 1)
		throw ErrorException();
	std::cout << stack.top() << std::endl;
}

const char* RPN::ErrorException::what() const throw()
{
	return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Division By Zero";
}
