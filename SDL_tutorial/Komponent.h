#ifndef Komponent_H
#define Komponent_H
#include "Rectangle.h"
#include "Image.h"

namespace Engine{

	class Komponent{
	public:
		virtual void handleCollision(Komponent*);
		virtual void move();
		void moveRect();
		virtual void draw()=0;
		virtual ~Komponent();
		const Rectangle& getRect() const;
	
	private:
		Rectangle rect;
	protected:
		Komponent( int x, int y, int w, int h, Image image);
		Image* img;
		int xx, yy;};

};

#endif