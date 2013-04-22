#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Komponent.h"
#include <string>

namespace Engine{

	class Player: public Komponent{
	public:
		Player(int x,int y, int w, int h, std::string p, bool o, int pn);
		void draw();
		//void keyDown(SDL_Event e);
		//void keyUp(SDL_Event e);
		void move();
		void handleCollision(Komponent*);
		int playerNumber;
		int xVel, yVel;
		//~Player();
	private:
		SDL_Surface* avatar;
	};

}

#endif
