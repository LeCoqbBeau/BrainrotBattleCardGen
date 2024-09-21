//
// Created by mscheman on 9/14/24.
//

# include "CardGen.h"

std::string userInput(const std::string &msg, bool(*check)(const std::string &)) {
	std::string	input;

	input = "";
	std::cout << fBBLU << msg << fBLU;
	if (check == userInputBypass)
		std::getline(std::cin, input);
	while (check(input))
		std::getline(std::cin, input);
	std::cout << fCLR;
	return (input);
}

bool userInputBypass(const std::string& str)
{
	(void)str;
	return true;
}
