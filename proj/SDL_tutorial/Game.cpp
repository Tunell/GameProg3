#include "Game.h"
#include "Globals.h"
#include "Komponent.h"
#include "Wall.h"
#include "Ball.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

namespace Engine{
	
	Game::Game(){
		GameEngine GameE;
			cout << "\nplayer";
		p1 = new Player(100,45,30,40, "player1.gif", true,1);
		GameE.add(p1);
			cout << "\nplayer2";
		p2 = new Player(500,45,30,40, "player1.gif", true,2);
		GameE.add(p2);
			cout << "\nBall";
		Ball* b1 = new Ball(0,0,50,50,8,4,"player1.gif", false);
		GameE.add(b1);
				cout << "\nWall";
		Wall* w1 = new Wall(100,100,50,50,"Brick.jpg", false,&GameE);
		GameE.add(w1);
		Wall* w2 = new Wall(400,100,50,50,"Brick.jpg", false,&GameE);
		GameE.add(w2);
		Wall* w3 = new Wall(100,400,50,50,"Brick.jpg", false,&GameE);
		GameE.add(w3);
		/*Komponent* k2 = new Komponent(0,100,50,100);
		GameE.add(k2);
		*/
		GameE.run();
	
		SDL_Quit();
	}

	void Game::keyDown1(SDL_Event e){
		cout << "woohoo";
		SDLKey keyPressed = e.key.keysym.sym;
		switch( keyPressed ){
				case SDLK_UP: p1->yVel -= 1; break;
				case SDLK_LEFT: p1->xVel -= 1; break;
				case SDLK_RIGHT: p1->xVel += 1; break;
				
				case SDLK_w: p2->yVel -= 1; break;
				case SDLK_s: p2->yVel += 1; break;
				case SDLK_a: p2->xVel -= 1; break;
				case SDLK_d: p2->xVel += 1; break;
			}
	}
	void Game::keyUp1(SDL_Event e){
		SDLKey keyPressed = e.key.keysym.sym;
		switch( keyPressed ){
			case SDLK_UP: p1->yVel += 1;break;
			case SDLK_DOWN: p1->yVel -= 1;break;
			case SDLK_LEFT: p1->xVel += 1; break;
			case SDLK_RIGHT: p1->xVel -= 1; break;
			
			case SDLK_w: p2->yVel += 1;break;
			case SDLK_s: p2->yVel -= 1;break;
			case SDLK_a: p2->xVel += 1; break;
			case SDLK_d: p2->xVel -= 1; break;
		}
	}
}