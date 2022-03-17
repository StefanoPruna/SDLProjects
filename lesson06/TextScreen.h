#pragma once
#include "GameLoad.h"
#include <string>

using namespace std;

class TextScreen : GameLoad
{
public:
	TextScreen(int font_size, string font_path, int posX, int posY);
	~TextScreen();
	void draw();
	void update(string str);
	void render();
	void loadFont(const char* message_text);

private:
	int m_font_size;
	string my_text;
	int m_positionX;
	int m_positionY;
	TTF_Font* m_font;
	SDL_Surface* text_surface;
	SDL_Texture* text_texture;
	SDL_Color textColor;
	SDL_Rect m_textRectangle;
};

