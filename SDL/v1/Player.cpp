#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
	std::cout << "Player texture is called " << m_textureID << "\n";
}

void Player::draw(SDL_Renderer* pRenderer)
{
	//GameObject::draw(pRenderer);
}

void Player::update()
{
	m_x -= 1;
}