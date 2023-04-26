#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl;

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	system("leaks a.out");

	return 0;
}
