#ifndef CARDGEN_H
# define CARDGEN_H

# include <iostream>
# include <string>
# include "colors.h"

# include "raylib.h"
# include "raymath.h"
# include "rlgl.h"

class CardGen
{
public:
	// Orthodox Canonical Form
	CardGen();
	CardGen(const CardGen &src);
	CardGen&operator=(const CardGen &rhs);
	~CardGen();

private:
};

#endif //CARDGEN
