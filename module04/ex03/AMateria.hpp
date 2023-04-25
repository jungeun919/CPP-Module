#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string		type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& object);
		virtual ~AMateria(void);
		AMateria&	operator=(const AMateria& object);

		std::string const &	getType() const; // Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
