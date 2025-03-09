#include "CardGen.h"

// Canonical Orthodox Form
CardGen::CardGen() {
	std::cout << fBGRN "CardGen Default Constructor called" fCLR;
	std::cout << fBBLK " [ " << this << " ] " fCLR << std::endl;
	InitWindow(WIDTH, HEIGHT, "CardGen");
	Image image = LoadImage("template/Template.png");
	this->_card = LoadTextureFromImage(image);
	UnloadImage(image);
	this->_kitFont = LoadFont("template/telegrama_render.otf");
	{
		std::string texturePath;
		for (int i = 0; i <= 9; ++i) {
			texturePath = "template/write/";
			texturePath.push_back(i + '0');
			texturePath += ".png";
			image = LoadImage(texturePath.c_str());
			_statFont[i] = LoadTextureFromImage(image);
			UnloadImage(image);
		}
	}
}

CardGen::~CardGen() {
	std::cout << fBGRN "CardGen Destructor called" fCLR;
	std::cout << fBBLK " [ " << this << " ] " fCLR << std::endl;
	for (auto it : _statFont) {
		UnloadTexture(it);
	}
	UnloadTexture(this->_card);
	UnloadFont(this->_kitFont);
	CloseWindow();
}

// Methods
void CardGen::render(const std::string &kit) {
	_prepare();
	// Loading
	std::string kitPath = "user/" + kit + ".png";
	Image kitImage = LoadImage(kitPath.c_str());
	{
		float resize = 280.0f / std::min((float)kitImage.width, (float)kitImage.height);
		ImageResize(&kitImage, resize * kitImage.width, resize * kitImage.height);
		Rectangle rectangle;
		rectangle.y = 0;
		rectangle.x = 0;
		if (kitImage.height > kitImage.width)
			rectangle.y = (kitImage.height - 280) / 2;
		else
			rectangle.x = (kitImage.width - 280) / 2;
		rectangle.width = 280;
		rectangle.height = 280;
		ImageCrop(&kitImage, rectangle);
	} // Resize et Crop
	Texture2D kitTexture = LoadTextureFromImage(kitImage);
	UnloadImage(kitImage);

	Vector2 kitNamePos = {static_cast<float>(WIDTH/2 - (kit.length() * 26.2)), 19};
	Color nameColor = {255, 76, 41, 255};

	//Draw
	BeginDrawing();
	DrawTextureV(kitTexture, (Vector2){35, 160}, WHITE);
	DrawTextEx(_kitFont, kit.c_str(), kitNamePos, 80, 0.0f, nameColor);
	EndDrawing();
	_drawStats(kit);
	std::string outputPath = "output/" + kit + ".png";
	std::string screenName = kit + ".png";
	TakeScreenshot(screenName.c_str());
	std::rename(screenName.c_str(), outputPath.c_str());
	//Unloading

	UnloadTexture(kitTexture);
}

void CardGen::_prepare() {
	Vector2 position = { (float)(WIDTH/2 - _card.width/2), (float)(HEIGHT/2 - _card.height/2) };
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawTextureV(_card, position, WHITE);
	EndDrawing();
}

#define HUE_MAX 180

static Color statToColor(double value, int step)
{
	double lowerBound;
	double upperBound;
	switch (step) {
		case 0: // PVS
			lowerBound = 1500;
			upperBound = 4500;
			break;
		case 1: // ATK
			lowerBound = 150;
			upperBound = 450;
			break;
		case 2: // DEF
			lowerBound = 150;
			upperBound = 450;
			break;
		case 3: // PWR
			lowerBound = 0;
			upperBound = 750;
			break;
		case 4: // RES
			lowerBound = 150;
			upperBound = 450;
			break;
		case 5: // SPD
			lowerBound = 70;
			upperBound = 200;
			break;
	}
	Color color;
	if (value == 0.0)
		return ColorFromHSV(0, 0, 0.7);
	if (lowerBound >= value)
		value = lowerBound;
	if (value > upperBound)
		value = upperBound;
	float hue = (value - lowerBound)/(upperBound - lowerBound);
	hue = Remap(hue, 0, 1, 0, HUE_MAX);
	color = ColorFromHSV(hue, 0.75, 1);
	return color;
}

void CardGen::_writeStats(const std::string &numptr, Vector2 pos, Color tint)
{
	Texture2D texture;

	for (char it : numptr)
	{
		if (it >= '0' && it <= '9')
			texture = _statFont[it - '0'];
		else
			continue;
		DrawTextureV(texture, pos, tint);
		pos.x += 33;
	}
}

void CardGen::_drawStats(const std::string &kit) {
	std::string statPath = "user/" + kit + ".stat";
	std::ifstream file(statPath);

	Image image = LoadImage("template/Stat.png");
	Texture2D texture;
	Color tint;
	float barLength;
	std::string numptr;
	Color statMainTint = {220, 220, 220, 255};
	Color statShadowTint = {23, 23, 23, 255};;

	double stat;
	for (int i = 0; i < 6; ++i) {
		std::getline(file, numptr);
		numptr = &numptr[5];
		stat = std::stod(numptr);
		stat = floor(stat);
		tint = statToColor(stat, i);
		barLength = ColorToHSV(tint).x;
		barLength = Remap(barLength, 0, HUE_MAX, 10, 358);
		barLength = round(barLength);
		texture = LoadTextureFromImage(image);

		BeginDrawing();
		for (int j = 0; j < barLength; ++j) {
			Vector3 tmpColor = ColorToHSV(tint);
			tmpColor.x += 0.125 * j;
			std::cout << j << ": " << tmpColor.x << std::endl;
			Color realTint = ColorFromHSV(tmpColor.x, tmpColor.y, tmpColor.z);
			DrawTexture(texture, 465 + j, 135 + i * 60, realTint);
		}
		for (int j = 0; j < 50; ++j) {
			_writeStats(numptr, (Vector2){500, (float)(115 + i * 60)}, statShadowTint);
			_writeStats(numptr, (Vector2){497, (float)(112 + i * 60)}, statMainTint);
		}
		EndDrawing();

		UnloadTexture(texture);
	}
	UnloadImage(image);
}
