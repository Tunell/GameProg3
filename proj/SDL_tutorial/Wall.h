#ifndef WALL_H
#define WALL_H

#include <SDL.h>
#include "Komponent.h"
#include <string>
#include "GameEngine.h"

namespace Engine{

	class Wall: public Komponent{
	public:
		Wall(int x,int y, int w, int h, std::string p, bool o, GameEngine * gameengine);
		void draw();
		void handleCollision(Komponent*);
	private:
		GameEngine* gameengine;
		SDL_Surface* avatar;
	};

}

#endif
