#include "Komponent.h"
#include "Globals.h"
#include <SDL.h>
#include <iostream>

namespace Engine{

	Komponent::Komponent( int x, int y, int w, int h):rect(x,y,w,h) {}

	Komponent::~Komponent(){}

	void Komponent::draw(){
		Uint32 red = SDL_MapRGB(GE.screen->format,255,0,0);
		SDL_FillRect(GE.screen,&rect,red);
	}

	void Komponent::keyDown(SDL_Event e){}

	void Komponent::keyUp(SDL_Event e){}
	
	void Komponent::move(){}
	
	void Komponent::handleCollision(Komponent* other){}

	void Komponent::moveRect(){
	rect.x = xx;
	rect.y = yy;
	}
	
	const Rectangle& Komponent::getRect() const{
		return rect;
	}
}