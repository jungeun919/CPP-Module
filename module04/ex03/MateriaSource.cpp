#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->memory[i] = NULL;
	// std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& object)
{
	for (int i = 0; i < 4; i++)
	{
		AMateria *temp = object.getMateria(i);
		if (temp)
			this->memory[i] = temp->clone();
		else
			this->memory[i] = NULL;
	}
	// std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->memory[i])
			delete this->memory[i];
	// std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& object)
{
	if (this != &object)
	{
		for (int i = 0; i < 4; i++)
		{
			AMateria *temp = object.getMateria(i);
			if (this->memory[i])
				delete this->memory[i];
			if (temp)
				this->memory[i] = temp->clone();
			else
				this->memory[i] = NULL;
		}
	}
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->memory[i] == NULL)
		{
			this->memory[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->memory[i] && this->memory[i]->getType() == type)
			return this->memory[i]->clone();
	return NULL;
}

AMateria *MateriaSource::getMateria(int idx) const
{
	return this->memory[idx];
}
