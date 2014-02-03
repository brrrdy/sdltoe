#ifndef _GFX_HPP_
#define _GFX_HPP_
	
#include <SDL2\SDL.h>
	
class Gfx {

	public:
		Gfx();
		~Gfx();
		
		void Set_Rect(int x, int y, int w, int h);
		bool Load_Surface(const unsigned int Tx_Id, const SDL_Rect* Src_Rect);
		bool Draw(SDL_Window* Window, const SDL_Rect* Dest_Rect);

	private:
		unsigned int Texture_Id;
		SDL_Rect Src_Rect;

};
			
#endif 