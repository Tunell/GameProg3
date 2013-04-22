#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Komponent.h"
#include "Image.h"
#include <string>

namespace Engine{

	class Player: public Komponent{
	public:
		Player(int x,int y, int w, int h, Image bild, int p);
		void draw();
		//void keyDown(SDL_Event e);
		//void keyUp(SDL_Event e);
		void move();
		void handleCollision(Komponent*);
		int getPlayerNumber(){return playerNumber;}
		void setXVel(int ny){xVel=ny;}
		void setYVel(int nn){yVel=nn;} 
	private:
		int playerNumber;
		int xVel, yVel;
		//~Player();
	};

}

#endif
