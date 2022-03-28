#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(int m_pframes, const char* path, int m_pox_x, int m_pos_y)
{
	m_frames = m_pframes;
	m_texture = path;
	m_position_x = m_pox_x;
	m_position_y = m_pos_y;
	flip = 'N';

	m_vector_left = new Vector2D(-3, 0);
	m_vector_init = new Vector2D(5, -7);
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	GameObject::draw(m_frames, m_texture, m_position_x, m_position_y);
}

void Enemy::update()
{
	GameObject::update();
}

void Enemy::render()
{
	//Enemy face on the left
	GameObject::render(0, 'H');
}

void Enemy::enemyEvents()
{
	SDL_Event event;

	enemyMove(m_vector_left);
	
	update();

	enemyMove(m_vector_init);
	//Enemy turn left
	m_vector_init->setX(-1 * m_vector_init->getX());
}

void Enemy::enemyMove(Vector2D* m_EnemyVector)
{
	m_destinationRectangle.x += m_EnemyVector->getX();
	//cout << m_destinationRectangle.x;

	//enemyDestinationRectangle.x += m_EnemyVector->getX();
}

SDL_Rect Enemy::getPosEnemy()
{
	//return m_destinationRectangle;
	return enemyDestinationRectangle;
}
