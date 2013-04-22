#ifndef GameEngine_H
#define GameEngine_H

#include <vector>
#include "Komponent.h"

namespace Engine{


	class GameEngine{
	public:
		GameEngine();
		void add(Komponent* komp);
		void remove(Komponent* komp);
		std::vector<Komponent*> getComps();
		void run();
		~GameEngine();
		virtual void keyDown1(SDL_Event e);
		virtual void keyUp1(SDL_Event e);
	private:
		std::vector<Komponent*> comps;
	protected:
	};
};
#endif