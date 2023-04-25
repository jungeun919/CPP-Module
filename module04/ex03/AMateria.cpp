#include "AMateria.hpp"

// type 변수를 참조로 전달 (객체의 복사본이 아닌 원본 전달)
// 메모리와 시간 절약
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

// 반환값 (type) 변경 x
// 해당 객체의 모든 멤버 변수를 RDONLY
// 코드 수정 방지
std::string const & AMateria::getType() const
{
	return this->type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "this function will not be called" << std::endl;
}
