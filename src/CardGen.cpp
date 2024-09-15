#include "CardGen.h"

// Canonical Orthodox Form
CardGen::CardGen() {
	std::cout << fBGRN "CardGen Default Constructor called" fCLR;
	std::cout << fBBLK " [ " << this << " ] " fCLR << std::endl;
}

CardGen::CardGen(const CardGen &src) {
	std::cout << fBGRN "CardGen Copy Constructor called" fCLR;
	std::cout << fBBLK " [ from " << &src << "to" << this << " ] " fCLR << std::endl;
}

CardGen &CardGen::operator=(const CardGen &rhs) {
	std::cout << fBGRN "CardGen Assignment Operator called" fCLR;
	std::cout << fBBLK " [ from " << &rhs << "to" << this << " ] " fCLR << std::endl;
	return *this;
}

CardGen::~CardGen() {
	std::cout << fBGRN "CardGen Destructor called" fCLR;
	std::cout << fBBLK " [ " << this << " ] " fCLR << std::endl;
}

// Methods
void CardGen::shellStart() {
	std::string kit;
	while (!std::cin.eof())
	{

	}
}
