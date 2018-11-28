#include "GameObject.h"
#include "string"
#include "Configuration.h"
#include <SDL.h>

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;

	m_currentRow = 1;
	m_currentFrame = 1;

	std::cout << "loaded object\n";
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawFrame("flash", m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void GameObject::update()
{
	if (m_x < SCREEN_WIDTH)
	{
		m_x += 3;
	}
	else
	{
		m_x = 0;
	}
	if (m_y < SCREEN_HEIGHT)
	{
		m_y += 2;
	}
	else
	{
		m_y = 0;
	}
	m_currentFrame = (m_currentFrame + 1) % 5;
}