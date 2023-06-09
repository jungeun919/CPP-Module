/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:24:16 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/09 12:24:25 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	Base*	base;
	int		val;

	std::srand(std::time(NULL));
	val = std::rand() % 3;
	switch (val)
	{
		case 0:
			base = new A();
			std::cout << "generate A" << std::endl;
			break;
		case 1:
			base = new B();
			std::cout << "generate B" << std::endl;
			break;
		case 2:
			base = new C();
			std::cout << "generate C" << std::endl;
			break;
	}
	return base;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{	
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

// void	leaks(void) { system("leaks identify"); }

int	main()
{
	// atexit(leaks);

	Base*	base = generate();

	identify(base);
	identify(*base);

	delete base;

	return 0;
}
