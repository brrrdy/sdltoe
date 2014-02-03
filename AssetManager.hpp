#ifndef _ASSETMANAGER_HPP_
#define _ASSETMANAGER_HPP_

#include <SDL2\SDL.h>

class AssetManager {
	public:
		AssetManager();
		~AssetManager();
		
		static SDL_Surface* Get_Texture(unsigned int Tx_Id);
		
	private:
		std::map<unsigned int, SDL_Surface*> Textures;
		
		
}
#endif