#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>

namespace Engine{

	class Globals{
	public:
		Globals(void);
		~Globals(void);
		SDL_Surface* screen;
	};

	extern Globals GE;

} // namespace

#endif