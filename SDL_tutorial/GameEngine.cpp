#include "GameEngine.h"
#include "Globals.h"
#include "Komponent.h"
#include <SDL.h>

#define FPS 2000

using namespace std;

namespace Engine{

	GameEngine::GameEngine(){}

	GameEngine::~GameEngine(void){}

	void GameEngine::add(Komponent* komp){
		comps.push_back(komp);
	}

	void GameEngine::remove(Komponent* komp){
		for( unsigned int i=0; i<comps.size(); i++ )
			if(comps[i]==komp)
				comps.erase(comps.begin() + i);
	}

	std::vector<Komponent*> GameEngine::getComps(){
		return comps;
	}

	void GameEngine::keyDown(SDL_Event e){
	}

	void GameEngine::keyUp(SDL_Event e){}
	
	void GameEngine::run(){
		const int tickInterval = 1000/FPS;
		Uint32 nextTick;
		int delay;
		bool quit = false;

		while (!quit) {			
			SDL_Event event;
			nextTick = SDL_GetTicks() + tickInterval;
			while( SDL_PollEvent( &event ) ){
				switch( event.type ){
				case SDL_QUIT:
					quit = true; break;
				case SDL_KEYDOWN:
						keyDown(event);break;
				case SDL_KEYUP:
						keyUp(event);
					break;
				}
			}
			SDL_FillRect(GE.screen,NULL,0X000000); 
			for( unsigned int i=0; i<comps.size(); i++ ){
				Komponent* other = comps[i];
				for( unsigned int x=0; x<comps.size(); x++ ){
					if(comps[x] != other){
						if( comps[x]->getRect().overlaps(other->getRect() ) )
							comps[x]->handleCollision(other);
					}
				}
				comps[i]->draw();
				comps[i]->move();
				//out of bounds
				//if(comps[i]->getRect().x<0-comps[i]->getRect().w || comps[i]->getRect().x>GE.screen->w+comps[i]->getRect().w ||comps[i]->getRect().y<0-comps[i]->getRect().h || comps[i]->getRect().y>GE.screen->h+comps[i]->getRect().h){
				//	comps.erase(comps.begin() + i);
				//}
			}
				delay = nextTick - SDL_GetTicks();
				if( delay > 0 )
					SDL_Delay( delay );
			SDL_Flip(GE.screen);
		}
	}
}