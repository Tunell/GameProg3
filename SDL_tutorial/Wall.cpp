#include "Wall.h"
#include "Globals.h"
#include "Image.h"
#include "GameEngine.h"
#include <SDL.h>
#include <vector>

using namespace std;

namespace Engine{
	
		Wall::Wall(int x,int y, int w, int h, Image bild, GameEngine * gameengine): Komponent(x,y,w,h,bild){
			xx = x;
			yy = y;
			this->gameengine=gameengine;
		}

		void Wall::draw(){
			Rectangle r = getRect();
			SDL_BlitSurface(img->getSurface(),NULL, GE.screen,&r);
		}

		void Wall::handleCollision(Komponent* other){
			vector<Komponent*> m_comps = gameengine->getComps();
			for( unsigned int i=0; i<m_comps.size(); i++ )
				if( m_comps[i] == other){
					xx= 1200;
					yy= 321;
					moveRect();
				}
		}
}
