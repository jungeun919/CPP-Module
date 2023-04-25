#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const & name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	// std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& object)
{
	this->name = object.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (object.inventory[i])
			this->inventory[i] = object.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	// std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	// std::cout << "Character destructor called" << std::endl;
}

Character&	Character::operator=(const Character& object)
{
	if (this != &object)
	{
		this->name = object.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (object.inventory[i])
				this->inventory[i] = object.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	// std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

std::string const & Character::getName() const
{
	return this->name;
}

// AMateria 장착 / 해제
void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

// Materia 삭제하면 안됨
// 알아서 처리
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
