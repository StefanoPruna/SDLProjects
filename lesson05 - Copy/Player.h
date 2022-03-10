#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class Player : GameObject
{
public:
	Player(int m_pframes, const char* path, int m_pox_x, int m_pos_y);
	~Player();
	void draw();
	void update();
	void render();
	void handleEvents();
	void playerMove(Vector2D* m_vector);

private:
	int m_frames;
	const char* m_texture;
	int m_position_x;
	int m_position_y;
	char m_Flip;
	int m_angle;

	Vector2D* m_vector_right;
	Vector2D* m_vector_left;
	Vector2D* m_vector_up;
	Vector2D* m_vector_down;
	Vector2D* m_vector_init;
};
