#ifndef GAME_H
#define GAME_H
#include "GameEngine.h"
#include "Player.h"


namespace Engine{
	class Game: public GameEngine{
	public:
		Game();
		void keyDown1(SDL_Event e);
		void keyUp1(SDL_Event e);
		Player* p1;
		Player* p2;
	//private:
	};
};
#endif