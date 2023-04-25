#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*memory[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& object);
		~MateriaSource(void);
		MateriaSource&	operator=(const MateriaSource& object);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		AMateria* getMateria(int idx) const;
};

#endif
