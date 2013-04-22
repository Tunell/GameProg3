#include "Player.h"
#include <SDL.h>
#include "Globals.h"
#include "Image.h"

using namespace std;

namespace Engine{
	
		Player::Player(int x,int y, int w, int h, Image bild,int p):
		Komponent(x,y,w,h,bild),xVel(0),yVel(0), playerNumber(p){
			xx = x;
			yy = y;
		}

		void Player::draw(){
			Rectangle r = getRect();
			SDL_BlitSurface(img->getSurface(),NULL, GE.screen,&r);
		}

		void Player::handleCollision(Komponent* other){
		}
		

		void Player::move(){
			
			if(getRect().x<0) 
				xx=0;
			if (getRect().x+(2*getRect().w)>GE.screen->w)
				xx=GE.screen->w-(2*getRect().w);
			if(getRect().y<0)
				yy=0;
			if( getRect().y+getRect().h+20>GE.screen->h)
				yy=GE.screen->h-getRect().h-20;
			xx+=xVel;
			yy+=yVel;
			moveRect();
		}
}
