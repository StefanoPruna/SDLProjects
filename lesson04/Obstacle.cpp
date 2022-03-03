#include "Obstacle.h"

Obstacle::Obstacle(int m_pframes, const char* path, int m_pox_x, int m_pos_y)
{
	m_frames = m_pframes;
	m_texture = path;
	m_position_x = m_pox_x;
	m_position_y = m_pos_y;
}

Obstacle::~Obstacle()
{
}

void Obstacle::draw()
{
	GameObject::draw(m_frames, m_texture, m_position_x, m_position_y);
}

void Obstacle::update()
{
	GameObject::update();
}

void Obstacle::render()
{
	GameObject::render(0, 'N');
}
