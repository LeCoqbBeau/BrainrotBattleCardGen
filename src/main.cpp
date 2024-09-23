//
// Created by mscheman on 8/16/24.
//

#include "CardGen.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return 0;

	CardGen cardGen;

	for (int i = 1; i < argc; ++i) {
		try {
			cardGen.render(argv[i]);
		}
		catch (std::exception &e) {
			std::cout << fRED "Failed to created " << fBRED << argv[i] << fCLR << std::endl << e.what() << std::endl;
		}
		sleep(1);
	}

}
