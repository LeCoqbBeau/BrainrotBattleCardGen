#ifndef CARDGEN_H
# define CARDGEN_H

# include <iostream>
# include <fstream>
# include <string>
# include <unistd.h>

# include "raylib.h"
# include "raymath.h"
# include "rlgl.h"

# include "colors.h"

# define WIDTH 800
# define HEIGHT 500

class CardGen
{
public:
	// Constructors
	CardGen();
	~CardGen();

	// Static

	// Methods
	void render(const std::string &kit);

private:
	Texture2D _card;
	Font _kitFont;
	Texture2D _statFont[14];
	void _prepare();
	void _drawStats(const std::string &kit);
	void _writeStats(const std::string &numptr, Vector2 pos, Color tint);
};

std::string userInput(const std::string &msg, bool(*check)(const std::string &));
bool userInputBypass(const std::string& str);

#endif //CARDGEN
