#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(int m_pframes, const char* path, int m_pox_x, int m_pos_y)
{
	m_frames = m_pframes;
	m_texture = path;
	m_position_x = m_pox_x;
	m_position_y = m_pos_y;
	m_Flip = 'N';
	m_angle = 0;

	m_vector_right = new Vector2D(3, 0);
	m_vector_left = new Vector2D(-3, 0);
	m_vector_up = new Vector2D(0, -2);
	m_vector_down = new Vector2D(0, 2);
}

Player::~Player()
{
}

void Player::draw()
{
	GameObject::draw(m_frames, m_texture, m_position_x, m_position_y);
}

void Player::update()
{
	GameObject::update();
}

void Player::render()
{
	GameObject::render(m_angle, m_Flip);
}

void Player::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				playerMove(m_vector_left);
				m_Flip = 'N';
				m_angle = 0;
				cout << "LEFT\n";
				break;
			case SDLK_RIGHT:
				playerMove(m_vector_right);
				m_Flip = 'H';
				m_angle = 0;
				cout << "RIGHT\n";
				break;
			case SDLK_UP:
				playerMove(m_vector_up);
				m_Flip = 'N';
				m_angle = 90;
				cout << "UP\n";
				break;
			case SDLK_DOWN:
				playerMove(m_vector_down);
				m_Flip = 'N';
				m_angle = -90;
				cout << "DOWN\n";
				break;
			case SDLK_c:
				cout << "C\n";
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			cout << "MOUSE BUTTON DOWN\n";
			break;
		case SDL_MOUSEBUTTONUP:
			cout << "MOUSE BUTTON UP\n";
			break;
		default:
			break;
		}
	}

	if (m_destinationRectangle.x < 40 && m_destinationRectangle.y < 100)
		cout << "You have reached your destination!\n";

}

void Player::playerMove(Vector2D* m_vector)
{
	m_destinationRectangle.x += m_vector->getX();
	m_destinationRectangle.y += m_vector->getY();
}
