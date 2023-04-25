#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& object) : AMateria(object.type)
{
	// std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(void)
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice&	Ice::operator=(const Ice& object)
{
	if (this != &object)
		this->type = object.type;
	// std::cout << "Ice copy assignment operator called" << std::endl;
	return *this;
}

AMateria*	Ice::clone() const
{
	AMateria*	temp = new Ice();
	return temp;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
