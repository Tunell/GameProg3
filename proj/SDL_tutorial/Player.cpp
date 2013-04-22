#include "Player.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Globals.h"
#include "GameEngine.h"
#include "Image.h"
#include <string>
#include <iostream>

using namespace std;

namespace Engine{
	
		Player::Player(int x,int y, int w, int h, string p, bool o, int pn):
		Komponent(x,y,w,h),playerNumber(pn),xVel(0),yVel(0){
			Image image(p, o);
			avatar = image.getSurface();
			xx = x;
			yy = y;
		}

		void Player::draw(){
			Rectangle r = getRect();
			SDL_BlitSurface(avatar,NULL, GE.screen,&r);
		}

		/*
		void Player::keyDown(SDL_Event e){
			SDLKey keyPressed = e.key.keysym.sym;
			switch( keyPressed ){
					if(playerNumber == 1){
						case SDLK_UP: yVel -= 1; break;
						case SDLK_DOWN: yVel += 1; break;
						case SDLK_LEFT: xVel -= 1; break;
						case SDLK_RIGHT: xVel += 1; break;
					}
					if(playerNumber == 2){
						case SDLK_w: yVel -= 1; break;
						case SDLK_s: yVel += 1; break;
						case SDLK_a: xVel -= 1; break;
						case SDLK_d: xVel += 1; break;
					}
				}
		}
		void Player::keyUp(SDL_Event e){
			SDLKey keyPressed = e.key.keysym.sym;
			switch( keyPressed ){
				if(playerNumber == 1){
					case SDLK_c: xx=-5;yy=45;break;
					case SDLK_UP: yVel += 1;break;
					case SDLK_DOWN: yVel -= 1;break;
					case SDLK_LEFT: xVel += 1; break;
					case SDLK_RIGHT: xVel -= 1; break;
				}
				if(playerNumber == 2){
					case SDLK_x: xx=-5;yy=45;break;
					case SDLK_w: yVel += 1;break;
					case SDLK_s: yVel -= 1;break;
					case SDLK_a: xVel += 1; break;
					case SDLK_d: xVel -= 1; break;
				}
			}
		}
		*/
		
		void Player::handleCollision(Komponent* other){
			cout << "Player crash";
		}
		

		void Player::move(){
			cout << xVel;
			xx+=xVel;
			yy+=yVel;
			moveRect();
		}
				

		//~Player(){}

}
