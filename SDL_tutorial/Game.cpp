#include "Game.h"
#include "Globals.h"
#include "Komponent.h"
#include "Wall.h"
#include "Ball.h"
#include "Image.h"
#include "Vinst.h"
#include <SDL.h>

using namespace std;
using namespace Engine;
namespace Engine{
	
	Game::Game(){
		Image* playerBild=new Image("player1.gif", true);
		Image* wallBild= new Image("Brick.jpg", false);
		p1 = new Player(101,300,30,40, *playerBild,1);
		add(p1);
		p2 = new Player(864,300,30,40, *playerBild,2);
		add(p2);
		Ball* b1 = new Ball(0,0,50,50,8,4,*playerBild);
		add(b1);
		Wall* w1 = new Wall(0,220,100,100,*wallBild,&*this);
		add(w1);
		Wall* w2 = new Wall(924,220,100,100,*wallBild,&*this);
		add(w2);
		Wall* w3 = new Wall(924,321,100,100,*wallBild,&*this);
		add(w3);
		Wall* w4 = new Wall(0,321,100,100,*wallBild,&*this);
		add(w4);
		Image* victory= new Image("Vinst.png", false);
		Vinst* vic = new Vinst(1200,321,100,100,*victory,&*this);
		add(vic);
		delete victory;
		delete playerBild;
		delete wallBild;

		run();
	
		SDL_Quit();
	}
	

	void Game::keyDown(SDL_Event e){
		SDLKey keyPressed = e.key.keysym.sym;
		switch( keyPressed ){
				case SDLK_UP: p1->setYVel(-1); break;
				case SDLK_DOWN: p1->setYVel(1); break;
				case SDLK_LEFT: p1->setXVel(-1); break;
				case SDLK_RIGHT: p1->setXVel(1); break;
				
				case SDLK_w: p2->setYVel(-1); break;
				case SDLK_s: p2->setYVel(1); break;
				case SDLK_a: p2->setXVel(-1); break;
				case SDLK_d: p2->setXVel(1); break;
			}
	}
	void Game::keyUp(SDL_Event e){
		SDLKey keyPressed = e.key.keysym.sym;
		switch( keyPressed ){
				case SDLK_UP: p1->setYVel(0); break;
				case SDLK_DOWN: p1->setYVel(0); break;
				case SDLK_LEFT: p1->setXVel(0); break;
				case SDLK_RIGHT: p1->setXVel(0); break;
				
				case SDLK_w: p2->setYVel(0); break;
				case SDLK_s: p2->setYVel(0); break;
				case SDLK_a: p2->setXVel(0); break;
				case SDLK_d: p2->setXVel(0); break;
		}
	}
}