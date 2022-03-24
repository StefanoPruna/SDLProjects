#include "TextScreen.h"

TextScreen::TextScreen(int font_size, string font_path, int posX, int posY)
{
	m_font_size = font_size;
	my_text = font_path;
	m_positionX = posX;
	m_positionY = posY;
}

TextScreen::~TextScreen()
{
}

void TextScreen::draw()
{
	textColor = { 0, 0, 255, 255 };
	m_textRectangle.x = m_positionX;
	m_textRectangle.y = m_positionY;
}

void TextScreen::update(string str)
{
	loadFont(str.c_str());
	SDL_QueryTexture(text_texture, nullptr, nullptr, &m_textRectangle.w, &m_textRectangle.h);
}

void TextScreen::render()
{
	//SDL_SetRenderDrawColor(m_Renderer, 0, 255, 255, 255);
	//SDL_RenderClear(m_Renderer);//to clear the score screen 
	SDL_RenderCopy(m_Renderer, text_texture, nullptr, &m_textRectangle);
}

void TextScreen::loadFont(const char* message_text)
{
	m_font = TTF_OpenFont(my_text.c_str(), m_font_size);
	text_surface = TTF_RenderText_Solid(m_font, message_text, textColor);
	text_texture = SDL_CreateTextureFromSurface(m_Renderer, text_surface);
	SDL_FreeSurface(text_surface);
}