#ifndef Rectangle_H
#define Rectangle_H
#include <SDL.h>

namespace Engine{

	struct Rectangle : public SDL_Rect{
		Rectangle();
		Rectangle( int xx, int yy, int ww, int hh);
		bool contains( int xx, int yy ) const;
		Rectangle centeredRect( int width, int height ) const;
		bool overlaps( const Rectangle& other ) const;
	};
};
#endif