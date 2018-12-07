#include "Enemy.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Enemy::update()
{
	m_y += 1;
	if (m_x < SCREEN_WIDTH)
	{
	}
	else
	{
		m_x = SCREEN_WIDTH;
	}
	if (m_y < SCREEN_HEIGHT)
	{
	}
	else
	{
		m_y = 0;
	}
}