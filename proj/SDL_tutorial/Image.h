#ifndef IMAGE_H
#define IMAGE_H
#include <SDL.h>
#include <string>

namespace Engine{

	class Image{
	public:
		Image():bild(0){};
		Image(std::string fileName, bool opacity);
		Image(const Image& other);
		const Image& operator=(const Image& other);
		~Image();
		SDL_Surface* getSurface() const{return bild;};
	private:
		SDL_Surface* bild;
		bool opacity;
	};
};
#endif