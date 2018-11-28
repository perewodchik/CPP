#ifndef __Game__
#define __Game__

#include <iostream>
#include "Configuration.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"


static GameObject m_go;
static Player m_player;

class Game
{
public:
	Game() {}
	~Game() {}

	//simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, 
		int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	// a function to access the private running variable
	bool running() { return m_bRunning; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Point screen_center;
	SDL_Texture* m_pTexture;
	int m_currentFrame;
	bool m_bRunning;
};



#endif /* defined (__Game__) */