#include "Ball.h"
#include "Globals.h"
#include "Image.h"
#include "Wall.h"
#include "Player.h"
#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include <iostream>

using namespace std;

namespace Engine{
	
		Ball::Ball(int x,int y, int w, int h, int xSpeed, int ySpeed, string p, bool o): Komponent(x,y,w,h){
			Image image(p, o);
			avatar = image.getSurface();
			xx = x;
			yy = y;
			xVel = xSpeed;
			yVel = ySpeed;
		}

		void Ball::draw(){
			Rectangle r = getRect();
			SDL_BlitSurface(avatar,NULL, GE.screen,&r);
		}

		void Ball::handleCollision(Komponent* other){
			if(Wall* wallElement = dynamic_cast<Wall*>(other))
				xVel=-xVel;
			if(Player* playerElement = dynamic_cast<Player*>(other)){
				if(playerElement->playerNumber==1)
					if( xVel < 0 )
						xVel=-xVel;
				if(playerElement->playerNumber==2)
					if( xVel > 0 )
						xVel=-xVel;
			}
		}

		void Ball::move(){
			if(getRect().x<0 || getRect().x+getRect().w>GE.screen->w) 
				xVel=-xVel;
			if(getRect().y<0 || getRect().y+getRect().h>GE.screen->h)
				yVel=-yVel;
			xx+=xVel;
			yy+=yVel;
			moveRect();
		}
}
