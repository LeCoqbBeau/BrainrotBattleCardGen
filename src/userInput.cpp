//
// Created by mscheman on 9/14/24.
//

std::string userInput(const std::string &msg, bool(*check)(std::string)) {
	std::string	input;

	input = "";
	std::cout << BBLU << msg << BLU << std::endl;
	if (check == userInputBypass)
		std::getline(std::cin, input);
	while (check(input))
		std::getline(std::cin, input);
	std::cout << CLR;
	return (input);
}

bool userInputBypass(std::string str)
{
	return true;
}
