#ifndef GAME_H
#define GAME_H
#include "GameEngine.h"
#include "Player.h"

namespace Engine{
	class Game: public GameEngine{
	public:
		Game();
		void keyDown(SDL_Event e);
		void keyUp(SDL_Event e);
		Player* p1;
		Player* p2;
	};
};
#endif