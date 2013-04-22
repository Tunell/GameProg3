#include "Background.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Globals.h"
#include <string>

using namespace std;

namespace Engine{
	/*
		Background::Background(int x,int y, int w, int h, string p): Komponent(x,y,w,h){
			const char * cstr = p.c_str();
			xx = -5;
			yy = 45;
			xVel = 0;
			yVel = 0;
			bg = IMG_Load(cstr);
		}

		void Background::draw(){
			Rectangle r = getRect();
			SDL_BlitSurface(bg,NULL, GE.screen,&r);
		}

		void Player::keyDown(SDL_Event e){
			SDLKey keyPressed = e.key.keysym.sym;
			switch( keyPressed ){
				case SDLK_a: cout << "yeah buddy!"; break;
				case SDLK_UP: yVel -= 1; break;
				case SDLK_DOWN: yVel += 1; break;
				case SDLK_LEFT: xVel -= 1; break;
				case SDLK_RIGHT: xVel += 1; break;
				}
		}
		void Player::keyUp(SDL_Event e){
			SDLKey keyPressed = e.key.keysym.sym;
			switch( keyPressed ){
				case SDLK_a: cout << "yeah buddy!";break;
				case SDLK_c: xx=-5;yy=45;break;
				case SDLK_UP: yVel += 1;break;
				case SDLK_DOWN: yVel -= 1;break;
				case SDLK_LEFT: xVel += 1; break;
				case SDLK_RIGHT: xVel -= 1; break;
			}
		}

	
		void handleCollision(Komponent* k){
		Rectangle player = k->getRect();
		if ( player.overlaps(wall)){
			xx = -5;
			yy = 45;
			}
		}

		void Player::move(){
			xx+=xVel;
			//if sats som ser till att screen contains player( player är med på spelplanen )
			yy+=yVel;
			//if sats som ser till att screen contains player( player är med på spelplanen )
			moveRect();
		}
				

		//~Player(){}
		
		*/

}