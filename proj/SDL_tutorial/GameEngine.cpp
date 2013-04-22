#include "GameEngine.h"
#include "Globals.h"
#include "Game.h"
#include "Komponent.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

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

	void GameEngine::keyDown1(SDL_Event e){
	cout << "apa1";}

	void GameEngine::keyUp1(SDL_Event e){}
	
	void GameEngine::run(){
		const int tickInterval = 1000/FPS;
		Uint32 nextTick;
		int delay;
		/*SDL_Surface* inImage = SDL_LoadBMP( "hello.bmp" );
		SDL_Surface* image = NULL;
		if(inImage != NULL){
			image = SDL_DisplayFormat( inImage );
			SDL_FreeSurface( inImage );
		}
		else{
			std::cerr << "Kan inte skapa bilden!\n";
			exit(-1);
		}

		//SDL_Surface* bild1 = load_img( "project_properties.png" );

		Uint32 bgColor2 = SDL_MapRGB(GE.screen->format, 0, 255, 255);

		Uint32 transp = *(Uint32*)image->pixels;
		SDL_SetColorKey(image,SDL_SRCCOLORKEY|SDL_RLEACCEL, transp);
		*/
		//SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,
		//	SDL_DEFAULT_REPEAT_INTERVAL);

		bool quit = false;

		while (!quit) {			
			SDL_Event event;
			nextTick = SDL_GetTicks() + tickInterval;
			while( SDL_PollEvent( &event ) ){
				switch( event.type ){
				case SDL_QUIT:
					quit = true; break;
				case SDL_KEYDOWN:
						keyDown1(event);
					//for( unsigned int i=0; i<comps.size(); i++ )
						//comps[i]->keyDown(event);break;
					//case SDLK_ESCAPE: quit= true;break;
				case SDL_KEYUP:
						keyUp1(event);
					//for( unsigned int i=0; i<comps.size(); i++ )
						//comps[i]->keyUp(event);
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
				//if(intersects(comps[i]))
					//comps[i]->handleCollision();
				comps[i]->draw();
				comps[i]->move();
				//out of bounds grej
				if(comps[i]->getRect().x<0-comps[i]->getRect().w || comps[i]->getRect().x>GE.screen->w+comps[i]->getRect().w ||comps[i]->getRect().y<0-comps[i]->getRect().h || comps[i]->getRect().y>GE.screen->h+comps[i]->getRect().h){
					comps.erase(comps.begin() + i);
				}
			}
				delay = nextTick - SDL_GetTicks();
				if( delay > 0 )
					SDL_Delay( delay );
			SDL_Flip(GE.screen);
		}
	}
}