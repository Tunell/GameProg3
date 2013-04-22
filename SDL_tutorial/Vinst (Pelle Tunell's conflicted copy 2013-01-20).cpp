#include "Vinst.h"
#include "Globals.h"
#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace Engine{
	
		Vinst::Vinst(int x,int y, int w, int h, Image bild, GameEngine * gameengine): Komponent(x,y,w,h,bild){
			xx = x;
			yy = y;
			this->gameengine=gameengine;
		}

		void Vinst::draw(){
			Rectangle r = getRect();
			SDL_BlitSurface(img->getSurface(),NULL, GE.screen,&r);
		}

		void Vinst::handleCollision(Komponent* other){
			vector<Komponent*> m_comps = gameengine->getComps();
			for( unsigned int i=0; i<m_comps.size(); i++ )
				if( m_comps[i] == other){
					cout << "viinst";
					xx = 100;
					yy = 100;
					moveRect();
					
					gameengine->remove(other);
				}
		}
}
