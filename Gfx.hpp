#ifndef _GFX_HPP_
#define _GFX_HPP_

#include <SDL2\SDL.h>
#include <string>

class Gfx {
	public:
		Gfx(std::string tname, SDL_Rect src, SDL_Rect dest);
		~Gfx();
	
		void DrawImage();
		
		SDL_Rect Src;
		SDL_Rect Dest;
	
	private:
		std::string TextureName;
};

#endif