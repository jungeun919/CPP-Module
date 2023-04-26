#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& object)
{
	this->type = object.type;
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& object)
{
	if (this != &object)
		this->type = object.type;
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "this function will not be called" << std::endl;
}
