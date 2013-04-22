#ifndef BALL_H
#define BALL_H

#include "Komponent.h"
#include "Image.h"

namespace Engine{

	class Ball: public Komponent{
	public:
		Ball(int x,int y, int w, int h, int xSpeed, int ySpeed, Image bild);
		void draw();
		void move();
		void handleCollision(Komponent*);
	private:
		int xVel, yVel;
	};

}

#endif
