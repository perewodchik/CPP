#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;

	m_currentRow = 0;
	m_currentFrame = 0;

	std::cout << "loaded object\n";
}

void GameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);

}

void GameObject::update()
{
	if (m_x < SCREEN_WIDTH)
	{
		m_x += 1;
	}
	else
	{
		m_x = 0;
	}
	if (m_y < SCREEN_HEIGHT)
	{
		m_y += 1;
	}
	else
	{
		m_y = 0;
	}
}