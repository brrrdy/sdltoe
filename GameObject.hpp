#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <SDL2\SDL.h>
#include "Gfx.hpp"

class GameObject {
	
	public:
		GameObject(unsigned int id, Gfx& gfx);
		virtual ~GameObject();
	
		unsigned int ObjectId;
		void Draw();
		
	private:
		Gfx& Graphics;
	
		
};
	
#endif