#include "Wall.h"
#include "Globals.h"
#include "Image.h"
#include "GameEngine.h"
#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace Engine{
	
		Wall::Wall(int x,int y, int w, int h, string p, bool o, GameEngine * gameengine): Komponent(x,y,w,h){
			Image image(p, o);
			avatar = image.getSurface();
			xx = x;
			yy = y;
			this->gameengine=gameengine;
		}

		void Wall::draw(){
			Rectangle r = getRect();
			SDL_BlitSurface(avatar,NULL, GE.screen,&r);
		}

		void Wall::handleCollision(Komponent* other){
			vector<Komponent*> m_comps = gameengine->getComps();
			for( unsigned int i=0; i<m_comps.size(); i++ )
				if( m_comps[i] == other)
					gameengine->remove(this);
			/*
			skriv något som gör att den försvinner.
			*/
		}
}
