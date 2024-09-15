//
// Created by mscheman on 9/14/24.
//

# include "CardGen.h"

std::string userInput(const std::string &msg, bool(*check)(std::string)) {
	std::string	input;

	input = "";
	std::cout << fBBLU << msg << fBLU << std::endl;
	if (check == userInputBypass)
		std::getline(std::cin, input);
	while (check(input))
		std::getline(std::cin, input);
	std::cout << fCLR;
	return (input);
}

bool userInputBypass(std::string str)
{
	(void)str;
	return true;
}
