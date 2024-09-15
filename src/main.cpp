//
// Created by mscheman on 8/16/24.
//

#include "CardGen.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;

	const int screenWidth = 800;
	const int screenHeight = 500;

	InitWindow(800, 500, "CardGen");

	Image card = LoadImage("template/Template.png");
	Texture2D texture = LoadTextureFromImage(card);
	Vector2 position = { (float)(screenWidth/2 - texture.width/2), (float)(screenHeight/2 - texture.height/2) };
	UnloadImage(card);

	Font font = LoadFont("template/telegrama_render.otf");

	Color nameColor = ColorFromHSV(197, 0.35, 1);

	std::string kitPath = argv[1];
	Vector2 kitNamePos = {static_cast<float>(800/2 - (kitPath.length() * 26.2)), 19};
	kitPath = "template/";
	kitPath += argv[1];
	kitPath += ".png";
	std::cout << kitNamePos.x << std::endl;
	Image kit = LoadImage(kitPath.c_str());
	ImageColorTint(&kit, RED);
	float resize;
	resize = 280.0f / std::min((float)kit.width, (float)kit.height);
	ImageResize(&kit, resize * kit.width, resize * kit.height);
	Rectangle rectangle;
	rectangle.y = 0;
	rectangle.x = 0;
	if (kit.height > kit.width)
		rectangle.y = (kit.height - 280) / 2;
	else
		rectangle.x = (kit.width - 280) / 2;
	rectangle.width = 280;
	rectangle.height = 280;
	ImageCrop(&kit, rectangle);
	Texture2D kitTexture = LoadTextureFromImage(kit);
	UnloadImage(kit);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTextureV(texture, position, WHITE);
		DrawTextureV(kitTexture, (Vector2){35, 160}, WHITE);
		DrawTextEx(font, argv[1], kitNamePos, 80, 0.0f, nameColor);
		EndDrawing();
	}

	UnloadFont(font);
	UnloadTexture(texture);
	CloseWindow();
}
