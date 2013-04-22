#include "Globals.h"
#include <iostream>

namespace Engine{
	Globals::Globals(){
		if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
			std::cerr << "Kan inte initera SDL!\n";
			exit(-1);}
		int screenWidth = 1024;
		int screenHeight = 640;
		screen = SDL_SetVideoMode(screenWidth,screenHeight,32,SDL_SWSURFACE|SDL_DOUBLEBUF);

		SDL_WM_SetCaption( "Hello World", NULL );
	}

	Globals::~Globals(){
		SDL_Quit();
	}

	Globals GE;

}

