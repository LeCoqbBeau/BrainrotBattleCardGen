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

	// Methods
	void shellStart();

private:
};

std::string userInput(const std::string &msg, bool(*check)(std::string));
bool userInputBypass(std::string str);

#endif //CARDGEN
