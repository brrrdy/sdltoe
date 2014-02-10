#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <SDL2\SDL.h>
#include "Gfx.hpp"

class GameObject {
	
	public:
		GameObject(unsigned int id, Gfx& gfx);
		virtual ~GameObject();
	
		unsigned int ObjectId;
		virtual void Update();
		virtual void Draw(SDL_Renderer * RenderWindow);
		
	protected:
		Gfx& Graphics;
	
		
};
	
#endif