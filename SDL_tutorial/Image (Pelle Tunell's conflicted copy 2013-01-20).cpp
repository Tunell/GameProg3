#include "Image.h"
#include "Globals.h"
#include <string>
#include <SDL_image.h>
#include <iostream>

using namespace std;

namespace Engine{

	Image::Image(string fileName, bool opacity){
		const char * cstr = fileName.c_str();
		SDL_Surface* segBild = IMG_Load(cstr);
		bild = SDL_DisplayFormat( segBild );
		SDL_FreeSurface( segBild );
		if( opacity ){
			Uint32 transp = *( Uint32* )bild->pixels;
			SDL_SetColorKey( GE.screen,SDL_SRCCOLORKEY | SDL_RLEACCEL,transp );
		}
	}

	Image::Image( const Image& other ):bild( other.bild ){
		if( bild )
			bild->refcount++;
	}

	const Image& Image::operator=(const Image& other){
		if( bild!= other.bild ){
			if(bild && --bild->refcount == 0)
				delete bild;
			bild = other.bild;
			bild->refcount++;
			cout << "\n =" << bild->refcount;
		}
		return *this;
	}

	Image::~Image(){
		//if( bild && --bild->refcount == 0 )
			SDL_FreeSurface(bild);
	}

}