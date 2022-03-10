#pragma once
class Vector2D
{
public:
	Vector2D();
	Vector2D(float x, float y);
	~Vector2D();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);

private:
	float m_x;
	float m_y;
};

