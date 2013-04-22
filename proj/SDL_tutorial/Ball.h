#ifndef BALL_H
#define BALL_H

#include <SDL.h>
#include "Komponent.h"
#include <string>

namespace Engine{

	class Ball: public Komponent{
	public:
		Ball(int x,int y, int w, int h, int xSpeed, int ySpeed, std::string p, bool o);
		void draw();
		void move();
		void handleCollision(Komponent*);
		int xVel, yVel;
	private:
		SDL_Surface* avatar;
	};

}

#endif
