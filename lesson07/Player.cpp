#include "Player.h"
#include <iostream>

using namespace std;
#define GRAVITY 4

Player::Player(int m_pframes, const char* path, int m_pox_x, int m_pos_y)
{
	m_frames = m_pframes;
	m_texture = path;
	m_position_x = m_pox_x;
	m_position_y = m_pos_y;
	m_Flip = 'N';
	m_angle = 0;
	m_alarm = false;

	m_vector_right = new Vector2D(3, 0);
	m_vector_left = new Vector2D(-3, 0);
	m_vector_up = new Vector2D(0, -2);
	m_vector_down = new Vector2D(0, 2);
	m_vector_init = new Vector2D(5, -7);
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
				//m_Flip = 'N';//the dog starts to face on the left, so I put N, so when you click on the right, it faces right
				//m_angle = 0;
				//cout << "LEFT\n";
				update();
				break;
			case SDLK_RIGHT:
				playerMove(m_vector_right);
				/*m_Flip = 'H';
				m_angle = 0;
				cout << "RIGHT\n";*/
				update();
				break;
			case SDLK_UP:
				m_alarm = true;
				playerMove(m_vector_up);
				m_vector_init->setY(-20);//to make it jump
				//m_Flip = 'N';
				//m_angle = 90;
				//cout << "UP\n";
				update();
				break;
			case SDLK_DOWN:
				m_alarm = false;
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

	if (m_destinationRectangle.x == 170 && m_destinationRectangle.y == 30)
		cout << "You have reached your destination!\n";

	playerMove(m_vector_init);
	if (m_destinationRectangle.x < 0 + 80 && (m_vector_init->getX() < 0))//width for the left wall
	{
		m_vector_init->setX(-1 * m_vector_init->getX());
		//m_Flip = 'Y';
	}
	else if (m_destinationRectangle.x > 1280 - 80 - m_destinationRectangle.w && (m_vector_init->getX() > 0))//for the right wall
	{
		m_vector_init->setX(-1 * m_vector_init->getX());
		//m_Flip = 'H';
	}		
	else if (m_destinationRectangle.y < 0 && (m_vector_init->getY() < 0))
		m_vector_init->setY(-1 * m_vector_init->getY());
	else if (m_destinationRectangle.y > 940 + 6 - m_destinationRectangle.h && (m_vector_init->getY() > 0))//for the right wall, if the player is out of the screen
		m_vector_init->setY(-1 * m_vector_init->getY());

	if (m_vector_init->getX() < 0)
	{
		//the dog faces left and if I click on the right, then it turns the face on the right 
		//m_Flip = 'Y';
		m_Flip = 'N';
		m_angle = 0;
	}
	else
	{		
		//m_Flip = 'N';
		m_Flip = 'H';
		m_angle = 0;
	}

	m_vector_init->setY(m_vector_init->getY() + GRAVITY);
	/*if (m_destinationRectangle.y < 940 + 6 - m_destinationRectangle.h)
	{
		m_vector_init->setY(m_vector_init->getY() + GRAVITY);
		cout << m_vector_init->getY() + GRAVITY;
	}*/
	if ((m_destinationRectangle.y > 940 + 6 - m_destinationRectangle.h) &&
		abs(m_vector_init->getY() + GRAVITY) < 10)
		m_vector_init->setY(0);
}

void Player::playerMove(Vector2D* m_vector)
{
	m_destinationRectangle.x += m_vector->getX();
	m_destinationRectangle.y += m_vector->getY();
}

bool Player::alarm()
{
	return m_alarm;
}

SDL_Rect Player::getPosPlayer()
{
	return m_destinationRectangle;
}