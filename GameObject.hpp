#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <SDL2\SDL.h>
#include "Gfx.hpp"

class GameObject {
	
	public:
		GameObject();
		virtual ~GameObject();
	
		unsigned int Object_Id;
		
	private:
		Gfx * gfx;
	
		
};
	
#endif