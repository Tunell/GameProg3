#ifndef WALL_H
#define WALL_H

#include "Komponent.h"
#include "GameEngine.h"
#include "Image.h"

namespace Engine{

	class Wall: public Komponent{
	public:
		Wall(int x,int y, int w, int h, Image bild, GameEngine * gameengine);
		void draw();
		void handleCollision(Komponent*);
	private:
		GameEngine* gameengine;
	};

}

#endif
