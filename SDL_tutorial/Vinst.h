#ifndef VINST_H
#define VINST_H

#include "Komponent.h"
#include "GameEngine.h"
#include "Image.h"

namespace Engine{

	class Vinst: public Komponent{
	public:
		Vinst(int x,int y, int w, int h, Image bild, GameEngine * gameengine);
		void draw();
		void handleCollision(Komponent*);
	private:
		GameEngine* gameengine;
	};

}

#endif
