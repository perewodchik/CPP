#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		//init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 100, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	std::cout << "init success\n";
	m_bRunning = true; //everything inited successfully, start main loop
	if (!TextureManager::Instance()->load("assets/flash.png", "flash", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/pikachu.png", "pikachu", m_pRenderer))
	{
		return false;
	}
	
	m_player = new Player();
	m_enemy1 = new Enemy();
	m_enemy2 = new GameObject();

	m_player->load(200, 0, 100, 100, "flash");
	m_enemy1->load(50, 100, 100, 100, "flash");
	m_enemy2->load(100, 100, 100, 66, "pikachu");

	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_enemy1);
	m_gameObjects.push_back(m_enemy2);



	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); //clear to the draw color

	//loop through our objects and draw them
	for (std::vector< GameObject* >::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::draw()
{
	
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
		break;

		default:
		break;
		}
	}
}

void Game::update() 
{
	for (std::vector< GameObject* >::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

