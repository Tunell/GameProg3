#ifndef Komponent_H
#define Komponent_H
#include "Rectangle.h"

namespace Engine{

	class Komponent{
	public:
		Komponent( int x, int y, int w, int h);
		virtual void keyDown(SDL_Event e);
		virtual void keyUp(SDL_Event e);
		virtual void handleCollision(Komponent*);
		virtual void move();
		void moveRect();
		virtual void draw();// = 0;
		virtual ~Komponent();
		const Rectangle& getRect() const;
	private:
		Rectangle rect;
	protected:
		int xx, yy;
	};

};

#endif