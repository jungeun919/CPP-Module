#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& object);
		~Cure(void);
		Cure&	operator=(const Cure& object);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
