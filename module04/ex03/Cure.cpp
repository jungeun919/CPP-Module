#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& object) : AMateria(object.type)
{
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
	// std::cout << "Cure destructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& object)
{
	if (this != &object)
		this->type = object.type;
	// std::cout << "Cure copy assignment operator called" << std::endl;
	return *this;
}

AMateria*	Cure::clone() const
{
	AMateria*	temp = new Cure();
	return temp;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
