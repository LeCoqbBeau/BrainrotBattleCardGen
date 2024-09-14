#include "CardGen.h"

// Canonical Orthodox Form
CardGen::CardGen() {
	std::cout << BGRN "CardGen Default Constructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

CardGen::CardGen(const CardGen &src) {
	std::cout << BGRN "CardGen Copy Constructor called" CLR;
	std::cout << BBLK " [ from " << &src << "to" << this << " ] " CLR << std::endl;
}

CardGen &CardGen::operator=(const CardGen &rhs) {
	std::cout << BGRN "CardGen Assignment Operator called" CLR;
	std::cout << BBLK " [ from " << &rhs << "to" << this << " ] " CLR << std::endl;
	return *this;
}

CardGen::~CardGen() {
	std::cout << BGRN "CardGen Destructor called" CLR;
	std::cout << BBLK " [ " << this << " ] " CLR << std::endl;
}

// Methods
